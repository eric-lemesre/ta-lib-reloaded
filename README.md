# TA-Lib : : Technical Analysis Library

![cmake workflow](https://github.com/eric-lemesre/ta-lib-reloaded/actions/workflows/cmake.yml/badge.svg)

This repository is **unofficial** migration from [svn TA-Lib on sourceforge](http://ta-lib.svn.sourceforge.net/viewvc/ta-lib/trunk/ta-lib/).

Information about Official TA-Lib implementation [TA-Lib web site](http://ta-lib.org).

## Migration roadmap 
see [Migration Roadamp](MigrationRoadMap.md)

## Build Unix

The build system is now CMake. The build use default system build tools. see [CMake documentation](https://cmake.org/documentation/).

To build in directory `build` from the root directory [TA-LibRoot]:

``` sh
# or cmake-gui
$ cmake . -B build
```

``` sh
$ cmake --build build/
```

### this last command build in Unix OS :
* `build/bin/gen_code` : program to generate lost of things for new function.
* `build/bin/te_regtest` : regression test for somme functions.
* `build/lib/lalib_lib.a` : library to include in static link.
* `build/lib/talib_lib.so` and `lib/talib_lib.so.[full version]` : dynamic library.
* `build/lib-java/ta-lib-[full version]-sources.jar` : jar sources file.
* `build/lib-java/ta-lib-[full version].jar` : library jar for java.
* `build/ta-lib-[full version]-test.jar` : jar for testing java package.

#### run test 

``` sh
# build test and run it
$ make -C build test
make: Entering directory '[TA-LibRoot]/build'
Running tests...
Test project [TA-LibRoot]/build
    Start 1: ta_regtest
1/2 Test #1: ta_regtest .......................   Passed   11.08 sec
    Start 2: ta-lib_jar
2/2 Test #2: ta-lib_jar .......................   Passed    0.17 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =  11.25 sec
make: Leaving directory '[TA-LibRoot]/build'
```

#### Pakaging

1. Generate C library packages

  ``` sh
  $ make -C build package
  ```

* `build/ta-lib-[full version]-Linux.tar.gz`
* `build/ta-lib-[full version]-Linux.zip`

2. Generate source packages
  ``` sh
  $ make -C build package_source
  ```
* `build/ta-lib-src-[full version]-Linux.tar.gz`
* `build/ta-lib-src-[full version].zip`

3. build documentation
  ``` sh
  $ make -C build docs
  ```
* `build/tadoc/ta-lib-doc/` : html docs from .rst files in `[TA-LibRoot]/tadoc/src`
