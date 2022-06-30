

find_jar(JUNIT_JAR "junit4")

IF(JUNIT_JAR-NOTFOUND)
    SET(MAVEN_REMOTE_REPOS "https://repo1.maven.org/maven2")
    SET(JUNIT_JAR_VERSION "4.13")
    file(DOWNLOAD ${MAVEN_REMOTE_REPOS}/junit/junit/${JUNIT_JAR_VERSION}/junit-${JUNIT_JAR_VERSION}.jar.asc.sha1 JUNIT_JAR_FILE_SHA)
    file(READ ${JUNIT_JAR_FILE_SHA} JUNIT_JAR_SHA)
    file(DOWNLOAD ${MAVEN_REMOTE_REPOS}/junit/junit/${JUNIT_JAR_VERSION}/junit-${JUNIT_JAR_VERSION}.jar 
        EXPECTED_HASH SHA1=${JUNIT_JAR_SHA}
        JUNIT_JAR)
ENDIF(JUNIT_JAR-NOTFOUND)

message(STATUS ${JUNIT_JAR})

SET(TA_LIB_JAVA_BASEDIR "${ta-lib_SOURCE_DIR}/java")
SET(TA_LIB_JAVA_BASE_SOURCEDIR "${TA_LIB_JAVA_BASEDIR}/src")
#set(TA_LIB_JAVA_PACKAGEDIR "meta/com/tictactec/ta/lib") 
#SET(TA_LIB_JAVA_SOURCEDIR "${TA_LIB_JAVA_BASE_SOURCEDIR}/${meta/com/tictactec/ta/lib}")

SET(TA_LIB_JAR_TARGET_NAME "${PROJECT_NAME}-${TA_LIB_VERSION_FULL}")
SET(TA_LIB_JAVA_SOURCE_VERSION ${JAVA_SOURCE_VERSION})
SET(TA_LIB_JAVA_TARGET_VERSION ${JAVA_SOURCE_VERSION})

configure_file(${TA_LIB_JAVA_BASEDIR}/build.xml.in ${ta-lib_BINARY_DIR}/build.xml)

ADD_CUSTOM_TARGET( ant_build ALL )
ADD_CUSTOM_COMMAND(
    TARGET  ant_build
    COMMAND ant 
    WORKING_DIRECTORY ${ta-lib_BINARY_DIR}
)

# set(TA_LIB_JSOURCES 
#     ${TA_LIB_JAVA_SOURCEDIR}/Core.java
#     ${TA_LIB_JAVA_SOURCEDIR}/MInteger.java
#     ${TA_LIB_JAVA_SOURCEDIR}/CandleSetting.java
#     ${TA_LIB_JAVA_SOURCEDIR}/CoreAnnotated.java
#     ${TA_LIB_JAVA_SOURCEDIR}/Compatibility.java
#     ${TA_LIB_JAVA_SOURCEDIR}/MoneyFlow.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/PriceHolder.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/TaGrpService.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/CoreMetaInfo.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/TaFuncService.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/FuncFlags.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/InputParameterType.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/InputFlags.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/RealList.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/OutputParameterInfo.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/FuncInfo.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/OptInputParameterType.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/OutputParameterType.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/OutputFlags.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/RealRange.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/IntegerList.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/IntegerRange.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/InputParameterInfo.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/OptInputParameterInfo.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/annotation/OptInputFlags.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/helpers/SimpleHelper.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/PriceInputParameter.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/TaFuncSignature.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/CoreMetaData.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/TaFuncMetaInfo.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/CoreMetaDataCompatibility.java
#     ${TA_LIB_JAVA_SOURCEDIR}/meta/TaFuncClosure.java
#     ${TA_LIB_JAVA_SOURCEDIR}/RangeType.java
#     ${TA_LIB_JAVA_SOURCEDIR}/MAType.java
#     ${TA_LIB_JAVA_SOURCEDIR}/RetCode.java
#     ${TA_LIB_JAVA_SOURCEDIR}/CandleSettingType.java
#     ${TA_LIB_JAVA_SOURCEDIR}/FuncUnstId.java
# )

# set(TA_LIB_JSOURCESTests 
#     ${TA_LIB_JAVA_SOURCEDIR}/test/InputData.java
#     ${TA_LIB_JAVA_SOURCEDIR}/test/TestAbstractClosure.java
#     ${TA_LIB_JAVA_SOURCEDIR}/test/TestData.java
#     ${TA_LIB_JAVA_SOURCEDIR}/test/TestCoreMetaData.java
#     ${TA_LIB_JAVA_SOURCEDIR}/test/MIntegerTest.java
#     ${TA_LIB_JAVA_SOURCEDIR}/test/CombinationGenerator.java
#     ${TA_LIB_JAVA_SOURCEDIR}/test/TestAbstract.java
#     ${TA_LIB_JAVA_SOURCEDIR}/test/AllTests.java
#     ${TA_LIB_JAVA_SOURCEDIR}/test/CoreTest.java
# ) 

# message(STATUS "JUnit to ${JUNIT_JAR}")


# add_jar(${PROJECT_NAME}
#     SOURCES ${TA_LIB_JSOURCES}
#     VERSION ${TA_LIB_VERSION_FULL}
# )

# get_target_property(_jarFile ${PROJECT_NAME} JAR_FILE)
# get_target_property(_classDir ${PROJECT_NAME} CLASSDIR)

# message(STATUS "Jar file ${_jarFile}")
# message(STATUS "Class compiled to ${_classDir}")


# add_jar("${PROJECT_NAME}-test"
#     SOURCES ${TA_LIB_JSOURCESTests}
#     VERSION ${TA_LIB_VERSION_FULL}
# )
