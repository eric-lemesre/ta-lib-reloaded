
include("${ta-lib_SOURCE_DIR}/cmake/OpenCVDetectApacheAnt.cmake")

find_jar(JUNIT_JAR NAMES "junit" "junit4"
    PATHS ${ta-lib_BINARY_DIR}
    VERSIONS 4.13.1 4.13.2)

IF(NOT JUNIT_JAR)
    SET(MAVEN_REMOTE_REPOS "https://repo1.maven.org/maven2")
    SET(JUNIT_VERSION "4.13.2")

    SET(HASH_FILE_TYPE "sha1")
    string(TOUPPER ${HASH_FILE_TYPE} HASH_TYPE)
    # SHA file
    SET(JUnit_SHA_URL ${MAVEN_REMOTE_REPOS}/junit/junit/${JUNIT_VERSION}/junit-${JUNIT_VERSION}.jar.asc.${HASH_FILE_TYPE})
    SET(JUNIT_JAR_FILE_SHA "${ta-lib_BINARY_DIR}/java/lib-test/junit-${JUNIT_VERSION}.jar.asc.${HASH_FILE_TYPE}")
    # jar file
    SET(JUNIT_JAR_URL ${MAVEN_REMOTE_REPOS}/junit/junit/${JUNIT_VERSION}/junit-${JUNIT_VERSION}.jar)
    SET(JUNIT_JAR_FILE "${ta-lib_BINARY_DIR}/java/lib-test/junit-${JUNIT_VERSION}.jar")

    message(STATUS "JUnit file not found download it from ${JUNIT_JAR_URL}")
    # Download SHA file
    file(DOWNLOAD ${JUnit_SHA_URL} ${JUNIT_JAR_FILE_SHA})
    file(READ ${JUNIT_JAR_FILE_SHA} JUNIT_JAR_SHA)
    #message(STATUS "SHA for file is ${JUNIT_JAR_SHA}")
    file(DOWNLOAD ${JUNIT_JAR_URL} ${JUNIT_JAR_FILE})
    SET(JUNIT_JAR ${JUNIT_JAR_FILE})

    # clean variables
    unset(MAVEN_REMOTE_REPOS)
    unset(HASH_FILE_TYPE)
    unset(HASH_TYPE)
    unset(JUnit_SHA_URL)
    unset(JUNIT_JAR_FILE_SHA)
    unset(JUNIT_JAR_URL)
    unset(JUNIT_JAR_FILE)

ENDIF(NOT JUNIT_JAR)
message(STATUS "JUnit found at  : ${JUNIT_JAR}")

SET(TA_LIB_JAVA_BASEDIR "${ta-lib_SOURCE_DIR}/ta-lib/java")
SET(TA_LIB_JAVA_BASE_SOURCEDIR "${TA_LIB_JAVA_BASEDIR}/ta-lib/src")
#set(TA_LIB_JAVA_PACKAGEDIR "meta/com/tictactec/ta/lib") 
#SET(TA_LIB_JAVA_SOURCEDIR "${TA_LIB_JAVA_BASE_SOURCEDIR}/${meta/com/tictactec/ta/lib}")

SET(TA_LIB_JAR_TARGET_NAME "${PROJECT_NAME}-${TA_LIB_VERSION_FULL}")
SET(TA_LIB_JAVA_SOURCE_VERSION ${JAVA_SOURCE_VERSION})
SET(TA_LIB_JAVA_TARGET_VERSION ${JAVA_SOURCE_VERSION})

configure_file(${TA_LIB_JAVA_BASEDIR}/build.xml.in ${ta-lib_BINARY_DIR}/java/build.xml @ONLY)

ADD_CUSTOM_TARGET( ant_build ALL )
ADD_CUSTOM_COMMAND(
    TARGET  ant_build
    COMMAND ${ANT_EXECUTABLE} 
    WORKING_DIRECTORY ${ta-lib_BINARY_DIR}/java
)

IF(TA_LIB_ENABLE_TESTS)
    set(TA_LIB_CLASSPATH_TEST "${ta-lib_BINARY_DIR}/${TA_LIB_JAR_TARGET_NAME}-test.jar:${JUNIT_JAR}:${ta-lib_BINARY_DIR}/lib-java/${TA_LIB_JAR_TARGET_NAME}.jar")
    add_test(NAME ta-lib_jar COMMAND ${Java_JAVA_EXECUTABLE} -cp ${TA_LIB_CLASSPATH_TEST} com.tictactec.ta.lib.test.AllTests)
ENDIF(TA_LIB_ENABLE_TESTS)