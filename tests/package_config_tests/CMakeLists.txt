# Copyright (c) 2017-2026, University of Cincinnati, developed by Henry Schreiner
# under NSF AWARD 1414736 and by the respective contributors.
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
cmake_minimum_required(VERSION 3.14...4.2)

project(CLI12-package-config-test)

include(CTest)

find_package(PkgConfig)

if(CLI12_DIR)
  set(CMAKE_PREFIX_PATH ${CLI12_DIR} ${CLI12_DIR}/lib)
endif()

message(STATUS "${CLI12_DIR}-- ${CMAKE_PREFIX_PATH}")
pkg_check_modules(CLI12 REQUIRED IMPORTED_TARGET CLI12)

# Test the target
add_executable(package-config-test ../../examples/positional_validation.cpp)
target_link_libraries(package-config-test PkgConfig::CLI12)

add_test(NAME package-config-test1 COMMAND package-config-test one)
set_property(TEST package-config-test1 PROPERTY PASS_REGULAR_EXPRESSION "File 1 = one")
