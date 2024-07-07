add_executable(SysTrayBingo Main.cpp)

target_include_directories(SysTrayBingo PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(SysTrayBingo PUBLIC SysTrayBingoData SysTrayBingoGui Qt5::Widgets)

install(TARGETS SysTrayBingo EXPORT ${CMAKE_PROJECT_NAME}Targets DESTINATION bin)
