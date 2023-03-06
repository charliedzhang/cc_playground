cmake_minimum_required(VERSION 3.13)
project(test_package)

set(CONAN_CMAKE_SILENT_OUTPUT TRUE)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS TARGETS)

find_package(cc_playground REQUIRED COMPONENTS cc_playground)

add_executable(test_package test_package.cpp)
target_link_libraries(test_package cc_playground::cc_playground)
