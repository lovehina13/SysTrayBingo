#pragma once

#include "MyProject/MyLibrary/MyClass.h"

class MySubClass : public MyClass {
  public:
    MySubClass() = default;
    virtual ~MySubClass() = default;
    MySubClass(const MySubClass& other) = default;
    MySubClass(MySubClass&& other) noexcept = default;
    MySubClass& operator=(const MySubClass& other) = default;
    MySubClass& operator=(MySubClass&& other) noexcept = default;

    MySubClass(int myNumber, int mySubNumber);

    int getMySubNumber() const;
    void setMySubNumber(int mySubNumber);

  private:
    int _mySubNumber{0};
};
