# Do not modify this file. It is automatically
# generated by make_pro.pl

TEMPLATE  = lib
CONFIG   -= qt
CONFIG   += staticlib

# Identify the temp dir
cmd:OBJECTS_DIR = ../../../../../temp/cmd
cmr:OBJECTS_DIR = ../../../../../temp/cmr
csd:OBJECTS_DIR = ../../../../../temp/csd
csr:OBJECTS_DIR = ../../../../../temp/csr

# Identify the target
LIBTARGET = ta_func
cmd:TARGET = ta_func_cmd
cmr:TARGET = ta_func_cmr
csd:TARGET = ta_func_csd
csr:TARGET = ta_func_csr

# Output info
DESTDIR     = ../../../../../lib

# Files to process
SOURCES	= ../../../../../src/ta_func/ta_utility.c \ 
          ../../../../../src/ta_func/ta_MAX.c \ 
          ../../../../../src/ta_func/ta_MIN.c \ 
          ../../../../../src/ta_func/ta_BBANDS.c \ 
          ../../../../../src/ta_func/ta_DEMA.c \ 
          ../../../../../src/ta_func/ta_EMA.c \ 
          ../../../../../src/ta_func/ta_HT_TRENDLINE.c \ 
          ../../../../../src/ta_func/ta_KAMA.c \ 
          ../../../../../src/ta_func/ta_MA.c \ 
          ../../../../../src/ta_func/ta_MAMA.c \ 
          ../../../../../src/ta_func/ta_MIDPRICE.c \ 
          ../../../../../src/ta_func/ta_MIDPOINT.c \ 
          ../../../../../src/ta_func/ta_SAR.c \ 
          ../../../../../src/ta_func/ta_SAREXT.c \ 
          ../../../../../src/ta_func/ta_SMA.c \ 
          ../../../../../src/ta_func/ta_T3.c \ 
          ../../../../../src/ta_func/ta_TEMA.c \ 
          ../../../../../src/ta_func/ta_TRIMA.c \ 
          ../../../../../src/ta_func/ta_WMA.c \ 
          ../../../../../src/ta_func/ta_ATR.c \ 
          ../../../../../src/ta_func/ta_TRANGE.c \ 
          ../../../../../src/ta_func/ta_ADX.c \ 
          ../../../../../src/ta_func/ta_ADXR.c \ 
          ../../../../../src/ta_func/ta_APO.c \ 
          ../../../../../src/ta_func/ta_AROON.c \ 
          ../../../../../src/ta_func/ta_AROONOSC.c \ 
          ../../../../../src/ta_func/ta_CCI.c \ 
          ../../../../../src/ta_func/ta_DX.c \ 
          ../../../../../src/ta_func/ta_MACD.c \ 
          ../../../../../src/ta_func/ta_MACDEXT.c \ 
          ../../../../../src/ta_func/ta_MACDFIX.c \ 
          ../../../../../src/ta_func/ta_MFI.c \ 
          ../../../../../src/ta_func/ta_MINUS_DI.c \ 
          ../../../../../src/ta_func/ta_MINUS_DM.c \ 
          ../../../../../src/ta_func/ta_MOM.c \ 
          ../../../../../src/ta_func/ta_PPO.c \ 
          ../../../../../src/ta_func/ta_PLUS_DI.c \ 
          ../../../../../src/ta_func/ta_PLUS_DM.c \ 
          ../../../../../src/ta_func/ta_ROC.c \ 
          ../../../../../src/ta_func/ta_ROCP.c \ 
          ../../../../../src/ta_func/ta_ROCR.c \ 
          ../../../../../src/ta_func/ta_ROCR100.c \ 
          ../../../../../src/ta_func/ta_RSI.c \ 
          ../../../../../src/ta_func/ta_STOCH.c \ 
          ../../../../../src/ta_func/ta_STOCHF.c \ 
          ../../../../../src/ta_func/ta_STOCHRSI.c \ 
          ../../../../../src/ta_func/ta_TRIX.c \ 
          ../../../../../src/ta_func/ta_WILLR.c \ 
          ../../../../../src/ta_func/ta_HT_DCPERIOD.c \ 
          ../../../../../src/ta_func/ta_HT_DCPHASE.c \ 
          ../../../../../src/ta_func/ta_HT_PHASOR.c \ 
          ../../../../../src/ta_func/ta_HT_SINE.c \ 
          ../../../../../src/ta_func/ta_HT_TRENDMODE.c \ 
          ../../../../../src/ta_func/ta_AD.c \ 
          ../../../../../src/ta_func/ta_ADOSC.c \ 
          ../../../../../src/ta_func/ta_OBV.c \ 
          ../../../../../src/ta_func/ta_LINEARREG.c \ 
          ../../../../../src/ta_func/ta_LINEARREG_SLOPE.c \ 
          ../../../../../src/ta_func/ta_LINEARREG_ANGLE.c \ 
          ../../../../../src/ta_func/ta_LINEARREG_INTERCEPT.c \ 
          ../../../../../src/ta_func/ta_STDDEV.c \ 
          ../../../../../src/ta_func/ta_TSF.c \ 
          ../../../../../src/ta_func/ta_VAR.c \ 
          ../../../../../src/ta_func/ta_AVGPRICE.c \ 
          ../../../../../src/ta_func/ta_MEDPRICE.c \ 
          ../../../../../src/ta_func/ta_TYPPRICE.c \ 
          ../../../../../src/ta_func/ta_WCLPRICE.c 

