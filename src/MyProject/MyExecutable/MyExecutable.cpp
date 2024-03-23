#include "MyProject/MyLibrary/MyClass.h"
#include "MyProject/MySubLibrary/MySubClass.h"

#include <cstdlib>
#include <iostream>

int main() {
    MyClass obj1(1);
    MySubClass obj2(2, 3);
    std::cout << obj1.getMyNumber() << std::endl;
    std::cout << obj2.getMyNumber() << std::endl;
    std::cout << obj2.getMySubNumber() << std::endl;
    return EXIT_SUCCESS;
}
