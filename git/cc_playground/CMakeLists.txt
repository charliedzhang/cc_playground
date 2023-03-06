cmake_minimum_required(VERSION 3.22)
project(cc_playground)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
enable_testing()

set(CMAKE_CXX_STANDARD 17)
message(STATUS "CXX version: ${CMAKE_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(GTest REQUIRED)
find_package(SystemCLanguage REQUIRED)
add_compile_options(-fdiagnostics-color)

add_compile_options(-Werror -Wall -Wextra -Wvla -Wno-unused-parameter)

add_subdirectory(src)
add_subdirectory(test)

add_custom_target(ctest
    COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process -T test --no-compress-output
    USES_TERMINAL)
message(STATUS "Install directory: ${CMAKE_INSTALL_INCLUDEDIR}")

install(TARGETS cc_playground TYPE LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
#install(DIRECTORY include/cc_playground DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
