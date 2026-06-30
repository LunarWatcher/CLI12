# Copyright (c) 2017-2026, University of Cincinnati, developed by Henry Schreiner
# under NSF AWARD 1414736 and by the respective contributors.
# All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause

if(CLI12_PRECOMPILED)
  # Create static lib
  file(GLOB CLI12_precompile_sources "${PROJECT_SOURCE_DIR}/src/*.cpp")
  add_library(CLI12 STATIC ${CLI12_headers} ${CLI12_library_headers} ${CLI12_impl_headers}
                           ${CLI12_precompile_sources})
  target_compile_definitions(CLI12 PUBLIC -DCLI12_COMPILE)

  set(PUBLIC_OR_INTERFACE PUBLIC)
else()
  add_library(CLI12 INTERFACE)
  if(CMAKE_VERSION VERSION_GREATER 3.19)
    # This is only useful for visual studio and other IDE builds
    target_sources(CLI12 PRIVATE ${CLI12_headers} ${CLI12_library_headers} ${CLI12_impl_headers})

  endif()

  set(PUBLIC_OR_INTERFACE INTERFACE)
endif()

if(CLI12_ENABLE_EXTRA_VALIDATORS)
  target_compile_definitions(CLI12 ${PUBLIC_OR_INTERFACE} -DCLI12_ENABLE_EXTRA_VALIDATORS=1)
elseif(CLI12_DISABLE_EXTRA_VALIDATORS)
  target_compile_definitions(CLI12 ${PUBLIC_OR_INTERFACE} -DCLI12_DISABLE_EXTRA_VALIDATORS=1)
elseif(DEFINED CLI12_ENABLE_EXTRA_VALIDATORS)
  target_compile_definitions(CLI12 ${PUBLIC_OR_INTERFACE} -DCLI12_ENABLE_EXTRA_VALIDATORS=0)
endif()
# Allow IDE's to group targets into folders
add_library(CLI12::CLI12 ALIAS CLI12) # for add_subdirectory calls

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(SYSTEM_INCL "")
else()
  # If this project is included from somewhere else, we mark our headers as system headers to avoid
  # the compiler emitting any warnings about them
  set(SYSTEM_INCL "SYSTEM")
endif()

# Duplicated because CMake adds the current source dir if you don't.
target_include_directories(
  CLI12 ${SYSTEM_INCL} ${PUBLIC_OR_INTERFACE} $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

if(CMAKE_CXX_STANDARD LESS 14)
  target_compile_features(CLI12 INTERFACE cxx_std_11)
endif()

if(CLI12_INSTALL OR CLI12_FULL_INSTALL)

  # Make an export target
  install(TARGETS CLI12 EXPORT CLI12Targets)
  if((NOT CLI12_SINGLE_FILE) OR CLI12_FULL_INSTALL)
    install(FILES ${CLI12_headers} ${CLI12_library_headers}
            DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/CLI")
    if(NOT (CLI12_DISABLE_IMPL_HEADERS_INSTALL AND CLI12_PRECOMPILED))
      install(FILES ${CLI12_impl_headers} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/CLI/impl")
    endif()
  endif()
endif()
