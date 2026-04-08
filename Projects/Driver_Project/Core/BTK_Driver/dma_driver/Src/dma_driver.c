/*
 * dma_driver.c
 *
 *  Created on: Feb 19, 2026
 *      Author: erhan
 */

#include "dma_driver.h"
#include "stm32f7xx_ll_adc.h"

volatile uint32_t GlobalDmaTransferStatus = DMA_Transfer_Not_Yet_Start ;
void ADC_Initialization(ADC_Info_t *adcInfo, ADC_HandleTypeDef *hadc)
{

adcInfo->hadc = hadc;
adcInfo->ADC_ErrorStatus = ADC_No_Error;


for(int i = 0 ; i < NUM_OF_ADC_CHANNEL ; i++)
{
adcInfo->adcConvertData[i] = 0;
adcInfo->adcVoltagetData[i] = 0;
adcInfo->adcSum[i]=0;
}
adcInfo->adcSampleCount = 0;

adcInfo->dmaTransferStatus = GlobalDmaTransferStatus;

if(HAL_ADC_Start_DMA(hadc, (uint32_t*)adcInfo->adcConvertData, NUM_OF_ADC_CHANNEL) != HAL_OK)
	adcInfo->ADC_ErrorStatus = ADC_init_Start_Error ;
}
void ADC_DMA_Conversion(ADC_Info_t *adcInfo)
{
    if(GlobalDmaTransferStatus == DMA_Transfer_Completed)
    {
        GlobalDmaTransferStatus = DMA_Transfer_Not_Completed;

        // Her DMA tamamlandığında sample'ı topla
        for(int i = 0; i < NUM_OF_ADC_CHANNEL; i++)
        {
            adcInfo->adcSum[i] += adcInfo->adcConvertData[i];
        }

        adcInfo->adcSampleCount++;

        // Yeterli sample toplandıysa ortalama al
        if(adcInfo->adcSampleCount >= ADC_AVG_Count)
        {
            adcInfo->adcSampleCount = 0;

            for(int i = 0; i < NUM_OF_ADC_CHANNEL; i++)
            {
                uint16_t AVG_ADC_DATA =
                    adcInfo->adcSum[i] / ADC_AVG_Count;

                adcInfo->adcVoltagetData[i] =
                    __LL_ADC_CALC_DATA_TO_VOLTAGE(
                        VDDA,
                        AVG_ADC_DATA,
                        digital_scale) / 1000.0f;

                adcInfo->adcSum[i] = 0;  // reset sum
            }
        }

        adcInfo->PotPercentage =
            MAP_Voltage_To_Percentage(
                adcInfo->adcVoltagetData[0],
                0.0f, 3.3f,
                0, 100);
    }
}

uint8_t MAP_Voltage_To_Percentage(float voltage , float inMin, float inMax , uint8_t outMin , uint8_t outMax)
{

uint8_t percentage = 0;
percentage =  (voltage-inMin)*(outMax-outMin)/(inMax-inMin) +outMin;
return percentage;


}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{

        GlobalDmaTransferStatus = DMA_Transfer_Completed;
        HAL_GPIO_TogglePin(GPIOB, LD1_Pin);

}


void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{

	// dma transfer status is not completed

}

