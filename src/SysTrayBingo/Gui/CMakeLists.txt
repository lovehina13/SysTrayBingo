add_library(SysTrayBingoGui SHARED BingoWidget.cpp ItemAction.cpp ItemLabel.cpp
    ${PROJECT_SOURCE_DIR}/ui/Resources.qrc)

target_include_directories(SysTrayBingoGui PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(SysTrayBingoGui PUBLIC SysTrayBingoData Qt5::Core Qt5::Widgets)

install(TARGETS SysTrayBingoGui EXPORT ${CMAKE_PROJECT_NAME}Targets DESTINATION lib)
