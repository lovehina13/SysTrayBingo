add_library(MySubLibrary SHARED MySubClass.cpp)

target_include_directories(MySubLibrary PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(MySubLibrary PUBLIC MyLibrary)

install(TARGETS MySubLibrary EXPORT ${CMAKE_PROJECT_NAME}Targets DESTINATION lib)
# install(FILES ${CMAKE_SOURCE_DIR}/include/MyProject/MySubLibrary/MySubClass.h
#     DESTINATION include/MyProject/MySubLibrary)
