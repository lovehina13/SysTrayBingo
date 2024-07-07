cmake_minimum_required(VERSION 3.25)

project(SysTrayBingo VERSION 1.0.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_subdirectory(src)

include(Documentation)
include(Package)
