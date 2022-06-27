
SET(TA_LIB_SWIG_SOURCES_TOP_DIR ${ta-lib_SOURCE_DIR}/swig)
SET(TA_LIB_SWIG_BINARY_TOP_DIR ${ta-lib_BINARY_DIR}/swig)
SET(TA_LIB_SWIG_INTERFACE_DIR ${TA_LIB_SWIG_SOURCES_TOP_DIR}/swig/interface)
set(SWIG_SOURCE_FILE_EXTENSIONS ".i" ".swg")

IF(SWIG_perl5_FOUND)
    set_property(SOURCE ta_func.swg PROPERTY CPLUSPLUS OFF)
    set_property(SOURCE ta_libc.swg PROPERTY CPLUSPLUS OFF)
    set_property(SOURCE ta_libc_perl.swg PROPERTY CPLUSPLUS OFF)

    swig_add_library(TA LANGUAGE perl5
        OUTPUT_DIR ${TA_LIB_SWIG_BINARY_TOP_DIR}/lib/perl/Finance
        OUTFILE_DIR ${TA_LIB_SWIG_BINARY_TOP_DIR}/temp/perl
    #    INCLUDE_DIRECTORIES ${ta-lib_SOURCE_DIR}/c/include
    #	    ${ta-lib_SOURCE_DIR}/c/src/ta_abstract 
    #	    ${ta-lib_SOURCE_DIR}/c/src/ta_abstract/frames
    #	    ${ta-lib_SOURCE_DIR}/c/src/ta_common
    #	    ${ta-lib_SOURCE_DIR}/c/src/ta_func
        SOURCES ${TA_LIB_SWIG_INTERFACE_DIR}/ta_libc.swg
    )
endif(SWIG_perl5_FOUND)
