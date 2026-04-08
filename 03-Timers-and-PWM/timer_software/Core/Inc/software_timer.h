/*
 * software_timer.h
 *
 *  Created on: Mar 14, 2026
 *      Author: erhan
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#include "main.h"
#include "stdbool.h"

typedef struct
{
uint32_t start_time;
uint32_t interval_time;
bool	activated;
}Stimer_t;

//1 zamanlayıcı seç ve başlat
void software_timer_Init(TIM_HandleTypeDef *htim);
//2 timer set et ve başlat
void software_set_time(Stimer_t *sTimer , uint32_t interval_ms);
// 3 zamanı al
uint32_t software_timer_get_time(void);
//4 geçen zamanı kontrol et
bool software_timer_check_elapsed_time(Stimer_t *sTimer);
// 5 zamanlayıcıyı durdur
void software_timer_stop(Stimer_t *sTimer);






#endif /* INC_SOFTWARE_TIMER_H_ */
