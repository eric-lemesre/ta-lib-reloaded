/* TA-LIB Copyright (c) 1999-2004, Mario Fortier
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
 *  120802 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *  062704 MF   Fix limit case to avoid divid by zero (or by
 *              a value close to zero induce by the imprecision
 *              of floating points).
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
/* Generated */ int Core::KAMA_Lookback( int           optInTimePeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_KAMA_Lookback( int           optInTimePeriod )  /* From 2 to 100000 */
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   return optInTimePeriod + TA_Globals->unstablePeriod[TA_FUNC_UNST_KAMA];
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_KAMA - Kaufman Adaptive Moving Average
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
/* Generated */ enum Core::TA_RetCode Core::KAMA( int    startIdx,
/* Generated */                                   int    endIdx,
/* Generated */                                   double       inReal __gc [],
/* Generated */                                   int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                   [OutAttribute]Int32 *outBegIdx,
/* Generated */                                   [OutAttribute]Int32 *outNbElement,
/* Generated */                                   double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_KAMA( int    startIdx,
/* Generated */                     int    endIdx,
/* Generated */                     const double inReal[],
/* Generated */                     int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                     int          *outBegIdx,
/* Generated */                     int          *outNbElement,
/* Generated */                     double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */

   const double constMax  = 2.0/(30.0+1.0);
   const double constDiff = 2.0/(2.0+1.0) - constMax;

   double tempReal, tempReal2;
   double sumROC1, periodROC, prevKAMA;
   int i, today, outIdx, lookbackTotal;
   int trailingIdx;
   double trailingValue;

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
/* Generated */    if( outReal == NULL )
/* Generated */       return TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Default return values */
   *outBegIdx    = 0;
   *outNbElement = 0;

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */
   lookbackTotal = optInTimePeriod + TA_Globals->unstablePeriod[TA_FUNC_UNST_KAMA];

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      *outBegIdx = 0;
      *outNbElement = 0;
      return TA_SUCCESS;
   }
      
   /* Initialize the variables by going through
    * the lookback period.
    */
   sumROC1 = 0.0;
   today = startIdx-lookbackTotal;   
   trailingIdx = today;
   i = optInTimePeriod;
   while( i-- > 0 )
   {      
      tempReal  = inReal[today++];
      tempReal -= inReal[today];
      sumROC1  += fabs(tempReal);
   }

   /* At this point sumROC1 represent the 
    * summation of the 1-day price difference
    * over the (optInTimePeriod-1)
    */

   /* Calculate the first KAMA */

   /* The yesterday price is used here as the previous KAMA. */
   prevKAMA = inReal[today-1];

   tempReal  = inReal[today];
   tempReal2 = inReal[trailingIdx++];
   periodROC = tempReal-tempReal2;

   /* Save the trailing value. Do this because inReal
    * and outReal can be pointers to the same buffer. 
    */
   trailingValue = tempReal2;

   /* Calculate the efficiency ratio */
   if( (sumROC1 <= periodROC) || TA_IS_ZERO(sumROC1))
      tempReal = 1.0;
   else
      tempReal = fabs(periodROC/sumROC1);

   /* Calculate the smoothing constant */
   tempReal  = (tempReal*constDiff)+constMax;
   tempReal *= tempReal;

   /* Calculate the KAMA like an EMA, using the
    * smoothing constant as the adaptive factor.
    */
   prevKAMA = ((inReal[today++]-prevKAMA)*tempReal) + prevKAMA;

   /* 'today' keep track of where the processing is within the
    * input.
    */

   /* Skip the unstable period. Do the whole processing 
    * needed for KAMA, but do not write it in the output.
    */   
   while( today <= startIdx )
   {
      tempReal  = inReal[today];
      tempReal2 = inReal[trailingIdx++];
      periodROC = tempReal-tempReal2;

      /* Adjust sumROC1:
       *  - Remove trailing ROC1 
       *  - Add new ROC1
       */
      sumROC1 -= fabs(trailingValue-tempReal2);
      sumROC1 += fabs(tempReal-inReal[today-1]);

      /* Save the trailing value. Do this because inReal
       * and outReal can be pointers to the same buffer. 
       */
      trailingValue = tempReal2;

      /* Calculate the efficiency ratio */
      if( (sumROC1 <= periodROC) || TA_IS_ZERO(sumROC1) )
         tempReal = 1.0;
      else
         tempReal = fabs(periodROC/sumROC1);

      /* Calculate the smoothing constant */
      tempReal  = (tempReal*constDiff)+constMax;
      tempReal *= tempReal;

      /* Calculate the KAMA like an EMA, using the
       * smoothing constant as the adaptive factor.
       */
      prevKAMA = ((inReal[today++]-prevKAMA)*tempReal) + prevKAMA;
   }

   /* Write the first value. */
   outReal[0] = prevKAMA;
   outIdx = 1;
   *outBegIdx = today-1;

   /* Do the KAMA calculation for the requested range. */
   while( today <= endIdx )
   {
      tempReal  = inReal[today];
      tempReal2 = inReal[trailingIdx++];
      periodROC = tempReal-tempReal2;

      /* Adjust sumROC1:
       *  - Remove trailing ROC1 
       *  - Add new ROC1
       */
      sumROC1 -= fabs(trailingValue-tempReal2);
      sumROC1 += fabs(tempReal-inReal[today-1]);

      /* Save the trailing value. Do this because inReal
       * and outReal can be pointers to the same buffer. 
       */
      trailingValue = tempReal2;

      /* Calculate the efficiency ratio */
      if( (sumROC1 <= periodROC) || TA_IS_ZERO(sumROC1) )
         tempReal = 1.0;
      else
         tempReal = fabs(periodROC / sumROC1);

      /* Calculate the smoothing constant */
      tempReal  = (tempReal*constDiff)+constMax;
      tempReal *= tempReal;

      /* Calculate the KAMA like an EMA, using the
       * smoothing constant as the adaptive factor.
       */
      prevKAMA = ((inReal[today++]-prevKAMA)*tempReal) + prevKAMA;
      outReal[outIdx++] = prevKAMA;
   }

   *outNbElement = outIdx;

   return TA_SUCCESS;
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
/* Generated */ enum Core::TA_RetCode Core::KAMA( int    startIdx,
/* Generated */                                   int    endIdx,
/* Generated */                                   float        inReal __gc [],
/* Generated */                                   int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                                   [OutAttribute]Int32 *outBegIdx,
/* Generated */                                   [OutAttribute]Int32 *outNbElement,
/* Generated */                                   double        outReal __gc [] )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_KAMA( int    startIdx,
/* Generated */                       int    endIdx,
/* Generated */                       const float  inReal[],
/* Generated */                       int           optInTimePeriod, /* From 2 to 100000 */
/* Generated */                       int          *outBegIdx,
/* Generated */                       int          *outNbElement,
/* Generated */                       double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    const double constMax  = 2.0/(30.0+1.0);
/* Generated */    const double constDiff = 2.0/(2.0+1.0) - constMax;
/* Generated */    double tempReal, tempReal2;
/* Generated */    double sumROC1, periodROC, prevKAMA;
/* Generated */    int i, today, outIdx, lookbackTotal;
/* Generated */    int trailingIdx;
/* Generated */    double trailingValue;
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
/* Generated */     if( outReal == NULL )
/* Generated */        return TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    *outBegIdx    = 0;
/* Generated */    *outNbElement = 0;
/* Generated */    lookbackTotal = optInTimePeriod + TA_Globals->unstablePeriod[TA_FUNC_UNST_KAMA];
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       *outBegIdx = 0;
/* Generated */       *outNbElement = 0;
/* Generated */       return TA_SUCCESS;
/* Generated */    }
/* Generated */    sumROC1 = 0.0;
/* Generated */    today = startIdx-lookbackTotal;   
/* Generated */    trailingIdx = today;
/* Generated */    i = optInTimePeriod;
/* Generated */    while( i-- > 0 )
/* Generated */    {      
/* Generated */       tempReal  = inReal[today++];
/* Generated */       tempReal -= inReal[today];
/* Generated */       sumROC1  += fabs(tempReal);
/* Generated */    }
/* Generated */    prevKAMA = inReal[today-1];
/* Generated */    tempReal  = inReal[today];
/* Generated */    tempReal2 = inReal[trailingIdx++];
/* Generated */    periodROC = tempReal-tempReal2;
/* Generated */    trailingValue = tempReal2;
/* Generated */    if( (sumROC1 <= periodROC) || (sumROC1 == 0.0) )
/* Generated */       tempReal = 1.0;
/* Generated */    else
/* Generated */       tempReal = fabs(periodROC/sumROC1);
/* Generated */    tempReal  = (tempReal*constDiff)+constMax;
/* Generated */    tempReal *= tempReal;
/* Generated */    prevKAMA = ((inReal[today++]-prevKAMA)*tempReal) + prevKAMA;
/* Generated */    while( today <= startIdx )
/* Generated */    {
/* Generated */       tempReal  = inReal[today];
/* Generated */       tempReal2 = inReal[trailingIdx++];
/* Generated */       periodROC = tempReal-tempReal2;
/* Generated */       sumROC1 -= fabs(trailingValue-tempReal2);
/* Generated */       sumROC1 += fabs(tempReal-inReal[today-1]);
/* Generated */       trailingValue = tempReal2;
/* Generated */       if( (sumROC1 <= periodROC) || (sumROC1 == 0.0) )
/* Generated */          tempReal = 1.0;
/* Generated */       else
/* Generated */          tempReal = fabs(periodROC/sumROC1);
/* Generated */       tempReal  = (tempReal*constDiff)+constMax;
/* Generated */       tempReal *= tempReal;
/* Generated */       prevKAMA = ((inReal[today++]-prevKAMA)*tempReal) + prevKAMA;
/* Generated */    }
/* Generated */    outReal[0] = prevKAMA;
/* Generated */    outIdx = 1;
/* Generated */    *outBegIdx = today-1;
/* Generated */    while( today <= endIdx )
/* Generated */    {
/* Generated */       tempReal  = inReal[today];
/* Generated */       tempReal2 = inReal[trailingIdx++];
/* Generated */       periodROC = tempReal-tempReal2;
/* Generated */       sumROC1 -= fabs(trailingValue-tempReal2);
/* Generated */       sumROC1 += fabs(tempReal-inReal[today-1]);
/* Generated */       trailingValue = tempReal2;
/* Generated */       if( (sumROC1 <= periodROC) || (sumROC1 == 0.0) )
/* Generated */          tempReal = 1.0;
/* Generated */       else
/* Generated */          tempReal = fabs(periodROC / sumROC1);
/* Generated */       tempReal  = (tempReal*constDiff)+constMax;
/* Generated */       tempReal *= tempReal;
/* Generated */       prevKAMA = ((inReal[today++]-prevKAMA)*tempReal) + prevKAMA;
/* Generated */       outReal[outIdx++] = prevKAMA;
/* Generated */    }
/* Generated */    *outNbElement = outIdx;
/* Generated */    return TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

