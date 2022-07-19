
if(NOT DEFINED SPHINX_THEME)
    set(SPHINX_THEME default)
endif()

if(NOT DEFINED SPHINX_THEME_DIR)
    set(SPHINX_THEME_DIR)
endif()

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

set(SPHINX_MASTER "indicator")

sphinx_add_docs(
  ta-lib-doc
  BUILDER html
  SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)
