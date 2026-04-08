#ifndef INC_ESP_SPI_H_
#define INC_ESP_SPI_H_

#include "stm32f7xx_hal.h" // HAL kütüphanesini kullanmak için gerekli

// SPI yapılandırması için pin tanımlamaları (Daha sonra kolayca değiştirebilirsin)
#define ESP_CS_PORT GPIOD
#define ESP_CS_PIN  GPIO_PIN_14

// Fonksiyon Prototipleri
void ESP_SPI_Init(void);
HAL_StatusTypeDef ESP_SPI_Send(uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef ESP_SPI_Receive(uint8_t *pRxData, uint16_t Size);

#endif /* INC_ESP_SPI_H_ */
