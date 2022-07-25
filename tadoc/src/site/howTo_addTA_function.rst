========================
How-to add a TA function
========================

source is `here <https://ta-lib.org/d_misc/how-to_function.html>`_ (on https://ta-lib.org)

------------
Introduction
------------

This document explain how someone can contribute a new technical function. This document is intended 
for developers working on enhancing TA-Lib, not for user of TA-Lib. User should instead consult the API documents.

-----------------
What is gen_code?
-----------------

A long term goal of TA-Lib is to remain easily portable to new platforms and provides interface to a variety of language. 
To facilitate the maintenance, the utility gen_code has been written to generate all the glue code. Already, this allows 
the same C/C++ TA function to be more easily integrated in .NET, Excel and Perl. The utility also forces consistency for 
the parameter of all the TA functions because both the ta_func.h and the function body (not its content) are generated.

Each TA function has its interface describe in a `table_x.cpp` file. All these tables are found in `ta-lib\c\src\ta_abstract\tables`. 
The utility gen_code uses these tables as input to figure out the function name, its parameters, the parameter range etc...

Type `gen_code ?` to see the list of generated files.

Most of the files are entirely re-generated, but some are a mix of generated and existing code. The TA function files 
found in the directory `ta-lib\c\src\ta_func` are mixed. You can easily recognize which portion is generated; they all start 
with the comment `/* Generated */...`

If there is no change to the `table_x.cpp` files, calling gen_code over and over again will have no effect.

---------------------------------
Steps to create a new TA function
---------------------------------

1. Open the `table_<x>.c` file, where **<x>** is the first letter of the TA function. As an example the function `TA_RSI` will be find in the file `table_r.c`

2. Follow the instruction in the `table_<x>.c` to add a new function. It is strongly suggest to cut&paste from an existing function and rename as needed. You can always change the table later if you want to add/remove some parameters.

3. Compile `gen_code`.

4. Run `gen_code` from `ta-lib\c\bin`

5. The body of the function will be created in `ta-lib\c\src\ta_func`. Add the code for the TA function outside of the generated area. Comments in the file helps to identify these area. These areas are preserve when `gen_code` is run again.

Writing a new TA function requires a good understanding of `startidx`, `endidx`, `outBegIdx` and `outNbElement`. If you are not sure about this, 
I strongly suggest to study a simple TA function and read again the C/C++ API.

--------------------
Language Abstraction
--------------------

You might have notice that the same code is also compiled on .NET and Java. How is that possible? C is the mother of (most) modern language. 
By carefully using a subset of the C language we end up with only a few syntax difference between C, C++, managed C++ (.NET) and Java.

All these syntax differences are handled by pre-processing as follow:

.. code-block:: c
   :caption: pre-processing

    #if defined( _MANAGED )
        ... here is the code for VS2005 and later...
    #elif defined( _JAVA )
        ... here is the code for Java...
    #else
        ... here is the ANSI C code...
    #endif


Some macro are also defined in `ta_memory.h` to abstract some fundamental differences related to array, pointer, memory allocation etc...

If you do not want to bother about all this language abstraction stuff, just write your function in C (or C++ minus the OO) and an active 
maintainer of TA-Lib might do the additional steps to get the code to work with all platforms/languages.

-------------------------
Is there an easier way?!?
-------------------------

 * Yes. Cut&paste an existing function. 
 * Add/remove parameters as needed, replace with your own code, do your best for testing 
 * and submit your code to the forum or e-mail to mfortier@ta-lib.org. 
 * Someone might complete the integration for you.
 