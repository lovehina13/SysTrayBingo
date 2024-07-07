#pragma once

#include "SysTrayBingo/Data/Item.h"

#include <QtCore/QTimer>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

namespace SysTrayBingo {
namespace Gui {

class ItemLabel : public QLabel {
  public:
    ItemLabel(Data::Item item, bool active, QWidget* parent = nullptr);

    const Data::Item& item() const;
    bool isActive() const;

  protected:
    void createLabel();

  protected slots:
    void updateLabel();

  private:
    Data::Item _item;
    bool _active{false};
    mutable QTimer _timer;
};

} /* namespace Gui */
} /* namespace SysTrayBingo */
