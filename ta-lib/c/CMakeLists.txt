
#SET(TA_LIB_FLAGS "")
#SET(TA_LIB_INCLUDE_DIRS "")
#SET(TA_LIB_LIBRARY_DIRS "")
#SET(TA_LIB_LIBRARIES "")

SET(LIBRARY_OUTPUT_PATH ${ta-lib_BINARY_DIR}/lib/ CACHE PATH "Single out dir for all libs" FORCE)
SET(TA_LIB_LIBRARY_DIRS lib)
LINK_DIRECTORIES(${ta-lib_BINARY_DIR}/lib)
SET(TA_LIB_CSOURCE_DIR "${ta-lib_SOURCE_DIR}/ta-lib/c")

#SET(priv_HEADERS
#	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/ta_frame_priv.h
#	${TA_LIB_CSOURCE_DIR}/src/ta_common/ta_global.h
#	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_utility.h
#	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/ta_def_ui.h
#	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/frames/ta_frame.h
#	${TA_LIB_CSOURCE_DIR}/src/ta_common/ta_magic_nb.h
#	${TA_LIB_CSOURCE_DIR}/src/ta_common/ta_memory.h
#)

SET(ta-lib_HEADERS
	${TA_LIB_CSOURCE_DIR}/include/ta_abstract.h
	${TA_LIB_CSOURCE_DIR}/include/ta_common.h
	${TA_LIB_CSOURCE_DIR}/include/ta_defs.h
	${TA_LIB_CSOURCE_DIR}/include/ta_func.h
	${TA_LIB_CSOURCE_DIR}/include/ta_libc.h
)

INCLUDE_DIRECTORIES(${TA_LIB_CSOURCE_DIR}/include
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract 
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/frames
	${TA_LIB_CSOURCE_DIR}/src/ta_common
	${TA_LIB_CSOURCE_DIR}/src/ta_func
)

SET(ta-lib_CSOURCES
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_LINEARREG.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MAX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLHAMMER.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLDRAGONFLYDOJI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLGRAVESTONEDOJI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLABANDONEDBABY.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MAVP.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLCONCEALBABYSWALL.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_HT_TRENDMODE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_IMI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLADVANCEBLOCK.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_AROONOSC.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLLONGLINE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MIDPOINT.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_PPO.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_WMA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_HT_DCPHASE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLSPINNINGTOP.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ACCBANDS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLIDENTICAL3CROWS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_LINEARREG_ANGLE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ADOSC.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDL3OUTSIDE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CORREL.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_SMA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ULTOSC.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_AD.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLUPSIDEGAP2CROWS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLUNIQUE3RIVER.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLRISEFALL3METHODS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLLADDERBOTTOM.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_PLUS_DM.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ADD.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_STOCHRSI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLHANGINGMAN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_NVI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_T3.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_HT_PHASOR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLTASUKIGAP.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_DEMA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_RSI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MIN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLSTICKSANDWICH.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MINMAX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLENGULFING.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLDOJI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ACOS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_SAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLINNECK.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_STOCH.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLPIERCING.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ASIN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MACD.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_KAMA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ATR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ADXR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLCLOSINGMARUBOZU.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLDARKCLOUDCOVER.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_TRIX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_HT_TRENDLINE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ROCP.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLMORNINGSTAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MIDPRICE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_LOG10.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLGAPSIDESIDEWHITE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_SIN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_TSF.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_STOCHF.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CMO.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDL3STARSINSOUTH.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_AROON.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_TAN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_SINH.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_utility.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_TYPPRICE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_NATR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDL3BLACKCROWS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_HT_DCPERIOD.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLBREAKAWAY.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_PLUS_DI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_STDDEV.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDL2CROWS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MOM.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_TRIMA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_TRANGE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLHIKKAKE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLEVENINGDOJISTAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MAXINDEX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_FLOOR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ROCR100.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLSEPARATINGLINES.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLHARAMICROSS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_WCLPRICE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_BBANDS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLLONGLEGGEDDOJI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CEIL.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_AVGDEV.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLCOUNTERATTACK.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_EXP.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLONNECK.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLINVERTEDHAMMER.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLXSIDEGAP3METHODS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLMARUBOZU.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CCI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MACDEXT.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLTHRUSTING.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLMATHOLD.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLHIKKAKEMOD.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLKICKINGBYLENGTH.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_LINEARREG_INTERCEPT.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLKICKING.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_SUB.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_LINEARREG_SLOPE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_HT_SINE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_COSH.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLDOJISTAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLHOMINGPIGEON.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_EMA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_COS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_SAREXT.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_LN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_TANH.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MACDFIX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_OBV.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_SUM.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_DX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_TEMA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MININDEX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MULT.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_APO.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_DIV.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_WILLR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLSHORTLINE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLRICKSHAWMAN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MEDPRICE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLMATCHINGLOW.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ROCR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLBELTHOLD.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLTAKURI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLTRISTAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLHARAMI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_PVI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ATAN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLHIGHWAVE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLSTALLEDPATTERN.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_VAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLEVENINGSTAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MAMA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDL3LINESTRIKE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDL3WHITESOLDIERS.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLSHOOTINGSTAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_BOP.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MINUS_DM.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ROC.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDLMORNINGDOJISTAR.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_AVGPRICE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MFI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MINMAXINDEX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_MINUS_DI.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_SQRT.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_BETA.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_CDL3INSIDE.c
	${TA_LIB_CSOURCE_DIR}/src/ta_func/ta_ADX.c
	${TA_LIB_CSOURCE_DIR}/src/ta_common/ta_version.c
	${TA_LIB_CSOURCE_DIR}/src/ta_common/ta_retcode.c
	${TA_LIB_CSOURCE_DIR}/src/ta_common/ta_global.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/frames/ta_frame.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/ta_abstract.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/ta_func_api.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/ta_def_ui.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/ta_group_idx.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_t.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_p.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_a.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_l.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_r.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_s.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_c.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_g.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_f.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_e.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_o.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_x.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_q.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_b.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_n.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_v.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_y.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_d.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_i.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_h.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_z.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_j.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_k.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_w.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_u.c
	${TA_LIB_CSOURCE_DIR}/src/ta_abstract/tables/table_m.c
)

IF(UNIX)
	ADD_LIBRARY(ta_lib SHARED ${ta-lib_CSOURCES})
	SET_TARGET_PROPERTIES(ta_lib PROPERTIES SOVERSION ${TA_LIB_VERSION_FULL} DEFINE_SYMBOL TA_LIB_SHARED)
	ADD_LIBRARY(ta_lib_static STATIC ${ta-lib_CSOURCES})
	SET_TARGET_PROPERTIES(ta_lib_static PROPERTIES OUTPUT_NAME ta_lib)
ENDIF(UNIX)

IF(WIN32)
	INCLUDE(GenerateExportHeader)
	ADD_LIBRARY(ta_lib SHARED ${ta-lib_CSOURCES})
	SET_TARGET_PROPERTIES(ta_lib PROPERTIES DEFINE_SYMBOL TA_LIB_SHARED)
	ADD_LIBRARY(ta_lib_static STATIC ${ta-lib_CSOURCES})
	SET_TARGET_PROPERTIES(ta_lib_static PROPERTIES OUTPUT_NAME ta_lib_a)
ENDIF(WIN32)

SET_TARGET_PROPERTIES(ta_lib PROPERTIES SOVERSION ${TA_LIB_VERSION_FULL})

INSTALL(FILES ${ta-lib_HEADERS} DESTINATION include/ta-lib)
INSTALL(TARGETS ta_lib ta_lib_static DESTINATION lib)
