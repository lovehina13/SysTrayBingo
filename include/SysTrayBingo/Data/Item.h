#pragma once

#include <cstdint>
#include <string>

namespace SysTrayBingo {
namespace Data {

class Item {
  public:
    using Name = std::string;
    using Value = std::size_t;
    enum class Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY, UNDEFINED };
    enum class Type { COUNTER, TIMER, UNDEFINED };

    Item();
    Item(Name name, Day day, Type type, Value value);

    const Name& name() const;
    Day day() const;
    Type type() const;
    Value value() const;

    void setValue(Value value);

  private:
    Name _name;
    Day _day{Day::UNDEFINED};
    Type _type{Type::UNDEFINED};
    Value _value{0};
};

} /* namespace Data */
} /* namespace SysTrayBingo */
