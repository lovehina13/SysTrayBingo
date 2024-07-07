#include "SysTrayBingo/Gui/ItemAction.h"

#include <QtCore/QString>

namespace SysTrayBingo {
namespace Gui {

ItemAction::ItemAction(Data::Item::Name name, Data::Item::Type type)
    : QAction(QString::fromStdString(name)), _name(std::move(name)), _type(type) {}

const Data::Item::Name& ItemAction::name() const { return _name; }

Data::Item::Type ItemAction::type() const { return _type; }

Data::Item::Value ItemAction::value() const {
    Data::Item::Value value = 0;

    if (_type == Data::Item::Type::COUNTER) {
        value = 1;
    } else if (_type == Data::Item::Type::TIMER) {
        if (!_timer.isValid()) {
            _timer.start();
        } else {
            value = static_cast<Data::Item::Value>(_timer.elapsed() / 1000);
            _timer.invalidate();
        }
    }

    return value;
}

} /* namespace Gui */
} /* namespace SysTrayBingo */
