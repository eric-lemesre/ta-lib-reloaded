/* TA-LIB Copyright (c) 1999-2002, Mario Fortier
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

int TA_APO_Lookback( TA_Integer    optInFastPeriod_0, /* From 1 to TA_INTEGER_MAX */
                     TA_Integer    optInSlowPeriod_1, /* From 1 to TA_INTEGER_MAX */
                     TA_Integer    optInMethod_2,
                     TA_Integer    optInCompatibility_3 ) 
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
   (void)optInFastPeriod_0;

   /* The slow MA is the key factor determining the lookback period. */
   return TA_MA_Lookback( optInSlowPeriod_1, optInMethod_2, optInCompatibility_3 );
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_APO - Absolute Price Oscillator
 * 
 * Input  = TA_Real
 * Output = TA_Real
 * 
 * Optional Parameters
 * -------------------
 * optInFastPeriod_0:(From 1 to TA_INTEGER_MAX)
 *    Number of period for the fast MA
 * 
 * optInSlowPeriod_1:(From 1 to TA_INTEGER_MAX)
 *    Number of period for the slow MA
 * 
 * optInMethod_2:
 *    Define technique used for calculation
 * 
 * optInCompatibility_3:
 *    Make function compatible to some software
 * 
 * 
 */

TA_RetCode TA_APO( TA_Libc      *libHandle,
                   TA_Integer    startIdx,
                   TA_Integer    endIdx,
                   const TA_Real inReal_0[],
                   TA_Integer    optInFastPeriod_0, /* From 1 to TA_INTEGER_MAX */
                   TA_Integer    optInSlowPeriod_1, /* From 1 to TA_INTEGER_MAX */
                   TA_Integer    optInMethod_2,
                   TA_Integer    optInCompatibility_3,
                   TA_Integer   *outBegIdx,
                   TA_Integer   *outNbElement,
                   TA_Real       outReal_0[] )
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   TA_Real *tempBuffer;
   TA_RetCode retCode;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   (void)libHandle; /* Get ride of warning if unused. */

#ifndef TA_FUNC_NO_RANGE_CHECK

   /* Validate the requested output range. */
   if( startIdx < 0 )
      return TA_OUT_OF_RANGE_START_INDEX;
   if( (endIdx < 0) || (endIdx < startIdx))
      return TA_OUT_OF_RANGE_END_INDEX;

   /* Validate the parameters. */
   if( !inReal_0 ) return TA_BAD_PARAM;
   /* min/max are checked for optInFastPeriod_0. */
   if( optInFastPeriod_0 == TA_INTEGER_DEFAULT )
      optInFastPeriod_0 = 12;
   else if( (optInFastPeriod_0 < 1) || (optInFastPeriod_0 > 2147483647) )
      return TA_BAD_PARAM;

   /* min/max are checked for optInSlowPeriod_1. */
   if( optInSlowPeriod_1 == TA_INTEGER_DEFAULT )
      optInSlowPeriod_1 = 26;
   else if( (optInSlowPeriod_1 < 1) || (optInSlowPeriod_1 > 2147483647) )
      return TA_BAD_PARAM;

   if( optInMethod_2 == TA_INTEGER_DEFAULT )
      optInMethod_2 = 0;
   else if( (optInMethod_2 < 0) || (optInMethod_2 > 4) )
      return TA_BAD_PARAM;

   if( optInCompatibility_3 == TA_INTEGER_DEFAULT )
      optInCompatibility_3 = 0;
   else if( (optInCompatibility_3 < 0) || (optInCompatibility_3 > 1) )
      return TA_BAD_PARAM;

   if( outReal_0 == NULL )
      return TA_BAD_PARAM;

#endif /* TA_FUNC_NO_RANGE_CHECK */

/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Allocate an intermediate buffer. */
   tempBuffer = TA_Malloc( libHandle, (endIdx-startIdx+1)*sizeof(TA_Real) );
   if( !tempBuffer )
      return TA_ALLOC_ERR;

   retCode = TA_INT_PO( libHandle,
                        startIdx, endIdx,                        
                        inReal_0,
                        optInFastPeriod_0, /* From 1 to 200 */
                        optInSlowPeriod_1, /* From 1 to 200 */
                        optInMethod_2,
                        optInCompatibility_3,                        
                        outBegIdx,
                        outNbElement,
                        outReal_0,
                        tempBuffer,
                        0 /* No percentage. */ );

   TA_Free( libHandle, tempBuffer );

   return retCode;
}


/* Internal price oscillator function.
 *
 * A buffer must be provided for intermediate processing.
 */
TA_RetCode TA_INT_PO( TA_Libc      *libHandle,
                      TA_Integer    startIdx,
                      TA_Integer    endIdx,
                      const TA_Real *inReal_0,
                      TA_Integer    optInFastPeriod_0, /* From 1 to 200 */
                      TA_Integer    optInSlowPeriod_1, /* From 1 to 200 */
                      TA_Integer    optInMethod_2,
                      TA_Integer    optInCompatibility_3,
                      TA_Integer   *outBegIdx,
                      TA_Integer   *outNbElement,
                      TA_Real      *outReal_0,
                      TA_Real      *tempBuffer,
                      unsigned int  doPercentageOutput )
{
   TA_RetCode retCode;

   TA_Integer tempInteger;
   TA_Integer outBegIdx1, outNbElement1;
   TA_Integer outBegIdx2, outNbElement2;

   TA_Integer i, j;

   /* Make sure slow is really slower than
    * the fast period! if not, swap...
    */
   if( optInSlowPeriod_1 < optInFastPeriod_0 )
   {
       /* swap */
       tempInteger       = optInSlowPeriod_1;
       optInSlowPeriod_1 = optInFastPeriod_0;
       optInFastPeriod_0 = tempInteger;
   }

   /* Calculate the slow MA into the temp buffer. */
   retCode = TA_MA( libHandle,
                    startIdx, endIdx,
                    inReal_0,
                    optInSlowPeriod_1, /* From 1 to 200 */
                    optInMethod_2,
                    optInCompatibility_3,
                    &outBegIdx1, &outNbElement1, tempBuffer );

   if( retCode == TA_SUCCESS )
   {
      /* Calculate the fast MA into the output. */
      retCode = TA_MA( libHandle,
                       startIdx, endIdx,
                       inReal_0,
                       optInFastPeriod_0, /* From 1 to 200 */
                       optInMethod_2,
                       optInCompatibility_3,
                       &outBegIdx2, &outNbElement2, outReal_0 );

      if( retCode == TA_SUCCESS )
      {
         tempInteger = outBegIdx1 - outBegIdx2;
         if( doPercentageOutput )
         {
            /* Calculate ((fast MA)-(slow MA))/(slow MA) in the output. */   
            for( i=0,j=tempInteger; i < outNbElement1; i++, j++ )
               outReal_0[i] = ((outReal_0[j]-tempBuffer[i])/tempBuffer[i])*100;
         }
         else
         {
            /* Calculate (fast MA)-(slow MA) in the output. */   
            for( i=0,j=tempInteger; i < outNbElement1; i++, j++ )
               outReal_0[i] = outReal_0[j]-tempBuffer[i];
         }

         *outBegIdx     = outBegIdx1;
         *outNbElement  = outNbElement1;
      }
   }

   if( retCode != TA_SUCCESS )
   {
      *outBegIdx     = 0;
      *outNbElement  = 0;
   }

   return retCode;
}



