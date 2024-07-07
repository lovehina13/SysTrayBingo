#include "SysTrayBingo/Data/Item.h"

namespace SysTrayBingo {
namespace Data {

Item::Item() = default;

Item::Item(Name name, Day day, Type type, Value value)
    : _name(std::move(name)), _day(day), _type(type), _value(value) {}

const Item::Name& Item::name() const { return _name; }

Item::Day Item::day() const { return _day; }

Item::Type Item::type() const { return _type; }

Item::Value Item::value() const { return _value; }

void Item::setValue(Value value) { _value = value; }

} /* namespace Data */
} /* namespace SysTrayBingo */
