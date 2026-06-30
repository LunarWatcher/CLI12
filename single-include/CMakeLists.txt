# Copyright (c) 2017-2026, University of Cincinnati, developed by Henry Schreiner
# under NSF AWARD 1414736 and by the respective contributors.
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

if(CLI12_SINGLE_FILE)
  # Single file test
  find_package(
    Python
    COMPONENTS Interpreter
    REQUIRED)

  file(MAKE_DIRECTORY "${PROJECT_BINARY_DIR}/single-include")
  add_custom_command(
    OUTPUT "${PROJECT_BINARY_DIR}/single-include/CLI12.hpp"
    COMMAND
      Python::Interpreter "${PROJECT_SOURCE_DIR}/scripts/MakeSingleHeader.py" ${CLI12_headers}
      ${CLI12_impl_headers} --main "${CMAKE_CURRENT_SOURCE_DIR}/CLI12.hpp.in" --output
      "${PROJECT_BINARY_DIR}/single-include/CLI12.hpp" --version "${CLI12_VERSION}"
    DEPENDS "${PROJECT_SOURCE_DIR}/include/CLI/CLI.hpp" CLI12.hpp.in ${CLI12_headers}
            ${CLI12_impl_headers})
  add_custom_target(CLI12-generate-single-file ALL
                    DEPENDS "${PROJECT_BINARY_DIR}/single-include/CLI12.hpp")
  set_property(TARGET CLI12-generate-single-file PROPERTY FOLDER "Scripts")
  if(CLI12_INSTALL OR CLI12_FULL_INSTALL)
    install(FILES "${PROJECT_BINARY_DIR}/single-include/CLI12.hpp"
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
  endif()
  add_library(CLI12_SINGLE INTERFACE)
  target_link_libraries(CLI12_SINGLE INTERFACE CLI12)
  add_dependencies(CLI12_SINGLE CLI12-generate-single-file)
  target_compile_definitions(CLI12_SINGLE INTERFACE -DCLI12_SINGLE_FILE)
  target_include_directories(
    CLI12_SINGLE INTERFACE $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/single-include/>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
endif()
