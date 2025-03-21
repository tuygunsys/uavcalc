cmake_minimum_required(VERSION 3.10)
project(uavcalc VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/uavcalc)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(HEADERS
    ${INCLUDE_DIR}/aerodynamics.h
)

set(SOURCES
    ${SOURCE_DIR}/aerodynamics.cpp
)

add_library(uavcalc STATIC ${SOURCES} ${HEADERS})

target_include_directories(uavcalc
PRIVATE
    ${INCLUDE_DIR}
)

set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_executable(uavcalc_test 
    ${TEST_DIR}/main.cpp
)

target_include_directories(uavcalc_test 
PRIVATE 
    ${INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/doctest/doctest
    ${SOURCE_DIR}
)

target_link_libraries(uavcalc_test uavcalc)

enable_testing()
add_test(NAME uavcalc_test COMMAND uavcalc_test)

target_include_directories(uavcalc PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set_target_properties(uavcalc PROPERTIES
    OUTPUT_NAME "uavcalc"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

install(TARGETS uavcalc
    EXPORT uavcalcTargets
    ARCHIVE DESTINATION lib
)

install(DIRECTORY ${INCLUDE_DIR} DESTINATION include)

install(EXPORT uavcalcTargets
    FILE uavcalcTargets.cmake
    NAMESPACE uavcalc::
    DESTINATION lib/cmake/uavcalc
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/uavcalcConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/uavcalcConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/uavcalcConfig.cmake
    @ONLY
)

install(FILES 
    "${CMAKE_CURRENT_BINARY_DIR}/uavcalcConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/uavcalcConfigVersion.cmake"
    DESTINATION lib/cmake/uavcalc
)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_PREFIX}/lib/cmake/uavcalc
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_INSTALL_PREFIX}/lib/libuavcalc.a
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_INSTALL_PREFIX}/include/uavcalc
    COMMAND ${CMAKE_COMMAND} -E echo "Uninstall complete."
)
