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
 *  120802 MF   Template creation.
 *
 */

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

int TA_MFI_Lookback( int           optInTimePeriod_0 )  /* From 2 to TA_INTEGER_MAX */

/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   return optInTimePeriod_0 + TA_Globals.unstablePeriod[TA_FUNC_UNST_MFI];
}

typedef struct
{
   double positive;
   double negative;
} MoneyFlow;


/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_MFI - Money Flow Index
 * 
 * Input  = High, Low, Close, Volume
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInTimePeriod_0:(From 2 to TA_INTEGER_MAX)
 *    Number of period
 * 
 * 
 */

TA_RetCode TA_MFI( int    startIdx,
                   int    endIdx,
                   const double inHigh_0[],
                   const double inLow_0[],
                   const double inClose_0[],
                   const int    inVolume_0[],
                   int           optInTimePeriod_0, /* From 2 to TA_INTEGER_MAX */
                   int          *outBegIdx,
                   int          *outNbElement,
                   double        outReal_0[] )
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
	/* insert local variable here */
   double posSumMF, negSumMF, prevValue;
   double tempValue1, tempValue2;
   int lookbackTotal, outIdx, i, today;

   CIRCBUF_PROLOG( mflow, MoneyFlow, 50 ); /* Id, Type, Static Size */
   
/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   /* Verify required price component. */
   if(!inHigh_0||!inLow_0||!inClose_0||!inVolume_0)
      return TA_BAD_PARAM;

   /* min/max are checked for optInTimePeriod_0. */
   if( (int)optInTimePeriod_0 == TA_INTEGER_DEFAULT )
      optInTimePeriod_0 = 14;
   else if( ((int)optInTimePeriod_0 < 2) || ((int)optInTimePeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   if( outReal_0 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   CIRCBUF_CONSTRUCT( mflow, MoneyFlow, optInTimePeriod_0 );

   *outBegIdx    = 0;
   *outNbElement = 0;
   
   /* Adjust startIdx to account for the lookback period. */
   lookbackTotal = optInTimePeriod_0 + TA_Globals.unstablePeriod[TA_FUNC_UNST_MFI];

   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      CIRCBUF_DESTROY(mflow);
      return TA_SUCCESS;
   }

   outIdx = 0; /* Index into the output. */

   /* Accumulate the positive and negative money flow
    * among the initial period.
    */
   today = startIdx-lookbackTotal;
   prevValue = (inHigh_0[today]+inLow_0[today]+inClose_0[today])/3.0;

   posSumMF = 0.0;
   negSumMF = 0.0;
   today++;
   for( i=optInTimePeriod_0; i > 0; i-- )
   {
      tempValue1 = (inHigh_0[today]+inLow_0[today]+inClose_0[today])/3.0;
      tempValue2 = tempValue1 - prevValue;
      prevValue  = tempValue1;
      tempValue1 *= inVolume_0[today++];
      if( tempValue2 < 0 )
      {
         mflow[mflow_Idx].negative = tempValue1;
         negSumMF += tempValue1;
         mflow[mflow_Idx].positive = 0.0;
      }
      else
      {
         mflow[mflow_Idx].positive = tempValue1;
         posSumMF += tempValue1;
         mflow[mflow_Idx].negative = 0.0;
      }

      CIRCBUF_NEXT(mflow);
   }
   
   /* The following two equations are equivalent:
    *    MFI = 100 - (100 / 1 + (posSumMF/negSumMF))
    *    MFI = 100 * (posSumMF/(posSumMF+negSumMF))
    * The second equation is used here for speed optimization.
    */
   if( today > startIdx )
      outReal_0[outIdx++] = 100.0*(posSumMF/(posSumMF+negSumMF));
   else
   {
      /* Skip the unstable period. Do the processing 
       * but do not write it in the output.
       */   
      while( today < startIdx )
      {
         posSumMF -= mflow[mflow_Idx].positive;
         negSumMF -= mflow[mflow_Idx].negative;

         tempValue1 = (inHigh_0[today]+inLow_0[today]+inClose_0[today])/3.0;
         tempValue2 = tempValue1 - prevValue;
         prevValue  = tempValue1;
         tempValue1 *= inVolume_0[today++];
         if( tempValue2 < 0 )
         {
            mflow[mflow_Idx].negative = tempValue1;
            negSumMF += tempValue1;
            mflow[mflow_Idx].positive = 0.0;
         }
         else
         {
            mflow[mflow_Idx].positive = tempValue1;
            posSumMF += tempValue1;
            mflow[mflow_Idx].negative = 0.0;
         }

         CIRCBUF_NEXT(mflow);
      }
   }

   /* Unstable period skipped... now continue
    * processing if needed.
    */
   while( today <= endIdx )
   {
      posSumMF -= mflow[mflow_Idx].positive;
      negSumMF -= mflow[mflow_Idx].negative;

      tempValue1 = (inHigh_0[today]+inLow_0[today]+inClose_0[today])/3.0;
      tempValue2 = tempValue1 - prevValue;
      prevValue  = tempValue1;
      tempValue1 *= inVolume_0[today++];
      if( tempValue2 < 0 )
      {
         mflow[mflow_Idx].negative = tempValue1;
         negSumMF += tempValue1;
         mflow[mflow_Idx].positive = 0.0;
      }
      else
      {
         mflow[mflow_Idx].positive = tempValue1;
         posSumMF += tempValue1;
         mflow[mflow_Idx].negative = 0.0;
      }

      outReal_0[outIdx++] = 100.0*(posSumMF/(posSumMF+negSumMF));

      CIRCBUF_NEXT(mflow);
   }

   CIRCBUF_DESTROY(mflow);

   *outBegIdx = startIdx;
   *outNbElement = outIdx;

   return TA_SUCCESS;
}

