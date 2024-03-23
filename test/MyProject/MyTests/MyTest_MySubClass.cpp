#include "MyTest.h"

#include "MyProject/MySubLibrary/MySubClass.h"

TEST_F(MyTest, MySubClass_Constructors) {
    MySubClass obj1;
    MySubClass obj2(1, 2);
    EXPECT_EQ(obj1.getMyNumber(), 0);
    EXPECT_EQ(obj1.getMySubNumber(), 0);
    EXPECT_EQ(obj2.getMyNumber(), 1);
    EXPECT_EQ(obj2.getMySubNumber(), 2);
}

TEST_F(MyTest, MySubClass_CopyConstructor) {
    MySubClass obj1(3, 4);
    MySubClass obj2(obj1);
    EXPECT_EQ(obj1.getMyNumber(), obj2.getMyNumber());
    EXPECT_EQ(obj1.getMySubNumber(), obj2.getMySubNumber());
}

TEST_F(MyTest, MySubClass_MoveConstructor) {
    MySubClass obj1(5, 6);
    MySubClass obj2(std::move(obj1));
    EXPECT_EQ(obj2.getMyNumber(), 5);
    EXPECT_EQ(obj2.getMySubNumber(), 6);
}

TEST_F(MyTest, MySubClass_CopyAssignmentOperator) {
    MySubClass obj1(7, 8);
    MySubClass obj2(9, 10);
    obj2 = obj1;
    EXPECT_EQ(obj1.getMyNumber(), obj2.getMyNumber());
    EXPECT_EQ(obj1.getMySubNumber(), obj2.getMySubNumber());
}

TEST_F(MyTest, MySubClass_MoveAssignmentOperator) {
    MySubClass obj1(11, 12);
    MySubClass obj2(13, 14);
    obj2 = std::move(obj1);
    EXPECT_EQ(obj2.getMyNumber(), 11);
    EXPECT_EQ(obj2.getMySubNumber(), 12);
}

TEST_F(MyTest, MySubClass_GettersAndSetters) {
    MySubClass obj1;
    obj1.setMyNumber(15);
    obj1.setMySubNumber(16);
    EXPECT_EQ(obj1.getMyNumber(), 15);
    EXPECT_EQ(obj1.getMySubNumber(), 16);
}