# Compiler Options
INCLUDEPATH = ../../../../../src/ta_common \n              ../../../../../include 

# debug/release dependent options.
debug:DEFINES   *= TA_DEBUG
debug:DEFINES   *= _DEBUG
DEFINES        += TA_SINGLE_THREAD
thread:DEFINES -= TA_SINGLE_THREAD


# Platform dependent options.
win32:DEFINES         *= WIN32
win32-msvc:DEFINES    *= _MBCS _LIB

cmd:TEMP_CLEAN_ALL = ../../../../../temp/cmd/*.pch
cmr:TEMP_CLEAN_ALL = ../../../../../temp/cmr/*.pch
csd:TEMP_CLEAN_ALL = ../../../../../temp/csd/*.pch
csr:TEMP_CLEAN_ALL = ../../../../../temp/csr/*.pch

cmd:TEMP_CLEAN_ALL2 = ../../../../../temp/cmd/*.idb
cmr:TEMP_CLEAN_ALL2 = ../../../../../temp/cmr/*.idb
csd:TEMP_CLEAN_ALL2 = ../../../../../temp/csd/*.idb
csr:TEMP_CLEAN_ALL2 = ../../../../../temp/csr/*.idb

cmd:TEMP_CLEAN_ALL3 = ../../../../../temp/cmd/$$LIBTARGET/*.pch
cmr:TEMP_CLEAN_ALL3 = ../../../../../temp/cmr/$$LIBTARGET/*.pch
csd:TEMP_CLEAN_ALL3 = ../../../../../temp/csd/$$LIBTARGET/*.pch
csr:TEMP_CLEAN_ALL3 = ../../../../../temp/csr/$$LIBTARGET/*.pch

cmd:TEMP_CLEAN_ALL4 = ../../../../../temp/cmd/$$LIBTARGET/*.idb
cmr:TEMP_CLEAN_ALL4 = ../../../../../temp/cmr/$$LIBTARGET/*.idb
csd:TEMP_CLEAN_ALL4 = ../../../../../temp/csd/$$LIBTARGET/*.idb
csr:TEMP_CLEAN_ALL4 = ../../../../../temp/csr/$$LIBTARGET/*.idb

cmd:TEMP_CLEAN_ALL5 = ../../../../../temp/cmd/$$LIBTARGET/*.obj
cmr:TEMP_CLEAN_ALL5 = ../../../../../temp/cmr/$$LIBTARGET/*.obj
csd:TEMP_CLEAN_ALL5 = ../../../../../temp/csd/$$LIBTARGET/*.obj
csr:TEMP_CLEAN_ALL5 = ../../../../../temp/csr/$$LIBTARGET/*.obj

win32:CLEAN_FILES = ../../../../../bin/*.map ../../../../../bin/*._xe ../../../../../bin/*.tds ../../../../../bin/*.pdb ../../../../../bin/*.pbo ../../../../../bin/*.pbi ../../../../../bin/*.pbt $$TEMP_CLEAN_ALL $$TEMP_CLEAN_ALL2 $$TEMP_CLEAN_ALL3 $$TEMP_CLEAN_ALL4 $$TEMP_CLEAN_ALL5
