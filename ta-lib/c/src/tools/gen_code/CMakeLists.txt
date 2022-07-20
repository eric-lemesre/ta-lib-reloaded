
SET(gen_code_SOURCE_DIR ${ta-lib_SOURCE_DIR}/ta-lib/c/src/tools/gen_code)

SET(EXECUTABLE_OUTPUT_PATH ${ta-lib_BINARY_DIR}/bin/ CACHE PATH "Build directory" FORCE)

INCLUDE_DIRECTORIES(
    ${ta-lib_SOURCE_DIR}/ta-lib/c/include
    ${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_func
#	${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_common/trio
#	${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_common/mt
	${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_common
	${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_abstract
#    ${ta_regtest_SOURCE_DIR}
)

add_executable(gen_code gen_code.c)
target_link_libraries(gen_code
    ta_lib_static
    -lm
)