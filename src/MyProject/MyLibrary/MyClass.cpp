#include "MyProject/MyLibrary/MyClass.h"

MyClass::MyClass(int myNumber) : _myNumber(myNumber) {}

int MyClass::getMyNumber() const { return _myNumber; }

void MyClass::setMyNumber(int myNumber) { _myNumber = myNumber; }
