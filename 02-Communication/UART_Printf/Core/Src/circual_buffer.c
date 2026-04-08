#include "circual_buffer.h"
#include <string.h> // memset kullanabilmek için şart

void Circular_Buffer_Init(Circular_Buffer_t *circularbuffer)
{
    // Cırcular -> CIRCULAR_BUFFER_SIZE olarak güncellendi
    memset(circularbuffer->buffer, 0, CIRCULAR_BUFFER_SIZE);
    circularbuffer->head = 0;
    circularbuffer->tail = 0;
}

bool Circular_Buffer_Is_Empty(Circular_Buffer_t *circularbuffer)
{
    return (circularbuffer->head == circularbuffer->tail);
}

bool Circular_Buffer_Is_Fully(Circular_Buffer_t *circularbuffer)
{
    // Daha verimli bir yöntem: head+1 bir sonraki adımda tail'e eşit mi?
    return ((circularbuffer->head + 1) % CIRCULAR_BUFFER_SIZE == circularbuffer->tail);
}

bool Circular_Buffer_Enqueue(Circular_Buffer_t *circularbuffer, uint8_t data)
{
    if (Circular_Buffer_Is_Fully(circularbuffer))
    {
        return false;
    }

    circularbuffer->buffer[circularbuffer->head] = data;
    circularbuffer->head = (circularbuffer->head + 1) % CIRCULAR_BUFFER_SIZE;
    return true; // Başarılı ekleme dönüşü
}

bool Circular_Buffer_Dequeue(Circular_Buffer_t *circularbuffer , uint8_t *data)
{
    if (Circular_Buffer_Is_Empty(circularbuffer))
    {
        return false; // Boşsa 0 veya hata kodu dönebilirsin
    }

     *data = circularbuffer->buffer[circularbuffer->tail];
    circularbuffer->tail = (circularbuffer->tail + 1) % CIRCULAR_BUFFER_SIZE;
    return true;
}

uint16_t Circular_Buffer_Count(Circular_Buffer_t *circularbuffer)
{
    if (circularbuffer->head >= circularbuffer->tail)
    {
        return (circularbuffer->head - circularbuffer->tail);
    }
    else
    {
        return (CIRCULAR_BUFFER_SIZE - (circularbuffer->tail - circularbuffer->head));
    }
}
