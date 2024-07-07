add_library(SysTrayBingoData SHARED Bingo.cpp Item.cpp)

target_include_directories(SysTrayBingoData PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS SysTrayBingoData EXPORT ${CMAKE_PROJECT_NAME}Targets DESTINATION lib)
