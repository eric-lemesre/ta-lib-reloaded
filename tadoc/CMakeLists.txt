
# définition theme in conf.py.in
# if(NOT DEFINED SPHINX_THEME)
#     set(SPHINX_THEME sphinx_rtd_theme)
# endif()

# if(NOT DEFINED SPHINX_THEME_DIR)
#     set(SPHINX_THEME_DIR)
# endif()

# configured documentation tools and intermediate build results
set(BINARY_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/docs/_build")

# Sphinx cache with pickled ReST documents
set(SPHINX_CACHE_DIR "${CMAKE_CURRENT_BINARY_DIR}/docs/_doctrees")

# HTML output directory
set(SPHINX_HTML_DIR "${CMAKE_CURRENT_BINARY_DIR}/docs/html")

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/conf.py.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/conf.py"
    @ONLY)

set(SPHINX_MASTER "index")

sphinx_add_docs(
  docs
  BUILDER html
  SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Doxygen

# look for Doxygen package
# find_package(Doxygen)

# if (DOXYGEN_FOUND)
#     # C sourcedir 
#     SET(TA_LIB_CSOURCE_DIR "${ta-lib_SOURCE_DIR}/ta-lib/c")
#     SET(DOXYGEN_HTML_DIR ${CMAKE_CURRENT_BINARY_DIR}/api)
#     SET(DOXYGEN_IGNORE_PREFIX "${ta-lib_SOURCE_DIR}/ta-lib/")

#     # set input and output files
#     set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/src/Doxyfile.in)
#     set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.out)

#     # request to configure the file
#     configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
#     message(STATUS "Build docs with Doxygen is enabled")

#      # Note: do not put "ALL" - this builds docs together with application EVERY TIME!
#     add_custom_target(docs
#         COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
#         COMMENT "Generating TA-Lib API documentation with Doxygen"
#         VERBATIM )
# else (DOXYGEN_FOUND)
#   message("Doxygen need to be installed to generate the doxygen documentation")
# endif (DOXYGEN_FOUND)

