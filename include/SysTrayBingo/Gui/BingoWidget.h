#pragma once

#include "SysTrayBingo/Data/Bingo.h"
#include "SysTrayBingo/Data/Item.h"

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtWidgets/QAction>
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

namespace SysTrayBingo {
namespace Gui {

class BingoWidget : public QWidget {
  public:
    explicit BingoWidget(Data::Bingo bingo, QWidget* parent = nullptr);

    const Data::Bingo& bingo() const;

  protected:
    void createActions();
    void createTable();
    void createIcon();
    void createCell(const Data::Item& item, int row, int column, bool active = false);

  protected slots:
    void actionTriggered(QAction* action);

  private:
    Data::Bingo _bingo;
    QTableWidget* _table;
    QSystemTrayIcon* _icon;
    QList<QAction*> _actions;
    QMap<QString, int> _names;
};

} /* namespace Gui */
} /* namespace SysTrayBingo */
