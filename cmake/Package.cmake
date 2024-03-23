include(CMakePackageConfigHelpers)

# <PackageName>Config.cmake

configure_package_config_file(
    ${CMAKE_MODULE_PATH}/PackageConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/${CMAKE_PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cmake/${CMAKE_PROJECT_NAME}Config.cmake
    DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})

# <PackageName>ConfigVersion.cmake

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    VERSION ${CMAKE_PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cmake/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})

# <PackageName>Targets.cmake

export(EXPORT ${CMAKE_PROJECT_NAME}Targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/cmake/${CMAKE_PROJECT_NAME}Targets.cmake)

install(EXPORT ${CMAKE_PROJECT_NAME}Targets
    FILE ${CMAKE_PROJECT_NAME}Targets.cmake
    NAMESPACE ${CMAKE_PROJECT_NAME}::
    DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})
