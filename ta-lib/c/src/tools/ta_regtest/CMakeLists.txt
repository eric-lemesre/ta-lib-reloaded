
SET(ta_regtest_SOURCE_DIR ${ta-lib_SOURCE_DIR}/ta-lib/c/src/tools/ta_regtest)

SET(EXECUTABLE_OUTPUT_PATH ${ta-lib_BINARY_DIR}/bin/ CACHE PATH "Build directory" FORCE)

SET(ta_regest_HEADERS 
    ${ta_regtest_SOURCE_DIR}/ta_error_number.h  
    ${ta_regtest_SOURCE_DIR}/ta_test_func.h  
    ${ta_regtest_SOURCE_DIR}/ta_test_priv.h
)

INCLUDE_DIRECTORIES(
    ${ta-lib_SOURCE_DIR}/ta-lib/c/include
    ${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_func
	${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_common/trio
	${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_common/mt
	${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_common
	${ta-lib_SOURCE_DIR}/ta-lib/c/src/ta_abstract
    ${ta_regtest_SOURCE_DIR}
)

SET(ta_regtest_CSOURSES
    ${ta_regtest_SOURCE_DIR}/ta_regtest.c
    ${ta_regtest_SOURCE_DIR}/test_data.c
    ${ta_regtest_SOURCE_DIR}/test_util.c
    ${ta_regtest_SOURCE_DIR}/test_abstract.c
#    ${ta_regtest_SOURCE_DIR}/ta_gDataClose.c
#    ${ta_regtest_SOURCE_DIR}/ta_gDataHigh.c
#    ${ta_regtest_SOURCE_DIR}/ta_gDataLow.c
#    ${ta_regtest_SOURCE_DIR}/ta_gDataOpen.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_adx.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_mom.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_sar.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_rsi.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_candlestick.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_per_ema.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_per_hlc.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_stoch.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_macd.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_minmax.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_per_hlcv.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_1in_1out.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_1in_2out.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_per_ohlc.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_stddev.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_bbands.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_ma.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_po.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_per_hl.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_trange.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_avgdev.c
    ${ta_regtest_SOURCE_DIR}/ta_test_func/test_imi.c
    ${ta_regtest_SOURCE_DIR}/test_internals.c  
)

add_executable(ta_regtest ${ta_regest_HEADERS} ${ta_regtest_CSOURSES})
target_link_libraries(ta_regtest 
    ta_lib_static
    -lm
)
