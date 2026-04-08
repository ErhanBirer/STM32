#include "SPI.h"
#include "main.h" // HAL tanımları ve uint8_t için gerekli

// Değişken tanımlamaları fonksiyon dışında olabilir
uint8_t slave_rx_buf[32];
volatile uint8_t transfer_complete = 0;

// Harici SPI handle'ını tanıtıyoruz
extern SPI_HandleTypeDef hspi1;

// Kesme tamamlandığında çalışan Callback fonksiyonu
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi) {
    if (hspi->Instance == SPI1) {
        transfer_complete = 1;
    }
}

// Haberleşmeyi başlatan bir fonksiyon oluşturalım
void ESP_SPI_Start_Receive_IT(void) {
    HAL_SPI_Receive_IT(&hspi1, slave_rx_buf, 32);
}
