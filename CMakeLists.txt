cmake_minimum_required(VERSION 3.25)

project(MyProject VERSION 1.0.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

add_subdirectory(src)
add_subdirectory(test)

include(Documentation)
include(Package)
