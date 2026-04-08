/*
 * uart_ex.h
 *
 *  Created on: Mar 11, 2026
 *      Author: erhan
 */

#ifndef INC_UART_EX_H_
#define INC_UART_EX_H_

#include "main.h"
#include "circual_buffer.h"
#include "stdio.h"
#include "string.h"
#include "stdarg.h"


typedef struct
{
	UART_HandleTypeDef *huart;
	Circular_Buffer_t *cbin;
	Circular_Buffer_t *cbout;


}UART_Ex_t;


void UARTx_Init(UART_Ex_t *uart ,UART_HandleTypeDef *huart,Circular_Buffer_t *cbin,Circular_Buffer_t *cbout );
void UARTx_Write_Char(UART_Ex_t *uart , char ch);
void UARTx_Put_String(UART_Ex_t *uart , char *str);
int UARTx_Printf(UART_Ex_t *uart , const char *format , ...);
bool UARTx_ReadLine(UART_Ex_t *uart , char *linebuffer , uint16_t maxLen);

#endif /* INC_UART_EX_H_ */
