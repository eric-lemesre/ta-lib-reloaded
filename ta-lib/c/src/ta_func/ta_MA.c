/* TA-LIB Copyright (c) 1999-2003, Mario Fortier
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
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *  022203 MF   Add MAMA
 *  040503 MF   Add T3
 *  052603 MF   Adapt code to compile with .NET Managed C++
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #using <mscorlib.dll>
/* Generated */    #include "Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
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
/* Generated */ int Core::MA_Lookback( int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                      TA_MAType     optInMAType ) /* Generated */ 
/* Generated */ #else
/* Generated */ int TA_MA_Lookback( int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                   TA_MAType     optInMAType ) /* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   int retValue;

   switch( optInMAType )
   {
   case TA_MAType_SMA:
      retValue = TA_SMA_Lookback( optInTimePeriod );
      break;

   case TA_MAType_EMA:
      retValue = TA_EMA_Lookback( optInTimePeriod );
      break;

   case TA_MAType_WMA:
      retValue = TA_WMA_Lookback( optInTimePeriod );
      break;

   case TA_MAType_DEMA:
      retValue = TA_DEMA_Lookback( optInTimePeriod );
      break;

   case TA_MAType_TEMA:
      retValue = TA_TEMA_Lookback( optInTimePeriod );
      break;

   case TA_MAType_TRIMA:
      retValue = TA_TRIMA_Lookback( optInTimePeriod );
      break;

   case TA_MAType_KAMA:
      retValue = TA_KAMA_Lookback( optInTimePeriod );
      break;

   case TA_MAType_MAMA:
      retValue = TA_MAMA_Lookback( 0.5, 0.05 );
      break;

   case TA_MAType_T3:
      retValue = TA_T3_Lookback( optInTimePeriod, 0.7 );
      break;

   default:
      retValue = 0;
   }

   return retValue;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_MA - All Moving Average
 * 
 * Input  = double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod:(From 2 to 100000)
 *    Number of period
 * 
 * optInMAType:
 *    Type of Moving Average
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::MA( int    startIdx,
/* Generated */                                 int    endIdx,
/* Generated */                                 double       inReal __gc [],
/* Generated */                                 int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                 TA_MAType     optInMAType,
/* Generated */                                 [OutAttribute]Int32 *outBegIdx,
/* Generated */                                 [OutAttribute]Int32 *outNbElement,
/* Generated */                                 double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_MA( int    startIdx,
/* Generated */                   int    endIdx,
/* Generated */                   const double inReal[],
/* Generated */                   int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                   TA_MAType     optInMAType,
/* Generated */                   int          *outBegIdx,
/* Generated */                   int          *outNbElement,
/* Generated */                   double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   ARRAY_REF(dummyBuffer);
   TA_RetCode retCode;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    if( !inReal ) return TA_BAD_PARAM;
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 30;
/* Generated */    else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED)
/* Generated */    if( (int)optInMAType == TA_INTEGER_DEFAULT )
/* Generated */       optInMAType = 0;
/* Generated */    else if( ((int)optInMAType < 0) || ((int)optInMAType > 8) )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) */
/* Generated */    if( outReal == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Simply call the internal implementation of the
    * requested moving average.
    */
   switch( optInMAType )
   {
   case TA_MAType_SMA:
      retCode = TA_PREFIX(INT_SMA)( startIdx, endIdx, inReal, optInTimePeriod,
                                  outBegIdx, outNbElement, outReal );
      break;

   case TA_MAType_EMA:
      retCode = TA_PREFIX(INT_EMA)( startIdx, endIdx, inReal,
                                  optInTimePeriod, PER_TO_K(optInTimePeriod),
                                  outBegIdx, outNbElement, outReal );
      break;

   case TA_MAType_WMA:
      retCode = TA_PREFIX(WMA)( startIdx, endIdx, inReal, optInTimePeriod,
                              outBegIdx, outNbElement, outReal );
      break;

   case TA_MAType_DEMA:
      retCode = TA_PREFIX(DEMA)( startIdx, endIdx, inReal, optInTimePeriod,
                               outBegIdx, outNbElement, outReal );
      break;

   case TA_MAType_TEMA:
      retCode = TA_PREFIX(TEMA)( startIdx, endIdx, inReal, optInTimePeriod,
                               outBegIdx, outNbElement, outReal );
      break;

   case TA_MAType_TRIMA:
      retCode = TA_PREFIX(TRIMA)( startIdx, endIdx, inReal, optInTimePeriod,
                                outBegIdx, outNbElement, outReal );
      break;

   case TA_MAType_KAMA:
      retCode = TA_PREFIX(KAMA)( startIdx, endIdx, inReal, optInTimePeriod,
                               outBegIdx, outNbElement, outReal );
      break;

   case TA_MAType_MAMA:
      /* The optInTimePeriod is ignored and the FAMA output of the MAMA
       * is ignored.
       */
      ARRAY_ALLOC(dummyBuffer, (endIdx-startIdx+1) );
      if( !dummyBuffer )
         return TA_ALLOC_ERR;

      retCode = TA_PREFIX(MAMA)( startIdx, endIdx, inReal, 0.5, 0.05,                           
                               outBegIdx, outNbElement,
                               outReal, dummyBuffer );
                         
      ARRAY_FREE( dummyBuffer );
      break;

   case TA_MAType_T3:
      retCode = TA_PREFIX(T3)( startIdx, endIdx, inReal,
                             optInTimePeriod, 0.7,
                             outBegIdx, outNbElement, outReal );
      break;

   default:
      retCode = TA_BAD_PARAM;
      break;
   }

   return retCode;
}

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum Core::TA_RetCode Core::MA( int    startIdx,
/* Generated */                                 int    endIdx,
/* Generated */                                 float        inReal __gc [],
/* Generated */                                 int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                 TA_MAType     optInMAType,
/* Generated */                                 [OutAttribute]Int32 *outBegIdx,
/* Generated */                                 [OutAttribute]Int32 *outNbElement,
/* Generated */                                 double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_MA( int    startIdx,
/* Generated */                     int    endIdx,
/* Generated */                     const float  inReal[],
/* Generated */                     int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                     TA_MAType     optInMAType,
/* Generated */                     int          *outBegIdx,
/* Generated */                     int          *outNbElement,
/* Generated */                     double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    ARRAY_REF(dummyBuffer);
/* Generated */    TA_RetCode retCode;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if( !inReal ) return TA_BAD_PARAM;
/* Generated */     if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInTimePeriod = 30;
/* Generated */     else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED)
/* Generated */     if( (int)optInMAType == TA_INTEGER_DEFAULT )
/* Generated */        optInMAType = 0;
/* Generated */     else if( ((int)optInMAType < 0) || ((int)optInMAType > 8) )
/* Generated */        return TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     if( outReal == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    switch( optInMAType )
/* Generated */    {
/* Generated */    case TA_MAType_SMA:
/* Generated */       retCode = TA_PREFIX(INT_SMA)( startIdx, endIdx, inReal, optInTimePeriod,
/* Generated */                                   outBegIdx, outNbElement, outReal );
/* Generated */       break;
/* Generated */    case TA_MAType_EMA:
/* Generated */       retCode = TA_PREFIX(INT_EMA)( startIdx, endIdx, inReal,
/* Generated */                                   optInTimePeriod, PER_TO_K(optInTimePeriod),
/* Generated */                                   outBegIdx, outNbElement, outReal );
/* Generated */       break;
/* Generated */    case TA_MAType_WMA:
/* Generated */       retCode = TA_PREFIX(WMA)( startIdx, endIdx, inReal, optInTimePeriod,
/* Generated */                               outBegIdx, outNbElement, outReal );
/* Generated */       break;
/* Generated */    case TA_MAType_DEMA:
/* Generated */       retCode = TA_PREFIX(DEMA)( startIdx, endIdx, inReal, optInTimePeriod,
/* Generated */                                outBegIdx, outNbElement, outReal );
/* Generated */       break;
/* Generated */    case TA_MAType_TEMA:
/* Generated */       retCode = TA_PREFIX(TEMA)( startIdx, endIdx, inReal, optInTimePeriod,
/* Generated */                                outBegIdx, outNbElement, outReal );
/* Generated */       break;
/* Generated */    case TA_MAType_TRIMA:
/* Generated */       retCode = TA_PREFIX(TRIMA)( startIdx, endIdx, inReal, optInTimePeriod,
/* Generated */                                 outBegIdx, outNbElement, outReal );
/* Generated */       break;
/* Generated */    case TA_MAType_KAMA:
/* Generated */       retCode = TA_PREFIX(KAMA)( startIdx, endIdx, inReal, optInTimePeriod,
/* Generated */                                outBegIdx, outNbElement, outReal );
/* Generated */       break;
/* Generated */    case TA_MAType_MAMA:
/* Generated */       ARRAY_ALLOC(dummyBuffer, (endIdx-startIdx+1) );
/* Generated */       if( !dummyBuffer )
/* Generated */          return TA_ALLOC_ERR;
/* Generated */       retCode = TA_PREFIX(MAMA)( startIdx, endIdx, inReal, 0.5, 0.05,                           
/* Generated */                                outBegIdx, outNbElement,
/* Generated */                                outReal, dummyBuffer );
/* Generated */       ARRAY_FREE( dummyBuffer );
/* Generated */       break;
/* Generated */    case TA_MAType_T3:
/* Generated */       retCode = TA_PREFIX(T3)( startIdx, endIdx, inReal,
/* Generated */                              optInTimePeriod, 0.7,
/* Generated */                              outBegIdx, outNbElement, outReal );
/* Generated */       break;
/* Generated */    default:
/* Generated */       retCode = TA_BAD_PARAM;
/* Generated */       break;
/* Generated */    }
/* Generated */    return retCode;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

