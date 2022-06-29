==================
MACD (Moving Average Convergence Divergence)
==================

Type
----

Short description
-----------------


Description
-----------
Moving average convergence divergence (MACD) is a trend-following momentum indicator that shows the relationship
between two moving averages of a security’s price. The MACD is calculated by subtracting the 26-period exponential
moving average (EMA) from the 12-period EMA.

The result of that calculation is the MACD line. A nine-day EMA of the MACD called the "signal line,"
is then plotted on top of the MACD line, which can function as a trigger for buy and sell signals.
Traders may buy the security when the MACD crosses above its signal line and sell (or short) the security
when the MACD crosses below the signal line. Moving average convergence divergence (MACD) indicators can be interpreted
in several ways, but the more common methods are crossovers, divergences, and rapid rises/falls.

Common code
-----------
**MACD**

Calculation
-----------
MACD=short-term-Period EMA − long-term-Period EMA

Explanation
-----------
 MACD is calculated by subtracting the long-term EMA (26 periods) from the short-term EMA (12 periods).
An exponential moving average (EMA) is a type of moving average (MA) that places a greater weight and significance
on the most recent data points.

The exponential moving average is also referred to as the exponentially weighted moving average.
An exponentially weighted moving average reacts more significantly to recent price changes than a simple
moving average (SMA), which applies an equal weight to all observations in the period.

Analyse
-------
The MACD has a positive value (shown as the blue line in the lower chart) whenever the 12-period EMA
(indicated by the red line on the price chart) is above the 26-period EMA (the blue line in the price chart)
and a negative value when the 12-period EMA is below the 26-period EMA. The more distant the MACD is above or
below its baseline indicates that the distance between the two EMAs is growing.

In the following chart, you can see how the two EMAs applied to the price chart correspond to the MACD (blue)
crossing above or below its baseline (dashed) in the indicator below the price chart.

MACD is often displayed with a histogram (see the chart below) which graphs the distance between the MACD and its
signal line. If the MACD is above the signal line, the histogram will be above the MACD’s baseline.
If the MACD is below its signal line, the histogram will be below the MACD’s baseline. Traders use the MACD’s histogram
to identify when bullish or bearish momentum is high.

Implementation
--------------
link to TA implementation.

:doc:`TA_MACD<../functions/MACD.rst>`
