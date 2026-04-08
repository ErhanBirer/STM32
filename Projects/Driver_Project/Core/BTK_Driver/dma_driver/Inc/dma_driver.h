/*
 * dma_driver.h
 *
 *  Created on: Feb 19, 2026
 *      Author: erhan
 */

#ifndef INC_DMA_DRIVER_H_
#define INC_DMA_DRIVER_H_

#include "main.h"
#define NUM_OF_ADC_CHANNEL 4
#define VDDA 			   3300


#define digital_scale_6BITS  0X3F  //63
#define digital_scale_8BITS  0XFF // 255
#define digital_scale_10BITS 0X3FF //1023
#define digital_scale_12BITS 0XFFF // 4095
extern volatile uint32_t GlobalDmaTransferStatus;

#define ADC_AVG_Count 64


#define digital_scale		digital_scale_12BITS
typedef enum
{
	DMA_Transfer_Not_Completed = 0,
	DMA_Transfer_Completed = 1,
	DMA_Transfer_Not_Yet_Start = 2,

}DMA_Transfer_Status_t;


typedef enum
{
ADC_No_Error = 0,
ADC_init_Start_Error = 1,
}ADC_Error_t;


typedef struct
{

ADC_HandleTypeDef *hadc;
uint16_t          adcConvertData[NUM_OF_ADC_CHANNEL];
float        adcVoltagetData[NUM_OF_ADC_CHANNEL];
DMA_Transfer_Status_t  dmaTransferStatus;
ADC_Error_t			ADC_ErrorStatus;
uint8_t 	PotPercentage;
uint8_t  adcSampleCount;
uint32_t adcSum[NUM_OF_ADC_CHANNEL];
}ADC_Info_t;


void ADC_Initialization(ADC_Info_t *adcInfo , ADC_HandleTypeDef *hadc);
void ADC_DMA_Conversion(ADC_Info_t *adcInfo);
uint8_t MAP_Voltage_To_Percentage(float voltage , float inMin, float inMax , uint8_t outMin , uint8_t outMax);



#endif /* INC_DMA_DRIVER_H_ */
