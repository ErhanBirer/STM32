/*
 * IO_driver.h
 *
 *  Created on: Feb 18, 2026
 *      Author: erhan
 */

#ifndef INC_IO_DRIVER_H_
#define INC_IO_DRIVER_H_

#include "main.h"

#define debounce_time 100 // 100ms

typedef enum
{
Input_Status_Low =0,
Input_Status_High // =1
}Input_Status_t;


typedef struct
{
GPIO_TypeDef *GPIOx;
uint16_t GPIO_Pin;
uint16_t numberOfinput;
GPIO_PinState currentState;
GPIO_PinState lastState;
Input_Status_t inputStatus;
uint32_t currentTime;
uint32_t debounceTime;
}Input_State_t;


typedef struct
{

	Input_State_t userButton;

}İnputs_İnfo_t;



typedef struct
{
GPIO_TypeDef *GPIOx;
uint16_t GPIO_Pin;
GPIO_PinState PinState;
}Output_State_t;

typedef struct
{

	Output_State_t Green_Led;
	Output_State_t Red_Led;
	Output_State_t Blue_Led;

}Outputs_İnfo_t;



typedef struct
{

	İnputs_İnfo_t  İnputsİnfo;
	Outputs_İnfo_t Outputsİnfo;
}IO_İnfo_t;



void IO_İnitialization(IO_İnfo_t *ioInfo);
void IO_Status_Control(IO_İnfo_t *ioInfo);
void IO_İnput_Control_With_Debounce(Input_State_t *inputState);
void IO_Output_Control(Output_State_t *OutputState);






#endif /* INC_IO_DRIVER_H_ */
