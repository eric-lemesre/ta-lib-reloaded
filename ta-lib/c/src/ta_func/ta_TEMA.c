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
 *
 */

#include "ta_memory.h"

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */

#ifndef TA_FUNC_H
   #include "ta_func.h"
#endif

#ifndef TA_UTILITY_H
   #include "ta_utility.h"
#endif

int TA_TEMA_Lookback( int           optInTimePeriod_0 )  /* From 2 to TA_INTEGER_MAX */

/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* Get lookack for one EMA. */
   int retValue = TA_EMA_Lookback( optInTimePeriod_0 );

   return retValue * 3;
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_TEMA - Triple Exponential Moving Average
 * 
 * Input  = double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod_0:(From 2 to TA_INTEGER_MAX)
 *    Number of period
 * 
 * 
 */

TA_RetCode TA_TEMA( int    startIdx,
                    int    endIdx,
                    const double inReal_0[],
                    int           optInTimePeriod_0, /* From 2 to TA_INTEGER_MAX */
                    int          *outBegIdx,
                    int          *outNbElement,
                    double        outReal_0[] )
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   double *firstEMA, *secondEMA;
   double k;

   TA_Integer firstEMABegIdx, firstEMANbElement;
   TA_Integer secondEMABegIdx, secondEMANbElement;
   TA_Integer thirdEMABegIdx, thirdEMANbElement;
   TA_Integer tempInt, outIdx, lookbackTotal, lookbackEMA;
   TA_Integer firstEMAIdx, secondEMAIdx;

   TA_RetCode retCode;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   if( !inReal_0 ) return TA_BAD_PARAM;
   /* min/max are checked for optInTimePeriod_0. */
   if( (int)optInTimePeriod_0 == TA_INTEGER_DEFAULT )
      optInTimePeriod_0 = 30;
   else if( ((int)optInTimePeriod_0 < 2) || ((int)optInTimePeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   if( outReal_0 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* For an explanation of this function, please read:
    * 
    * Stocks & Commodities V. 12:1 (11-19): 
    *   Smoothing Data With Faster Moving Averages
    * Stocks & Commodities V. 12:2 (72-80): 
    *   Smoothing Data With Less Lag
    *
    * Both magazine articles written by Patrick G. Mulloy
    *
    * Essentially, a TEMA of time serie 't' is:
    *   EMA1 = EMA(t,period)
    *   EMA2 = EMA(EMA(t,period),period)
    *   EMA3 = EMA(EMA(EMA(t,period),period))
    *   TEMA = 3*EMA1 - 3*EMA2 + EMA3
    *
    * TEMA offers a moving average with less lags then the
    * traditional EMA.
    *
    * Do not confuse a TEMA with EMA3. Both are called "Triple EMA"
    * in the litterature.
    *
    * DEMA is very similar (and from the same author).
    */

   /* Will change only on success. */
   *outNbElement = 0;
   *outBegIdx    = 0;

   /* Adjust startIdx to account for the lookback period. */
   lookbackEMA = TA_EMA_Lookback( optInTimePeriod_0 );
   lookbackTotal = lookbackEMA * 3;

   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
      return TA_SUCCESS; 

   /* Allocate a temporary buffer for the firstEMA. */
   tempInt = lookbackTotal+(endIdx-startIdx)+1;
   firstEMA = (double *)TA_Malloc( tempInt * sizeof( double) );
   if( !firstEMA )
      return TA_ALLOC_ERR;

   /* Calculate the first EMA */   
   k = PER_TO_K(optInTimePeriod_0);
   retCode = TA_INT_EMA( startIdx-(lookbackEMA*2), endIdx, inReal_0,
                         optInTimePeriod_0, k,
                         &firstEMABegIdx, &firstEMANbElement, firstEMA );
   
   /* Verify for failure or if not enough data after
    * calculating the first EMA.
    */
   if( (retCode != TA_SUCCESS) || (firstEMANbElement == 0) )
   {
      TA_Free(  firstEMA );
      return retCode;
   }

   /* Allocate a temporary buffer for storing the EMA2 */
   secondEMA = (double *)TA_Malloc( firstEMANbElement * sizeof( double) );

   if( !secondEMA )
   {
      TA_Free(  firstEMA );
      return TA_ALLOC_ERR;
   }

   retCode = TA_INT_EMA( 0, firstEMANbElement-1, firstEMA,
                         optInTimePeriod_0, k,
                         &secondEMABegIdx, &secondEMANbElement, secondEMA );

   /* Return empty output on failure or if not enough data after
    * calculating the second EMA.
    */
   if( (retCode != TA_SUCCESS) || (secondEMANbElement == 0) )      
   {
      TA_Free(  firstEMA );
      TA_Free(  secondEMA );
      return retCode;
   }

   /* Calculate the EMA3 into the caller provided output. */
   retCode = TA_INT_EMA( 0, secondEMANbElement-1, secondEMA,
                         optInTimePeriod_0, k,
                         &thirdEMABegIdx, &thirdEMANbElement,
                         outReal_0 );

   /* Return empty output on failure or if not enough data after
    * calculating the third EMA.
    */
   if( (retCode != TA_SUCCESS) || (thirdEMANbElement == 0) )
   {
      TA_Free(  firstEMA );
      TA_Free(  secondEMA );
      return retCode;
   }


   /* Indicate where the output starts relative to
    * the caller input.
    */
   firstEMAIdx  = thirdEMABegIdx + secondEMABegIdx;
   secondEMAIdx = thirdEMABegIdx;
   *outBegIdx    = firstEMAIdx + firstEMABegIdx;

   /* Do the TEMA:
    *  Iterate through the EMA3 (output buffer) and adjust
    *  the value by using the EMA2 and EMA1.
    */
   outIdx = 0;
   while( outIdx < thirdEMANbElement ) 
   {
      outReal_0[outIdx] += (3.0*firstEMA[firstEMAIdx++]) - (3.0*secondEMA[secondEMAIdx++]);
      outIdx++;
   }

   TA_Free(  firstEMA );
   TA_Free(  secondEMA );

   /* Indicates to the caller the number of output
    * successfully calculated.
    */
   *outNbElement = outIdx;

   return TA_SUCCESS;
}


