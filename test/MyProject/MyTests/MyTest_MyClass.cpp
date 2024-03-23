#include "MyTest.h"

#include "MyProject/MyLibrary/MyClass.h"

TEST_F(MyTest, MyClass_Constructors) {
    MyClass obj1;
    MyClass obj2(1);
    EXPECT_EQ(obj1.getMyNumber(), 0);
    EXPECT_EQ(obj2.getMyNumber(), 1);
}

TEST_F(MyTest, MyClass_CopyConstructor) {
    MyClass obj1(2);
    MyClass obj2(obj1);
    EXPECT_EQ(obj1.getMyNumber(), obj2.getMyNumber());
}

TEST_F(MyTest, MyClass_MoveConstructor) {
    MyClass obj1(3);
    MyClass obj2(std::move(obj1));
    EXPECT_EQ(obj2.getMyNumber(), 3);
}

TEST_F(MyTest, MyClass_CopyAssignmentOperator) {
    MyClass obj1(4);
    MyClass obj2(5);
    obj2 = obj1;
    EXPECT_EQ(obj1.getMyNumber(), obj2.getMyNumber());
}

TEST_F(MyTest, MyClass_MoveAssignmentOperator) {
    MyClass obj1(6);
    MyClass obj2(7);
    obj2 = std::move(obj1);
    EXPECT_EQ(obj2.getMyNumber(), 6);
}

TEST_F(MyTest, MyClass_GettersAndSetters) {
    MyClass obj1;
    obj1.setMyNumber(8);
    EXPECT_EQ(obj1.getMyNumber(), 8);
}
