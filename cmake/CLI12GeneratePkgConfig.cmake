if(CLI12_PRECOMPILED)
  configure_file("cmake/CLI12precompiled.pc.in" "CLI12.pc" @ONLY)
else()
  configure_file("cmake/CLI12.pc.in" "CLI12.pc" @ONLY)
endif()

install(FILES "${PROJECT_BINARY_DIR}/CLI12.pc" DESTINATION "${CMAKE_INSTALL_DATADIR}/pkgconfig")
