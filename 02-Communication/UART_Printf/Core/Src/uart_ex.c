/*
 * uart_ex.c
 *
 *  Created on: Mar 11, 2026
 *      Author: erhan
 */
#include "uart_ex.h"

void UARTx_Init(UART_Ex_t *uart ,UART_HandleTypeDef *huart,Circular_Buffer_t *cbin,Circular_Buffer_t *cbout )
{
	uart->huart = huart;
	uart->cbin = cbin;
	uart->cbout = cbout;

	Circular_Buffer_Init(uart->cbin);
	Circular_Buffer_Init(uart->cbout);
	__HAL_UART_ENABLE_IT(uart->huart , UART_IT_RXNE);
	__HAL_UART_ENABLE_IT(uart->huart , UART_IT_TXE);
}


void UARTx_Write_Char(UART_Ex_t *uart , char ch)
{
	if(Circular_Buffer_Enqueue(uart->cbout,ch))
	{
		if(!(uart->huart->Instance->CR1 & USART_CR1_TXEIE))
		{
			uint8_t ch;
			if(Circular_Buffer_Dequeue(uart->cbout, &ch))
			{
				uart->huart->Instance->TDR = ch;
				__HAL_UART_ENABLE_IT(uart->huart ,UART_IT_TXE);
			}
		}
	}
}

void UARTx_Put_String(UART_Ex_t *uart , char *str)
{
while(*str)
{
	UARTx_Write_Char(uart, *str);
	str++;
}
}


int UARTx_Printf(UART_Ex_t *uart , const char *format , ...)
{
	char tx_buffer[256];
	va_list args;

	va_start(args,format);
	int length = vsnprintf(tx_buffer,sizeof(tx_buffer),format,args);
	va_end(args);
	UARTx_Put_String(uart, tx_buffer);
	return length;
}


bool UARTx_ReadLine(UART_Ex_t *uart, char *linebuffer, uint16_t maxLen)
{
    static uint16_t index    = 0;
    static bool messageReady = false;
    static bool lastCr       = false; // Küçük harf 'l' ile düzeltildi (tutarlılık için)
    uint8_t ch               = 0;

    if (messageReady)
    {
        // Yeni bir okuma başlatılmadan önce flag'i ve index'i temizlemelisin
    	linebuffer[index] = '\0';
        messageReady = false;
        index = 0;
        return true;
    }

    // While döngüsünün sonundaki ';' kaldırıldı, aksi halde gövde çalışmazdı
    while (Circular_Buffer_Dequeue(uart->cbin, &ch))
    {
        // C'de tek karakterler tek tırnak '' ile belirtilir. "\n" bir dizidir.
        if (lastCr && ch == '\n')
        {
            linebuffer[index] = '\0'; // Satırı sonlandırmak için null terminator ekle
            messageReady = true;
            lastCr = false;
            return true; // Mesaj tamamlandı
        }

        if (ch == '\r')
        {
            lastCr = true;
        }
        else
        {
            if (lastCr)
            {
                // Eğer CR'den sonra LF gelmediyse, CR'yi normal karakter olarak ekle
                if (index < maxLen - 1)
                    linebuffer[index++] = '\r';

                lastCr = false;
            }

            if (index < maxLen - 1)
            {
                linebuffer[index++] = ch;
            }
        }
    }

    return false;
}
