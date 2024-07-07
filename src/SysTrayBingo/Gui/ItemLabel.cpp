#include "SysTrayBingo/Gui/ItemLabel.h"

#include <QtCore/QString>
#include <QtCore/QTime>

namespace SysTrayBingo {
namespace Gui {

ItemLabel::ItemLabel(Data::Item item, bool active, QWidget* parent)
    : QLabel(parent), _item(item), _active(active) {
    createLabel();
}

const Data::Item& ItemLabel::item() const { return _item; }

bool ItemLabel::isActive() const { return _active; }

void ItemLabel::createLabel() {
    Data::Item::Type type = _item.type();
    Data::Item::Value value = _item.value();
    QString counter = QString::number(value);
    QString timer = QTime(0, 0, 0).addSecs(static_cast<int>(value)).toString();
    QString label = type == Data::Item::Type::COUNTER && value > 0              ? counter
                    : type == Data::Item::Type::TIMER && (value > 0 || _active) ? timer
                                                                                : QString();

    setText(label);
    setAlignment(Qt::AlignRight);

    if (type == Data::Item::Type::TIMER && _active) {
        connect(&_timer, &QTimer::timeout, this, &ItemLabel::updateLabel);
        _timer.start(1000);
    }
}

void ItemLabel::updateLabel() {
    Data::Item::Value value = _item.value() + 1;
    QString label = QTime(0, 0, 0).addSecs(static_cast<int>(value)).toString();

    _item.setValue(value);
    setText(label);
}

} /* namespace Gui */
} /* namespace SysTrayBingo */
