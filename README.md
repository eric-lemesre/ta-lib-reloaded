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
cmake --build build
```

### this last command build in Unix OS

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
$ ctest -V --test-dir build
Internal ctest changing into directory: [TA-LibRoot]/build
UpdateCTestConfiguration  from :[TA-LibRoot]/build/DartConfiguration.tcl
Parse Config file:[TA-LibRoot]/build/DartConfiguration.tcl
UpdateCTestConfiguration  from :[TA-LibRoot]/build/DartConfiguration.tcl
Parse Config file:[TA-LibRoot]/build/DartConfiguration.tcl
Test project [TA-LibRoot]/build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: ta_regtest

1: Test command: [TA-LibRoot]/build/bin/ta_regtest
1: Working Directory: [TA-LibRoot]/build
1: Test timeout computed to be: 1500
1: 
1: ta_regtest V0.6.0-dev (Aug 17 2022 09:38:43) - Regression Tests of TA-Lib code
1: 
1: Testing utility functions
1: Testing Abstract interface
1: Testing the TA functions
1:          MATH,VECTOR,DCPERIOD/PHASE,TRENDLINE/MODE: Testing...done.
1:                                All Moving Averages: Testing...done.
1:                                  AROON,CORREL,BETA: Testing...done.
1:                              CCI,WILLR,ULTOSC,NATR: Testing...done.
1:                                       BOP,AVGPRICE: Testing...done.
1:                                            RSI,CMO: Testing...done.
1:       MIN,MAX,MININDEX,MAXINDEX,MINMAX,MINMAXINDEX: Testing...done.
1:                                             PO,APO: Testing...done.
1:                                  ADX,ADXR,DI,DM,DX: Testing...done.
1:                                         SAR,SAREXT: Testing...done.
1:                              STOCH,STOCHF,STOCHRSI: Testing...done.
1:                                       MFI,AD,ADOSC: Testing...done.
1:                                        PHASOR,SINE: Testing...done.
1:                                               TRIX: Testing...done.
1:                               MACD,MACDFIX,MACDEXT: Testing...done.
1:                          MOM,ROC,ROCP,ROCR,ROCR100: Testing...done.
1:                                         TRANGE,ATR: Testing...done.
1:                                         STDDEV,VAR: Testing...done.
1:                                             AVGDEV: Testing...done.
1:                                             BBANDS: Testing...done.
1:                                   All Candlesticks: Testing...done.
1: 
1: Warning: Code profiling not supported for this platform.
1: 
1: * All tests succeeded. Enjoy the library. *
1/2 Test #1: ta_regtest .......................   Passed   10.97 sec
test 2
    Start 2: ta-lib_jar

2: Test command: /usr/bin/java "-cp" "[TA-LibRoot]/build/lib-java/ta-lib-0.6.0-dev-test.jar:/usr/share/java/junit4-4.13.2.jar:[TA-LibRoot]/build/lib-java/ta-lib-0.6.0-dev.jar" "com.tictactec.ta.lib.test.AllTests"
2: Working Directory: [TA-LibRoot]/build/ta-lib/java
2: Test timeout computed to be: 1500
2: .
2: Time: 0,007
2: 
2: OK (1 test)
2: 
2/2 Test #2: ta-lib_jar .......................   Passed    0.15 sec

100% tests passed, 0 tests failed out of 2

Total Test time (real) =  11.12 sec
```

#### Pakaging

1. Generate C library packages

    ``` sh
    make -C build package
    ```

    * `build/ta-lib-[full version]-Linux.tar.gz`
    * `build/ta-lib-[full version]-Linux.zip`

2. Generate source packages

    ``` sh
    make -C build package_source
    ```

    * `build/ta-lib-src-[full version]-Linux.tar.gz`
    * `build/ta-lib-src-[full version].zip`

3. build documentation

    ``` sh
    make -C build docs
    ```

    * `build/tadoc/ta-lib-doc/` : html docs from .rst files in `[TA-LibRoot]/tadoc/src`
