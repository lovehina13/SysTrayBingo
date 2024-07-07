#include "SysTrayBingo/Data/Bingo.h"

#include <set>

namespace SysTrayBingo {
namespace Data {

Bingo::Bingo() = default;

Bingo::Bingo(Items items) : _items(std::move(items)) {}

const Bingo::Items& Bingo::items() const { return _items; }

Bingo::Names Bingo::names() const {
    Names names;
    for (const auto& item : _items) {
        names.emplace_back(item.first);
    }
    return names;
}

Bingo::Names Bingo::counterNames() const {
    Names names;
    std::set<Item::Name> registered;
    for (const auto& item : _items) {
        for (const auto& item2 : item.second) {
            if (item2.second.type() == Data::Item::Type::COUNTER) {
                if (registered.count(item.first) == 0) {
                    names.emplace_back(item.first);
                    registered.insert(item.first);
                }
            }
        }
    }
    return names;
}

Bingo::Names Bingo::timerNames() const {
    Names names;
    std::set<Item::Name> registered;
    for (const auto& item : _items) {
        for (const auto& item2 : item.second) {
            if (item2.second.type() == Data::Item::Type::TIMER) {
                if (registered.count(item.first) == 0) {
                    names.emplace_back(item.first);
                    registered.insert(item.first);
                }
            }
        }
    }
    return names;
}

Bingo::Days Bingo::days() const {
    return {Item::Day::MONDAY, Item::Day::TUESDAY,  Item::Day::WEDNESDAY, Item::Day::THURSDAY,
            Item::Day::FRIDAY, Item::Day::SATURDAY, Item::Day::SUNDAY};
}

Item Bingo::item(const Item::Name& name, Item::Day day) const {
    return _items.count(name) > 0 && _items.at(name).count(day) > 0 ? _items.at(name).at(day)
                                                                    : Item();
}

void Bingo::setItem(const Item::Name& name, Item::Day day, const Item& item) {
    _items[name][day] = item;
}

} /* namespace Data */
} /* namespace SysTrayBingo */
