#include "SysTrayBingo/Gui/BingoWidget.h"

#include "SysTrayBingo/Gui/ItemAction.h"
#include "SysTrayBingo/Gui/ItemLabel.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QDate>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMenu>
#include <QtWidgets/QTableWidgetItem>

namespace SysTrayBingo {
namespace Gui {

BingoWidget::BingoWidget(Data::Bingo bingo, QWidget* parent)
    : QWidget(parent), _bingo(std::move(bingo)) {
    createActions();
    createTable();
    createIcon();
}

const Data::Bingo& BingoWidget::bingo() const { return _bingo; }

void BingoWidget::createActions() {
    Data::Bingo::Names counterNames = _bingo.counterNames();
    Data::Bingo::Names timerNames = _bingo.timerNames();

    _actions.clear();

    for (const auto& name : counterNames) {
        ItemAction* action = new ItemAction(name, Data::Item::Type::COUNTER);
        connect(action, &QAction::triggered, this, [=]() { actionTriggered(action); });
        _actions.push_back(action);
    }
    for (const auto& name : timerNames) {
        ItemAction* action = new ItemAction(name, Data::Item::Type::TIMER);
        connect(action, &QAction::triggered, this, [=]() { actionTriggered(action); });
        _actions.push_back(action);
    }
}

void BingoWidget::createTable() {
    Data::Bingo::Names names = _bingo.names();
    Data::Bingo::Days days = _bingo.days();

    QMap<Data::Item::Day, QString> daysText = {
        {Data::Item::Day::MONDAY, "Monday"},       {Data::Item::Day::TUESDAY, "Tuesday"},
        {Data::Item::Day::WEDNESDAY, "Wednesday"}, {Data::Item::Day::THURSDAY, "Thursday"},
        {Data::Item::Day::FRIDAY, "Friday"},       {Data::Item::Day::SATURDAY, "Saturday"},
        {Data::Item::Day::SUNDAY, "Sunday"}};

    _table = new QTableWidget;
    _table->setRowCount(static_cast<int>(names.size()));
    _table->setColumnCount(static_cast<int>(days.size()));

    int row = 0;
    for (const auto& name : names) {
        QTableWidgetItem* nameItem = new QTableWidgetItem(QString::fromStdString(name));
        _table->setVerticalHeaderItem(row, nameItem);
        _names[nameItem->text()] = row;
        int column = 0;
        for (const auto& day : days) {
            QTableWidgetItem* dayItem = new QTableWidgetItem(daysText.value(day));
            _table->setHorizontalHeaderItem(column, dayItem);
            Data::Item item = _bingo.item(name, day);
            createCell(item, row, column);
            ++column;
        }
        ++row;
    }

    QGridLayout* layout = new QGridLayout;
    layout->addWidget(_table);

    setLayout(layout);
    resize(800, 600);
}

void BingoWidget::createIcon() {
    QAction* minimizeAction = new QAction("Minimize");
    QAction* restoreAction = new QAction("Restore");
    QAction* quitAction = new QAction("Quit");
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);
    connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    QMenu* menu = new QMenu;
    for (const auto& action : _actions) {
        ItemAction* itemAction = static_cast<ItemAction*>(action);
        if (itemAction->type() == Data::Item::Type::COUNTER) {
            menu->addAction(itemAction);
        }
    }
    menu->addSeparator();
    for (const auto& action : _actions) {
        ItemAction* itemAction = static_cast<ItemAction*>(action);
        if (itemAction->type() == Data::Item::Type::TIMER) {
            menu->addAction(itemAction);
        }
    }
    menu->addSeparator();
    menu->addAction(minimizeAction);
    menu->addAction(restoreAction);
    menu->addAction(quitAction);

    QIcon icon(":/icons/iconAppointmentNew");
    _icon = new QSystemTrayIcon;
    _icon->setContextMenu(menu);
    _icon->setIcon(icon);
    _icon->show();

    setWindowIcon(icon);
}

void BingoWidget::createCell(const Data::Item& item, int row, int column, bool active) {
    ItemLabel* itemLabel = new ItemLabel(item, active);
    _table->setCellWidget(row, column, itemLabel);
}

void BingoWidget::actionTriggered(QAction* action) {
    ItemAction* itemAction = static_cast<ItemAction*>(action);

    Data::Item::Name name = itemAction->name();
    Data::Item::Day day = static_cast<Data::Item::Day>(QDate::currentDate().dayOfWeek() - 1);
    Data::Item item = _bingo.item(name, day);

    Data::Item::Value value = itemAction->value();
    Data::Item::Value valueOld = item.value();
    Data::Item::Value valueNew = valueOld + value;

    Data::Item::Type type = item.type();
    bool active = type == Data::Item::Type::TIMER && value == 0;

    item.setValue(valueNew);
    _bingo.setItem(name, day, item);

    int row = _names.value(QString::fromStdString(name));
    int column = static_cast<int>(day);
    createCell(item, row, column, active);
}

} /* namespace Gui */
} /* namespace SysTrayBingo */
