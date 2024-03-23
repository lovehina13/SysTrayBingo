find_package(GTest)

add_executable(MyTests MyTest.cpp MyTest_MyClass.cpp MyTest_MySubClass.cpp)

target_include_directories(MyTests PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(MyTests PUBLIC MyLibrary MySubLibrary GTest::gtest GTest::gtest_main)

gtest_discover_tests(MyTests)
