#pragma once

#include "SysTrayBingo/Data/Item.h"

#include <QtCore/QElapsedTimer>
#include <QtWidgets/QAction>

namespace SysTrayBingo {
namespace Gui {

class ItemAction : public QAction {
  public:
    ItemAction(Data::Item::Name name, Data::Item::Type type);

    const Data::Item::Name& name() const;
    Data::Item::Type type() const;
    Data::Item::Value value() const;

  private:
    Data::Item::Name _name;
    Data::Item::Type _type{Data::Item::Type::UNDEFINED};
    mutable QElapsedTimer _timer;
};

} /* namespace Gui */
} /* namespace SysTrayBingo */
