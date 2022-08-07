## Migration roadmap


  1. import to git from svn
     * [x] import code history
     * [x] import tag
     * [x] binary release
  2. port all build script to CMake Build tools
     * [ ] Build ta-lib library from c source file `ta-lib/c/src/{ta_abstrac,ta_common,ta_func}` [link to source](ta-lib/c/src)
       * [x] Unix shared lib
       * [x] Unix static lib
       * [x] Windows dll
       * [ ] Mac OSX shared lib
       * [ ] Mac OSX static lib
     * [x ] Build ta_regtest programme from c source file `ta-lib/c/src/tools/ta_regtest` [link to source](ta-lib/c/src/tools/ta_regtest)
       * [x] on Unix OS
       * [x] on Windows OS
       * [ ] on MacOSX OS
     * [ ] Build gen_code programme from c source file `ta-lib/c/src/tools/gen_code` [link to source](ta-lib/c/src/tools/gen_code)
        * [x] target to Unix OS
        * [x] target to Windows OS
        * [ ] target to MacOSX OS
     * [ ] Build ta-lib.jar programme from java source file `ta-lib/java` [link to source](ta-lib/java)
       * with initial `ant` script file
          * [x] running on Unix OS
          * [x] running on Windows OS
          * [ ] running on MacOSX OS
     * [ ] Build SWIG wrapper `ta-lib/swig` [link to source](ta-lib/swig)
       * for language PERL
          * [ ] running on Unix OS
          * [ ] running on Windows OS
          * [ ] running on MacOSX OS
       * for language Python
          * [ ] running on Unix OS
          * [ ] running on Windows OS
          * [ ] running on MacOSX OS
     * [ ] Build DotNet from `ta-lib/dotnet` [link to source](ta-lib/dotnet)
       * [ ] Running on Windows
       * [ ] Running on Unix
       * [ ] running on Mac OSX
     * [ ] Build Excel from `ta-lib/excel` [link to source](ta-lib/excel)
       * [ ] Running on Windows
       * [ ] Running on Unix
       * [ ] running on Mac OSX

  3. writing documentation for all functions and indicators
     1. see [functions](tadoc/functions.rst)
     2. see [indicator](tadoc/indicators.rst)
  4. improve tests for all artifact (probably with [Code Coverage Summary](https://github.com/marketplace/actions/code-coverage-summary))
     * [ ] unit tests library ta-lib
     * [ ] functional tests library (actual ta_regtest)
     * [ ] functional tests java implementation
     * [ ] functional tests swig for PERL
     * [ ] functional tests swig for Python
     * [ ] functional tests dotnet
     * [ ] functional tests Excel
