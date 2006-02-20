/* TA-LIB Copyright (c) 1999-2006, Mario Fortier
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
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *
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
/* Generated */ int Core::WMA_Lookback( int           optInTimePeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #elif defined( _JAVA )
/* Generated */ public int WMA_Lookback( int           optInTimePeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_WMA_Lookback( int           optInTimePeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert local variable here */

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 30;
/* Generated */    else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */       return -1;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/

   /* insert lookback code here. */
   return optInTimePeriod - 1;
}

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/*
 * TA_WMA - Weighted Moving Average
 * 
 * Input  = double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod:(From 2 to 100000)
 *    Number of period
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::WMA( int    startIdx,
/* Generated */                                        int    endIdx,
/* Generated */                                        cli::array<double>^ inReal,
/* Generated */                                        int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                        [Out]int%    outBegIdx,
/* Generated */                                        [Out]int%    outNbElement,
/* Generated */                                        cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode WMA( int    startIdx,
/* Generated */                        int    endIdx,
/* Generated */                        double       inReal[],
/* Generated */                        int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                        MInteger     outBegIdx,
/* Generated */                        MInteger     outNbElement,
/* Generated */                        double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_WMA( int    startIdx,
/* Generated */                    int    endIdx,
/* Generated */                    const double inReal[],
/* Generated */                    int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                    int          *outBegIdx,
/* Generated */                    int          *outNbElement,
/* Generated */                    double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   int inIdx, outIdx, i, trailingIdx, divider;
   double periodSum, periodSub, tempReal, trailingValue;
   int lookbackTotal;

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA)*/
/* Generated */    /* min/max are checked for optInTimePeriod. */
/* Generated */    if( (int)optInTimePeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInTimePeriod = 30;
/* Generated */    else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */    if( !outReal )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) && !defined(_JAVA) */
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */
   lookbackTotal = optInTimePeriod-1;

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      return NAMESPACE(TA_RetCode)TA_SUCCESS;
   }

   /* To make the rest more efficient, handle exception
    * case where the user is asking for a period of '1'.
    * In that case outputs equals inputs for the requested
    * range.
    */
   if( optInTimePeriod == 1 ) 
   {      
      VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;
      VALUE_HANDLE_DEREF(outNbElement) = endIdx-startIdx+1;
      ARRAY_MEMMOVE( outReal, 0, inReal, startIdx, (int)VALUE_HANDLE_DEREF(outNbElement) );	  	  
      return NAMESPACE(TA_RetCode)TA_SUCCESS;
   }

   /* Calculate the divider (always an integer value).
    * By induction: 1+2+3+4+'n' = n(n+1)/2
    * '>>1' is usually faster than '/2' for unsigned.
    */
   divider = (optInTimePeriod*(optInTimePeriod+1))>>1;

   /* The algo used here use a very basic property of
    * multiplication/addition: (x*2) = x+x
    *   
    * As an example, a 3 period weighted can be 
    * interpreted in two way:
    *  (x1*1)+(x2*2)+(x3*3)
    *      OR
    *  x1+x2+x2+x3+x3+x3 (this is the periodSum)
    *   
    * When you move forward in the time serie
    * you can quickly adjust the periodSum for the
    * period by substracting:
    *   x1+x2+x3 (This is the periodSub)
    * Making the new periodSum equals to:
    *   x2+x3+x3
    *
    * You can then add the new price bar
    * which is x4+x4+x4 giving:
    *   x2+x3+x3+x4+x4+x4
    *
    * At this point one iteration is completed and you can
    * see that we are back to the step 1 of this example.
    *
    * Why making it so un-intuitive? The number of memory
    * access and floating point operations are kept to a
    * minimum with this algo.
    */
   outIdx      = 0;
   trailingIdx = startIdx - lookbackTotal;

   /* Evaluate the initial periodSum/periodSub and trailingValue. */
   periodSum = periodSub = (double)0.0;
   inIdx=trailingIdx;
   i = 1;
   while( inIdx < startIdx )
   {
      tempReal = inReal[inIdx++];
      periodSub += tempReal;
      periodSum += tempReal*i;
      i++;
   }
   trailingValue = 0.0;

   /* Tight loop for the requested range. */
   while( inIdx <= endIdx )
   {
      /* Add the current price bar to the sum
       * who are carried through the iterations.
       */
      tempReal = inReal[inIdx++];
      periodSub += tempReal;
      periodSub -= trailingValue;
      periodSum += tempReal*optInTimePeriod;

      /* Save the trailing value for being substract at
       * the next iteration.
       * (must be saved here just in case outReal and
       *  inReal are the same buffer).
       */
      trailingValue = inReal[trailingIdx++];

      /* Calculate the WMA for this price bar. */
      outReal[outIdx++] = periodSum / divider;

      /* Prepare the periodSum for the next iteration. */
      periodSum -= periodSub;
   }

   /* Set output limits. */
   VALUE_HANDLE_DEREF(outNbElement) = outIdx;
   VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;

   return NAMESPACE(TA_RetCode)TA_SUCCESS;
}

/**** START GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED ) && !defined( _JAVA )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::WMA( int    startIdx,
/* Generated */                                        int    endIdx,
/* Generated */                                        cli::array<float>^ inReal,
/* Generated */                                        int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                        [Out]int%    outBegIdx,
/* Generated */                                        [Out]int%    outNbElement,
/* Generated */                                        cli::array<double>^  outReal )
/* Generated */ #elif defined( _JAVA )
/* Generated */ public TA_RetCode WMA( int    startIdx,
/* Generated */                        int    endIdx,
/* Generated */                        float        inReal[],
/* Generated */                        int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                        MInteger     outBegIdx,
/* Generated */                        MInteger     outNbElement,
/* Generated */                        double        outReal[] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_WMA( int    startIdx,
/* Generated */                      int    endIdx,
/* Generated */                      const float  inReal[],
/* Generated */                      int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                      int          *outBegIdx,
/* Generated */                      int          *outNbElement,
/* Generated */                      double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    int inIdx, outIdx, i, trailingIdx, divider;
/* Generated */    double periodSum, periodSub, tempReal, trailingValue;
/* Generated */    int lookbackTotal;
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
/* Generated */     else if( ((int)optInTimePeriod < 2) || ((int)optInTimePeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED) && !defined(_JAVA)
/* Generated */     if( !outReal )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */  #endif 
/* Generated */    lookbackTotal = optInTimePeriod-1;
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */    }
/* Generated */    if( optInTimePeriod == 1 ) 
/* Generated */    {      
/* Generated */       VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;
/* Generated */       VALUE_HANDLE_DEREF(outNbElement) = endIdx-startIdx+1;
/* Generated */       ARRAY_MEMMOVE( outReal, 0, inReal, startIdx, (int)VALUE_HANDLE_DEREF(outNbElement) );	  	  
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */    }
/* Generated */    divider = (optInTimePeriod*(optInTimePeriod+1))>>1;
/* Generated */    outIdx      = 0;
/* Generated */    trailingIdx = startIdx - lookbackTotal;
/* Generated */    periodSum = periodSub = (double)0.0;
/* Generated */    inIdx=trailingIdx;
/* Generated */    i = 1;
/* Generated */    while( inIdx < startIdx )
/* Generated */    {
/* Generated */       tempReal = inReal[inIdx++];
/* Generated */       periodSub += tempReal;
/* Generated */       periodSum += tempReal*i;
/* Generated */       i++;
/* Generated */    }
/* Generated */    trailingValue = 0.0;
/* Generated */    while( inIdx <= endIdx )
/* Generated */    {
/* Generated */       tempReal = inReal[inIdx++];
/* Generated */       periodSub += tempReal;
/* Generated */       periodSub -= trailingValue;
/* Generated */       periodSum += tempReal*optInTimePeriod;
/* Generated */       trailingValue = inReal[trailingIdx++];
/* Generated */       outReal[outIdx++] = periodSum / divider;
/* Generated */       periodSum -= periodSub;
/* Generated */    }
/* Generated */    VALUE_HANDLE_DEREF(outNbElement) = outIdx;
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;
/* Generated */    return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 5 - DO NOT DELETE THIS LINE ****/

