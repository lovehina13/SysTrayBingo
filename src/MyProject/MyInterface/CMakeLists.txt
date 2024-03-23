add_library(MyInterface INTERFACE)

target_include_directories(MyInterface INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

# install(FILES ${CMAKE_SOURCE_DIR}/include/MyProject/MyInterface/IMyClass.h
#     DESTINATION include/MyProject/MyInterface)
