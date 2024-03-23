add_executable(MyExecutable MyExecutable.cpp)

target_include_directories(MyExecutable PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(MyExecutable PUBLIC MyLibrary MySubLibrary)

install(TARGETS MyExecutable EXPORT ${CMAKE_PROJECT_NAME}Targets DESTINATION bin)
