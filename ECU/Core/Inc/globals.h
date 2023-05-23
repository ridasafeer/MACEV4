/*
 * globals.h
 *
 *  Created on: May 21, 2023
 *      Author: Samuel Parent
 */

#ifndef INC_GLOBALS_H_
#define INC_GLOBALS_H_

/*********************************************************
*                       INCLUDES
*********************************************************/

#include "stdint.h"
#include "adc.h"
#include "canal.h"
#include "uart.h"
#include <pthread.h>

/*********************************************************
*                       DEFINES
*********************************************************/

#define DEBUG_MODE 1

// ADC:
#define APPS1_ADC_CHANNEL 					(10)
#define APPS1_BUFFER_LEN 					(10)

#define APPS2_ADC_CHANNEL 					(11)
#define APPS2_BUFFER_LEN 					(10)

#define STEERING_ANGLE_SENSOR_ADC_CHANNEL 	(12)
#define STEERING_ANGLE_SENSOR_BUFFER_LEN 	(10)

#define BPPS_BUFFERED 						(13)
#define BPPS_BUFFERED_BUFFER_LEN 			(10)

#define ADC1_NUM_CHANNELS 					(4)

// CAN:
#define PT1_CAN_INST 						(CANAL_INST_CAN_1)
#define PT1_CAN_BAUD						(CANAL_BAUD_500K)
#if DEBUG_MODE
#define PT1_CAN_MODE						(CANAL_MODE_SILENT_LOOPBACK)
#else
#define PT1_CAN_MODE						(CANAL_MODE_NORMAL)
#endif // DEBUG_MODE

#define PT2_CAN_INST						(CANAL_INST_CAN_2)
#define PT2_CAN_BAUD						(CANAL_BAUD_500K)
#define PT2_CAN_MODE						(CANAL_MODE_SILENT_LOOPBACK)

#define VEH_CAN_INST						(CANAL_INST_CAN_3)
#define VEH_CAN_BAUD						(CANAL_BAUD_500K)
#if DEBUG_MODE
#define VEH_CAN_MODE						(CANAL_MODE_SILENT_LOOPBACK)
#else
#define VEH_CAN_MODE						(CANAL_MODE_NORMAL)
#endif // DEBUG_MODE


extern TsCanAL pt1_can;
extern TsCanAL pt2_can;
extern TsCanAL veh_can;
extern ADC_st adc1;

/*********************************************************
*                        ADC
*********************************************************/

ADC_HandleTypeDef hadc1;

uint16_t apps1_buffer[APPS1_BUFFER_LEN] = {0};
uint16_t apps2_buffer[APPS2_BUFFER_LEN] = {0};
uint16_t steering_angle_sensor_buffer[STEERING_ANGLE_SENSOR_BUFFER_LEN]= {0};
uint16_t bpps_buffered_buffer[BPPS_BUFFERED_BUFFER_LEN] = {0};


ADC_Channel_st adc1_channels[ADC1_NUM_CHANNELS] = {
	{
		.channel_number = APPS1_ADC_CHANNEL,
		.sample_time = ADC_28CYCLES,
		.buffer_len = APPS1_BUFFER_LEN,
		.buffer = apps1_buffer,
		.convert = NULL,
	},
	{
		.channel_number = APPS2_ADC_CHANNEL,
		.sample_time = ADC_15CYCLES,
		.buffer_len = APPS2_BUFFER_LEN,
		.buffer = apps2_buffer,
		.convert = NULL,
	},
};

ADC_st adc1 = {
	.hadc = &hadc1,
	.adc_num = 1,
	.num_channels = ADC1_NUM_CHANNELS,
	.channels = adc1_channels,
};

/*********************************************************
*                        CAN
*********************************************************/

extern pthread_mutex_t can_lock;

CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;
CAN_HandleTypeDef hcan3;

TsCanAL pt1_can = {
	.hcan = &hcan1,
	.canNum = PT1_CAN_INST,
	.baud = PT1_CAN_BAUD,
	.mode = PT1_CAN_MODE,
};

TsCanAL pt2_can = {
	.hcan = &hcan2,
	.canNum = PT2_CAN_INST,
	.baud = PT2_CAN_BAUD,
	.mode = PT2_CAN_MODE,
};

TsCanAL veh_can = {
	.hcan = &hcan3,
	.canNum = VEH_CAN_INST,
	.baud = VEH_CAN_BAUD,
	.mode = VEH_CAN_MODE,
};

/*********************************************************
*                        UART
*********************************************************/

// NOT USING THE GPS YET (uart2)


/*********************************************************
*                        SPI
*********************************************************/

// NOT USING THE IMU YET
SPI_HandleTypeDef hspi4;


#endif /* INC_GLOBALS_H_ */
