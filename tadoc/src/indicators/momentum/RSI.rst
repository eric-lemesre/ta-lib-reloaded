=============================
Relative Strength Index (RSI)
=============================

Type
----
Momentum indicator

Short description
-----------------


Description
-----------

The relative strength index (RSI) is a momentum indicator used in technical analysis. 
RSI measures the speed and magnitude of a security's recent price changes to evaluate 
overvalued or undervalued conditions in the price of that security.

The RSI is displayed as an oscillator (a line graph) on a scale of zero to 100. 
The indicator was developed by J. Welles Wilder Jr. and introduced in his seminal 1978 book, 
New Concepts in Technical Trading Systems.1

The RSI can do more than point to overbought and oversold securities. 
It can also indicate securities that may be primed for a trend reversal or 
corrective pullback in price. It can signal when to buy and sell. Traditionally, 
an RSI reading of 70 or above indicates an overbought situation. 
A reading of 30 or below indicates an oversold condition. 

Common code
-----------
RSI 

Calculation
-----------

The RSI uses a two-part calculation that starts with the following formula: 

The average gain or loss used in this calculation is the average percentage gain or 
loss during a look-back period. The formula uses a positive value for the average loss. 
Periods with price losses are counted as zero in the calculations of average gain. 
Periods with price increases are counted as zero in the calculations of average loss.

The standard number of periods used to calculate the initial RSI value is 14. 
For example, imagine the market closed higher seven out of the past 14 days with 
an average gain of 1%. The remaining seven days all closed lower with an average loss of −0.8%.

The first calculation for the RSI would look like the following expanded calculation: 

Once there are 14 periods of data available, the second calculation can be done. 
Its purpose is to smooth the results so that the RSI only nears 100 or zero in a strongly 
trending market.

Explanation
-----------

As a momentum indicator, the relative strength index compares a security's strength on days 
when prices go up to its strength on days when prices go down. Relating the result of 
this comparison to price action can give traders an idea of how a security may perform. 
The RSI, used in conjunction with other technical indicators, can help traders make 
better-informed trading decisions. 

Analyse
-------

* The relative strength index (RSI) is a popular momentum oscillator introduced in 1978.
* The RSI provides technical traders with signals about bullish and bearish price momentum, and it is often plotted beneath the graph of an asset’s price.
* An asset is usually considered overbought when the RSI is above 70 and oversold when it is below 30.
* The RSI line crossing below the overbought line or above oversold line is often seen by traders as a signal to buy or sell.
* The RSI works best in trading ranges rather than trending markets.

Implementation
--------------
link to TA implementation.

:doc:`TA_RSI <../functions/RSI.rst>`
