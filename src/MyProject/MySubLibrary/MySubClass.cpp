#include "MyProject/MySubLibrary/MySubClass.h"

MySubClass::MySubClass(int myNumber, int mySubNumber) : MyClass(myNumber), _mySubNumber(mySubNumber) {}

int MySubClass::getMySubNumber() const { return _mySubNumber; }

void MySubClass::setMySubNumber(int mySubNumber) { _mySubNumber = mySubNumber; }
