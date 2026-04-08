#ifndef INC_CIRCUAL_BUFFER_H_
#define INC_CIRCUAL_BUFFER_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h> // memset için ekledik

// 'ı' harfini 'i' yaptık:
#define CIRCULAR_BUFFER_SIZE 512

typedef struct
{
    uint8_t buffer[CIRCULAR_BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
} Circular_Buffer_t;

// Fonksiyon Prototipleri
void Circular_Buffer_Init(Circular_Buffer_t *circularbuffer);
bool Circular_Buffer_Is_Empty(Circular_Buffer_t *circularbuffer);
bool Circular_Buffer_Is_Fully(Circular_Buffer_t *circularbuffer);
bool Circular_Buffer_Enqueue(Circular_Buffer_t *circularbuffer, uint8_t data);
bool Circular_Buffer_Dequeue(Circular_Buffer_t *circularbuffer , uint8_t *data);
uint16_t Circular_Buffer_Count(Circular_Buffer_t *circularbuffer);

#endif /* INC_CIRCUAL_BUFFER_H_ */
