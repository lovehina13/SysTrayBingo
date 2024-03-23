add_library(MyLibrary SHARED MyClass.cpp)

target_include_directories(MyLibrary PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS MyLibrary EXPORT ${CMAKE_PROJECT_NAME}Targets DESTINATION lib)
# install(FILES ${CMAKE_SOURCE_DIR}/include/MyProject/MyLibrary/MyClass.h
#     DESTINATION include/MyProject/MyLibrary)
