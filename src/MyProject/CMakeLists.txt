add_subdirectory(MyExecutable)
add_subdirectory(MyInterface)
add_subdirectory(MyLibrary)
add_subdirectory(MySubLibrary)

install(FILES ${CMAKE_SOURCE_DIR}/README.md ${CMAKE_SOURCE_DIR}/LICENSE.md DESTINATION share/${CMAKE_PROJECT_NAME})
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION .)
