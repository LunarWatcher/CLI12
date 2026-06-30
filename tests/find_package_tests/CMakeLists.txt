# Copyright (c) 2017-2026, University of Cincinnati, developed by Henry Schreiner
# under NSF AWARD 1414736 and by the respective contributors.
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.14...4.2)

project(CLI12-find-package-test)

include(CTest)

if(CLI12_DIR)
  set(CMAKE_PREFIX_PATH ${CLI12_DIR})
endif()

# Test the CLI12 CMake package config
find_package(CLI12 2.0 REQUIRED)

# Test the target
add_executable(package-test ../../examples/positional_validation.cpp)
target_link_libraries(package-test CLI12::CLI12)

add_test(NAME package-test1 COMMAND package-test one)
set_property(TEST package-test1 PROPERTY PASS_REGULAR_EXPRESSION "File 1 = one")
