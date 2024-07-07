add_subdirectory(App)
add_subdirectory(Data)
add_subdirectory(Gui)

install(FILES ${CMAKE_SOURCE_DIR}/README.md ${CMAKE_SOURCE_DIR}/LICENSE.md DESTINATION share/${CMAKE_PROJECT_NAME})
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION .)
