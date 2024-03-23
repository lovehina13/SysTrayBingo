#pragma once

#include "MyProject/MyInterface/IMyClass.h"

class MyClass : public IMyClass {
  public:
    MyClass() = default;
    virtual ~MyClass() = default;
    MyClass(const MyClass& other) = default;
    MyClass(MyClass&& other) noexcept = default;
    MyClass& operator=(const MyClass& other) = default;
    MyClass& operator=(MyClass&& other) noexcept = default;

    explicit MyClass(int myNumber);

    int getMyNumber() const;
    void setMyNumber(int myNumber);

  private:
    int _myNumber{0};
};
