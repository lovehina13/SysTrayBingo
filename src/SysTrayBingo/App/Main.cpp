#include "SysTrayBingo/Data/Bingo.h"
#include "SysTrayBingo/Data/Item.h"
#include "SysTrayBingo/Gui/BingoWidget.h"

#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    SysTrayBingo::Data::Bingo bingo;
    SysTrayBingo::Data::Bingo::Names counterNames = {"Counter #1", "Counter #2", "Counter #3"};
    SysTrayBingo::Data::Bingo::Names timerNames = {"Timer #1", "Timer #2", "Timer #3"};
    for (const auto& name : counterNames) {
        for (const auto& day : bingo.days()) {
            SysTrayBingo::Data::Item item(name, day, SysTrayBingo::Data::Item::Type::COUNTER, 0);
            bingo.setItem(name, day, item);
        }
    }
    for (const auto& name : timerNames) {
        for (const auto& day : bingo.days()) {
            SysTrayBingo::Data::Item item(name, day, SysTrayBingo::Data::Item::Type::TIMER, 0);
            bingo.setItem(name, day, item);
        }
    }

    SysTrayBingo::Gui::BingoWidget widget(bingo);
    widget.show();

    return app.exec();
}
