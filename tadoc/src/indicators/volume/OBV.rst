=======================
On Balance Volume (OBV)
=======================

Type
----
Volume indicator

Short description
-----------------


Description
-----------
On Balance Volume (OBV) is the volume indicator that calculates the buying and selling pressure 
as a cumulative indicator which sums up volume on up days and subtracts volume on down days.

When the stock closes higher than the previous close, then all of the day’s volume is considered up-volume.

Similarly when the stock closes lower than the previous close, then all of the day’s volume is considered down-volume.

Rather than the value, one should focus on its direction.

* When both price as well as OBV are making higher peaks and higher troughs, then the upward trend is likely to continue as shown below:

  .. image:: ../../_static/OBV-rising.png
    :alt: OBV rising

* When both price as well as OBV are making lower peaks and lower troughs, then the downward trend is likely to continue as shown below:

  .. image:: ../../_static/OBV-falling.png
    :alt: OBV falling

* When price continues to make higher peaks but OBV makes lower peaks, then the upward trend is likely to fail, known as negative divergence.
* When price continues to make lower troughs and OBV makes higher troughs, then the downward trend is to fail, known as positive divergence.

This indicator is calculated by adding the day’s volume to a cumulative total when the security’s price closes up, and subtracting the day’s volume when the security’s price closes down.

* If today’s close is greater than yesterday’s close then: OBV = Yesterday’s OBV + Today’s Volume
* If today’s close is less than yesterday’s close then: OBV = Yesterday’s OBV – Today’s Volume
* If today’s close is equal to yesterday’s close then: OBV = Yesterday’s OBV

Common code
-----------

Calculation
-----------

Explanation
-----------

Analyse
-------

Implementation
--------------
link to TA implementation.


