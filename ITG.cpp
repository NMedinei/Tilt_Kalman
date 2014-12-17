/**************************************************************************
 *                                                                         *
 * ITG Driver for Arduino                                              *
 *                                                                         *
 ***************************************************************************/
#include "Arduino.h"
#include "ITG.h"
#include <Wire.h>


ITG::ITG() {
}

void ITG::init() {
	Wire.begin();        // join i2c bus (address optional for master)
	writeTo(ITG_PWR_MGM, 0x80);	// Reset the device to initial state
	writeTo(ITG_DLPF_FS, ITG_FULLSCALE | ITG_42HZ);
}

// Reads the acceleration into three variable x, y and z
void ITG::readXYZ(int *xyz){
	readFrom(ITG_GYRO_XOUT_H, 6, _buff);
	((uint8_t*)xyz)[0] = _buff[1];
	((uint8_t*)xyz)[1] = _buff[0];
	((uint8_t*)xyz)[2] = _buff[3];
	((uint8_t*)xyz)[3] = _buff[2];
	((uint8_t*)xyz)[4] = _buff[5];
	((uint8_t*)xyz)[5] = _buff[4];
}
// Writes val to address register on device
void ITG::writeTo(byte address, byte val) {
	Wire.beginTransmission(ITG_ADDR); // start transmission to device 
	Wire.write(address);             // send register address
	Wire.write(val);                 // send value to write
	Wire.endTransmission();         // end transmission
}

// Reads num bytes starting from address register on device in to _buff array
void ITG::readFrom(byte address, int num, byte _buff[]) {
	Wire.beginTransmission(ITG_ADDR); // start transmission to device 
	Wire.write(address);             // sends address to read from
	Wire.endTransmission();         // end transmission
	
	Wire.beginTransmission(ITG_ADDR); // start transmission to device
	Wire.requestFrom(ITG_ADDR, num);    // request 6 bytes from device
	
	int i = 0;
	while(Wire.available())         // device may send less than requested (abnormal)
	{ 
		_buff[i] = Wire.read();    // receive a byte
		i++;
	}
	if(i != num){
//		status = ADXL345_ERROR;
//		error_code = ADXL345_READ_ERROR;
	}
	Wire.endTransmission();         // end transmission
}

