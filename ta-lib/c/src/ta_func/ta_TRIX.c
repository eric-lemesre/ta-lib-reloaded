/* TA-LIB Copyright (c) 1999-2005, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  MF       Mario Fortier
 *  AA       Andrew Atkinson
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *  020605 AA   Fix #1117656. NULL pointer assignement.
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #elif defined( _JAVA )
/* Generated */    #include "ta_defs.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */    #include "ta_trace.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::TRIX_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int TRIX_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_TRIX_Lookback( int           optInTimePeriod )  /* From 1 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   int emaLookback = LOOKBACK_CALL(EMA)( optInTimePeriod );
   return (emaLookback*3) + LOOKBACK_CALL(ROCR)( 1 );
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_TRIX - 1-day Rate-Of-Change (ROC) of a Triple Smooth EMA
 * 
 * Input  = double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod:(From 1 to 100000)
 *    Number of period
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::TRIX( int    startIdx,
/* Generated */                                         int    endIdx,
/* Generated */                                         cli::array<double>^ inReal,
/* Generated */                                         int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                                         [Out]int%    outBegIdx,
/* Generated */                                         [Out]int%    outNbElement,
/* Generated */                                         cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode TRIX( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         double       inReal[],
/* Generated */                         int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                         MInteger     outBegIdx,
/* Generated */                         MInteger     outNbElement,
/* Generated */                         double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_TRIX( int    startIdx,
/* Generated */                     int    endIdx,
/* Generated */                     const double inReal[],
/* Generated */                     int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                     int          *outBegIdx,
/* Generated */                     int          *outNbElement,
/* Generated */                     double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   double k;
   ARRAY_REF(tempBuffer);
   VALUE_HANDLE_INT(nbElement);
   VALUE_HANDLE_INT(begIdx);
   int totalLookback;
   int emaLookback, rocLookback;
   TA_RetCode retCode;
   int nbElementToOutput;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA)*/
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 30;
/* Generated */    else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !outReal )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Adjust the startIdx to account for the lookback. */
   emaLookback   = LOOKBACK_CALL(EMA)( optInTimePeriod );
   rocLookback   = LOOKBACK_CALL(ROCR)( 1 );
   totalLookback = (emaLookback*3) + rocLookback;

   if( startIdx < totalLookback )
      startIdx = totalLookback;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      return NAMESPACE(TA_RetCode)TA_SUCCESS; 
   }

   VALUE_HANDLE_DEREF(outBegIdx) = startIdx; 

   nbElementToOutput = (endIdx-startIdx)+1+totalLookback;

   /* Allocate a temporary buffer for performing
    * the calculation.
    */
   ARRAY_ALLOC(tempBuffer, nbElementToOutput );
   #if !defined( _JAVA )
      if( !tempBuffer )
      {
         VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
         VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
         return NAMESPACE(TA_RetCode)TA_ALLOC_ERR;
      }
   #endif

   /* Calculate the first EMA */   
   k = PER_TO_K(optInTimePeriod);  
   retCode = FUNCTION_CALL(INT_EMA)( (startIdx-totalLookback), endIdx, inReal,
                                     optInTimePeriod, k,
                                     VALUE_HANDLE_OUT(begIdx), VALUE_HANDLE_OUT(nbElement),
								     tempBuffer );
   
   /* Verify for failure or if not enough data after
    * calculating the EMA.
    */
   if( (retCode != NAMESPACE(TA_RetCode)TA_SUCCESS ) || (VALUE_HANDLE_GET(nbElement) == 0) )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      ARRAY_FREE( tempBuffer );
      return retCode;
   }

   nbElementToOutput--; /* Make this variable zero base from now on. */

   /* Calculate the second EMA */   
   nbElementToOutput -= emaLookback;
   retCode = FUNCTION_CALL_DOUBLE(INT_EMA)( 0, nbElementToOutput, tempBuffer,
                                            optInTimePeriod, k,
                                            VALUE_HANDLE_OUT(begIdx), VALUE_HANDLE_OUT(nbElement),
						                    tempBuffer );
   
   /* Verify for failure or if not enough data after
    * calculating the EMA.
    */
   if( (retCode != NAMESPACE(TA_RetCode)TA_SUCCESS ) || (VALUE_HANDLE_GET(nbElement) == 0) )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      ARRAY_FREE( tempBuffer );
      return retCode;
   }

   /* Calculate the third EMA */   
   nbElementToOutput -= emaLookback;
   retCode = FUNCTION_CALL_DOUBLE(INT_EMA)( 0, nbElementToOutput, tempBuffer,
                                            optInTimePeriod, k,
                                            VALUE_HANDLE_OUT(begIdx), VALUE_HANDLE_OUT(nbElement),
						                    tempBuffer );
   
   /* Verify for failure or if not enough data after
    * calculating the EMA.
    */
   if( (retCode != NAMESPACE(TA_RetCode)TA_SUCCESS ) || (VALUE_HANDLE_GET(nbElement) == 0) )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      ARRAY_FREE( tempBuffer );
      return retCode;
   }

   /* Calculate the 1-day Rate-Of-Change */
   nbElementToOutput -= emaLookback;
   retCode = FUNCTION_CALL_DOUBLE(ROC)( 0, nbElementToOutput,
                                        tempBuffer,
                                        1,  VALUE_HANDLE_OUT(begIdx), outNbElement,
                                        outReal );

   ARRAY_FREE( tempBuffer );
   /* Verify for failure or if not enough data after
    * calculating the rate-of-change.
    */
   if( (retCode != NAMESPACE(TA_RetCode)TA_SUCCESS ) || ((int)VALUE_HANDLE_DEREF(outNbElement) == 0) )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      return retCode;
   }

   return NAMESPACE(TA_RetCode)TA_SUCCESS;
}

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::TRIX( int    startIdx,
/* Generated */                                         int    endIdx,
/* Generated */                                         cli::array<float>^ inReal,
/* Generated */                                         int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                                         [Out]int%    outBegIdx,
/* Generated */                                         [Out]int%    outNbElement,
/* Generated */                                         cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode TRIX( int    startIdx,
/* Generated */                         int    endIdx,
/* Generated */                         float        inReal[],
/* Generated */                         int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                         MInteger     outBegIdx,
/* Generated */                         MInteger     outNbElement,
/* Generated */                         double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_TRIX( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       const float  inReal[],
/* Generated */                       int           optInTimePeriod, /* From 1 to 100000 */
/* Generated */                       int          *outBegIdx,
/* Generated */                       int          *outNbElement,
/* Generated */                       double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    double k;
/* Generated */    ARRAY_REF(tempBuffer);
/* Generated */    VALUE_HANDLE_INT(nbElement);
/* Generated */    VALUE_HANDLE_INT(begIdx);
/* Generated */    int totalLookback;
/* Generated */    int emaLookback, rocLookback;
/* Generated */    TA_RetCode retCode;
/* Generated */    int nbElementToOutput;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInTimePeriod = 30;
/* Generated */     else if( ((int)optInTimePeriod < 1) || ((int)optInTimePeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !outReal )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    emaLookback   = LOOKBACK_CALL(EMA)( optInTimePeriod );
/* Generated */    rocLookback   = LOOKBACK_CALL(ROCR)( 1 );
/* Generated */    totalLookback = (emaLookback*3) + rocLookback;
/* Generated */    if( startIdx < totalLookback )
/* Generated */       startIdx = totalLookback;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS; 
/* Generated */    }
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx) = startIdx; 
/* Generated */    nbElementToOutput = (endIdx-startIdx)+1+totalLookback;
/* Generated */    ARRAY_ALLOC(tempBuffer, nbElementToOutput );
/* Generated */    #if !defined( _JAVA )
/* Generated */       if( !tempBuffer )
/* Generated */       {
/* Generated */          VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */          VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */          return NAMESPACE(TA_RetCode)TA_ALLOC_ERR;
/* Generated */       }
/* Generated */    #endif
/* Generated */    k = PER_TO_K(optInTimePeriod);  
/* Generated */    retCode = FUNCTION_CALL(INT_EMA)( (startIdx-totalLookback), endIdx, inReal,
/* Generated */                                      optInTimePeriod, k,
/* Generated */                                      VALUE_HANDLE_OUT(begIdx), VALUE_HANDLE_OUT(nbElement),
/* Generated */ 								     tempBuffer );
/* Generated */    if( (retCode != NAMESPACE(TA_RetCode)TA_SUCCESS ) || (VALUE_HANDLE_GET(nbElement) == 0) )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       ARRAY_FREE( tempBuffer );
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    nbElementToOutput--; 
/* Generated */    nbElementToOutput -= emaLookback;
/* Generated */    retCode = FUNCTION_CALL_DOUBLE(INT_EMA)( 0, nbElementToOutput, tempBuffer,
/* Generated */                                             optInTimePeriod, k,
/* Generated */                                             VALUE_HANDLE_OUT(begIdx), VALUE_HANDLE_OUT(nbElement),
/* Generated */ 						                    tempBuffer );
/* Generated */    if( (retCode != NAMESPACE(TA_RetCode)TA_SUCCESS ) || (VALUE_HANDLE_GET(nbElement) == 0) )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       ARRAY_FREE( tempBuffer );
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    nbElementToOutput -= emaLookback;
/* Generated */    retCode = FUNCTION_CALL_DOUBLE(INT_EMA)( 0, nbElementToOutput, tempBuffer,
/* Generated */                                             optInTimePeriod, k,
/* Generated */                                             VALUE_HANDLE_OUT(begIdx), VALUE_HANDLE_OUT(nbElement),
/* Generated */ 						                    tempBuffer );
/* Generated */    if( (retCode != NAMESPACE(TA_RetCode)TA_SUCCESS ) || (VALUE_HANDLE_GET(nbElement) == 0) )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       ARRAY_FREE( tempBuffer );
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    nbElementToOutput -= emaLookback;
/* Generated */    retCode = FUNCTION_CALL_DOUBLE(ROC)( 0, nbElementToOutput,
/* Generated */                                         tempBuffer,
/* Generated */                                         1,  VALUE_HANDLE_OUT(begIdx), outNbElement,
/* Generated */                                         outReal );
/* Generated */    ARRAY_FREE( tempBuffer );
/* Generated */    if( (retCode != NAMESPACE(TA_RetCode)TA_SUCCESS ) || ((int)VALUE_HANDLE_DEREF(outNbElement) == 0) )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       return retCode;
/* Generated */    }
/* Generated */    return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

