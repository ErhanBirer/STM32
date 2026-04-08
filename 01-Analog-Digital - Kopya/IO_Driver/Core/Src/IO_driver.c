/*
 * IO_driver.c
 *
 *  Created on: Feb 18, 2026
 *      Author: erhan
 */

#include "IO_driver.h"
void IO_İnitialization(IO_İnfo_t *ioInfo)
{

/*************** İnput İnitializaiton ***************/
	ioInfo->İnputsİnfo.userButton.GPIOx = USER_Btn_GPIO_Port;
	ioInfo->İnputsİnfo.userButton.GPIO_Pin = USER_Btn_Pin;
	ioInfo->İnputsİnfo.userButton.numberOfinput = 0;
	ioInfo->İnputsİnfo.userButton.currentState = GPIO_PIN_RESET;
	ioInfo->İnputsİnfo.userButton.lastState = GPIO_PIN_RESET;
	ioInfo->İnputsİnfo.userButton.inputStatus = Input_Status_Low;
	ioInfo->İnputsİnfo.userButton.currentTime= 0 ;
	ioInfo->İnputsİnfo.userButton.debounceTime = debounce_time;


	/*************** Output İnitializaiton ***************/
	ioInfo->Outputsİnfo.Blue_Led.GPIOx = LD2_GPIO_Port;
	ioInfo->Outputsİnfo.Blue_Led.GPIO_Pin = LD2_Pin;
	ioInfo->Outputsİnfo.Blue_Led.PinState = GPIO_PIN_RESET;

	ioInfo->Outputsİnfo.Red_Led.GPIOx = LD3_GPIO_Port;
	ioInfo->Outputsİnfo.Red_Led.GPIO_Pin = LD3_Pin;
	ioInfo->Outputsİnfo.Red_Led.PinState = GPIO_PIN_RESET;

	ioInfo->Outputsİnfo.Green_Led.GPIOx = LD1_GPIO_Port;
	ioInfo->Outputsİnfo.Green_Led.GPIO_Pin = LD1_Pin;
	ioInfo->Outputsİnfo.Green_Led.PinState = GPIO_PIN_RESET;

}
void IO_Status_Control(IO_İnfo_t *ioInfo)
{
	IO_Output_Control(&ioInfo->Outputsİnfo.Blue_Led);
	IO_Output_Control(&ioInfo->Outputsİnfo.Green_Led);
	IO_Output_Control(&ioInfo->Outputsİnfo.Red_Led);

	IO_İnput_Control_With_Debounce(&ioInfo->İnputsİnfo.userButton);
}

void IO_İnput_Control_With_Debounce(Input_State_t *inputState)
{
inputState->currentState = HAL_GPIO_ReadPin(inputState->GPIOx, inputState->GPIO_Pin);
if(inputState->currentState == GPIO_PIN_SET)
{
	if(inputState->inputStatus == Input_Status_Low)
	{
		if(inputState->currentState != inputState->lastState)
		{

			inputState->lastState = inputState->currentState;
			inputState->currentTime = HAL_GetTick();
		}
		if((HAL_GetTick()- inputState->currentTime)>= inputState->debounceTime)
		{

			inputState->inputStatus = Input_Status_High;

		}
	}

	else
	{

		// zaten high
	}
}
else
{
	inputState->lastState = inputState->currentState;
	inputState->inputStatus = Input_Status_Low;
}


}
void IO_Output_Control(Output_State_t *OutputState)
{



HAL_GPIO_WritePin(OutputState->GPIOx, OutputState->GPIO_Pin, OutputState->PinState);


}
