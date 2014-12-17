/**************************************************************************
 *                                                                         *
 * ITG Gyro Driver for Arduino                                         *
 *                                                                         *
 ***************************************************************************/
#include "Arduino.h"

#ifndef ITG_h
#define ITG_h

/* ------- Register names ------- */
#define ITG_ADDR	(0xD0 >> 1) //0xD0 if tied low, 0xD2 if tied high

#define ITG_WHO_AM_I	0x00
#define ITG_SMPLRT_DIV	0x15
#define	ITG_DLPF_FS		0x16
#define ITG_INT_CFG		0x17
#define ITG_INT_STATUS	0x1A
#define	ITG_TEMP_OUT_H	0x1B
#define	ITG_TEMP_OUT_L	0x1C
#define ITG_GYRO_XOUT_H	0x1D
#define	ITG_GYRO_XOUT_L	0x1E
#define ITG_GYRO_YOUT_H	0x1F
#define ITG_GYRO_YOUT_L	0x20
#define ITG_GYRO_ZOUT_H	0x21
#define ITG_GYRO_ZOUT_L	0x22
#define	ITG_PWR_MGM		0x3E


#define ITG_FULLSCALE (0x03 << 3)
#define ITG_42HZ (0x03)

class ITG
{
public:
	ITG();
	void init();
	void readXYZ(int* xyx);
	
private:
	void writeTo(byte address, byte val);
	void readFrom(byte address, int num, byte buff[]);
	byte _buff[6] ;    //6 bytes buffer for saving data read from the device
};
#endif
