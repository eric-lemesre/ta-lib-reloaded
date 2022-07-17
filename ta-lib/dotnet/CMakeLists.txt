
# Set global .NET Framework version.
SET(CMAKE_DOTNET_TARGET_FRAMEWORK_VERSION "v4.7.2")

# Set the C# language version for all projects.
SET(CMAKE_CSharp_FLAGS "/langversion:6")

# Explicitly set the `PlatformTarget` for C# projects, since AnyCPU can result in 
# System.BadImageFormatException throws, when trying to load C++/CLI assemblies.
get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(isMultiConfig)
  if(NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES "Release;Debug" CACHE STRING
    "Choose the type of builds, options are: Debug Release RelWithDebInfo MinSizeRel. (default: Release;Debug)"
    FORCE)
  endif()
  message(STATUS "Configuration types: ${CMAKE_CONFIGURATION_TYPES}")
else()
  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel. (default: Release)"
    FORCE)
  endif()
  message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
endif()

# Layout build dir like install dir
include(GNUInstallDirs)
if(UNIX)
  option(BUILD_SHARED_LIBS "Build shared libraries (.so or .dyld)." ON)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dotnet/${CMAKE_INSTALL_LIBDIR})
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dotnet/${CMAKE_INSTALL_LIBDIR})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dotnet/${CMAKE_INSTALL_BINDIR})
  # for multi-config build system (e.g. Xcode, Ninja Multi-Config)
  foreach(OutputConfig IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER ${OutputConfig} OUTPUTCONFIG)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/dotnet/${OutputConfig}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/dotnet/${OutputConfig}/${CMAKE_INSTALL_LIBDIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/dotnet/${OutputConfig}/${CMAKE_INSTALL_BINDIR})
  endforeach()
else()
  # Currently Only support static build for windows
  option(BUILD_SHARED_LIBS "Build shared libraries (.dll)." OFF)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dotnet/${CMAKE_INSTALL_BINDIR})
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dotnet/${CMAKE_INSTALL_BINDIR})
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dotnet/${CMAKE_INSTALL_BINDIR})
  # for multi-config builds (e.g. msvc)
  foreach(OutputConfig IN LISTS CMAKE_CONFIGURATION_TYPES)
    string(TOUPPER ${OutputConfig} OUTPUTCONFIG)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/dotnet/${OutputConfig}/${CMAKE_INSTALL_BINDIR})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/dotnet/${OutputConfig}/${CMAKE_INSTALL_BINDIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_BINARY_DIR}/dotnet/${OutputConfig}/${CMAKE_INSTALL_BINDIR})
  endforeach()
endif()

# Set the C++ standard for all projects.
SET(CMAKE_CXX_STANDARD 17)


# Setup project to use C# utilities.
INCLUDE(CSharpUtilities)

SET(TA_LIB_CSharp_BASEDIR "${ta-lib_SOURCE_DIR}/dotnet/src/Core")

SET(TA_LIB_CSharpSOURCES 
    "${TA_LIB_CSharp_BASEDIR}/AssemblyInfo.cpp"
    "${TA_LIB_CSharp_BASEDIR}/resource.h"
    "${TA_LIB_CSharp_BASEDIR}/Stdafx.cpp"
    "${TA_LIB_CSharp_BASEDIR}/Stdafx.h"
    "${TA_LIB_CSharp_BASEDIR}/TA-Lib-Core.cpp"
    "${TA_LIB_CSharp_BASEDIR}/TA-Lib-Core.h"
)

SET(TA_LIB_CSharpRESOURCES 
    "${TA_LIB_CSharp_BASEDIR}/app.ico"
    "${TA_LIB_CSharp_BASEDIR}/app.rc"
)
INCLUDE_DIRECTORIES(${TA_LIB_CSharp_BASEDIR})
# Optional: Create source groups for better code organization.
SOURCE_GROUP(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${TA_LIB_CSharpSOURCES} ${TA_LIB_CSharpSOURCES})

# Add shared library project.
ADD_LIBRARY(${PROJECT_NAME} SHARED
    "${TA_LIB_CSharpSOURCES}"
    "${TA_LIB_CSharpRESOURCES}"
)

