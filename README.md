# TA-Lib : : Technical Analysis Library

![cmake workflow](https://github.com/eric-lemesre/ta-lib-reloaded/actions/workflows/cmake.yml/badge.svg)

This repository is **unofficial** migration from [svn TA-Lib on sourceforge](http://ta-lib.svn.sourceforge.net/viewvc/ta-lib/trunk/ta-lib/).

Information about Official TA-Lib implementation [TA-Lib web site](http://ta-lib.org).

## Migration roadmap 
see [Migration Roadamp](MigrationRoadMap.md)

## Build

The build system is now CMake. The build use default system build tools. see [CMake documentation](https://cmake.org/documentation/).

To build in directiory `build` from the root directory [TA-LibRoot]:

``` sh
# or cmake-gui
cmake . -B build
```

``` sh
cmake --build build/
```
