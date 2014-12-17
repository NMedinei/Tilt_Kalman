Tilt_Kalman
===========

Modules related to Kalman filter for forward and side tilts.

It includes the usual 10-sample low-pass filter in the read_Acc_angle() function, and then the Kalman filtering-related functions. The main loop remains at 10ms.

I will add extra code to
1) Verify noise variance for sensors,
2) Compare the output of Kalman filter and only low-pass techniques.
