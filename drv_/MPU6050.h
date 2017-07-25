/*
 * MPU6050.h
 *
 * Created: 7/24/2017 1:45:06 PM
 *  Author: HP
 */ 
#include "defines.h"
#include "functions.h"
#include "USART.h"
#include "ADC.h"
#include "TIMER.h"
#include "mpu6050registers.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

uint16_t mpu6050_read_gyroX();
uint16_t mpu6050_read_gyroY();
uint16_t mpu6050_read_gyroZ();
uint16_t mpu6050_read_accelX();
uint16_t mpu6050_read_accelY();
uint16_t mpu6050_read_accelZ();

void print_double(double *value);
uint8_t mpu6050_readByte(uint8_t byteToRead);//readbyte
void mpu6050_writeByte(uint8_t wereToWrite,uint8_t byteToWrite);
int8_t mpu6050_readBytes(uint8_t regAddr, uint8_t length, uint8_t *data);
void mpu6050_getRawData(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
#ifdef CALIBERATED_DATA
	#define accX (accel_x-=accelX_calib)
	#define accY (accel_y-=accelY_calib)
	#define accZ (accel_z-=accelZ_calib)
	#define grX (gyro_x-=gyroX_calib)
	#define grY (gyro_y-=gyroY_calib)
	#define grZ (gyro_z-=gyroZ_calib)
	#define calibration_counter 20
	#define caliberation_wait_delay 0//in ms
	void mpu6050_calibrate_gyro(int32_t *x,int32_t *y, int32_t *z);
	void mpu6050_calibrate_accel(int32_t *x,int32_t *y, int32_t *z);
#endif
