#pragma once

#include "SysTrayBingo/Data/Item.h"

#include <list>
#include <map>

namespace SysTrayBingo {
namespace Data {

class Bingo {
  public:
    using Items = std::map<Item::Name, std::map<Item::Day, Item>>;
    using Names = std::list<Item::Name>;
    using Days = std::list<Item::Day>;

    Bingo();
    explicit Bingo(Items items);

    const Items& items() const;
    Names names() const;
    Names counterNames() const;
    Names timerNames() const;
    Days days() const;
    Item item(const Item::Name& name, Item::Day day) const;

    void setItem(const Item::Name& name, Item::Day day, const Item& item);

  private:
    Items _items;
};

} /* namespace Data */
} /* namespace SysTrayBingo */
