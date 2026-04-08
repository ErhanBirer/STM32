/*
 * software_timer.c
 *
 *  Created on: Mar 14, 2026
 *      Author: erhan
 */

#include "software_timer.h"
uint32_t msTick =0 ;


//1 zamanlayıcı seç ve başlat
void software_timer_Init(TIM_HandleTypeDef *htim)
{
HAL_TIM_Base_Start_IT(htim);
}


//2 timer set et ve başlat
void software_set_time(Stimer_t *sTimer , uint32_t interval_ms)
{
sTimer->start_time = software_timer_get_time();
sTimer->interval_time = interval_ms;
sTimer->activated = true;
}

// 3 zamanı al
uint32_t software_timer_get_time(void)
{
return msTick;
}

//4 geçen zamanı kontrol et
bool software_timer_check_elapsed_time(Stimer_t *sTimer)
{
	if(sTimer->activated)
	{
		uint32_t current_tick = software_timer_get_time();
		if(sTimer->start_time<= current_tick)
		{
			if(current_tick - sTimer->start_time >= sTimer->interval_time)
			{
				software_timer_stop(sTimer);
				return true;
			}
		}
		else
		{
			if(0XFFFFFFFF-(sTimer->start_time - current_tick)>= sTimer->interval_time)
			{
				software_timer_stop(sTimer);
				return true;
			}
		}
	}
	return false;
}

// 5 zamanlayıcıyı durdur
void software_timer_stop(Stimer_t *sTimer)
{
sTimer->activated = false;

}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM14)
	{
		//1mslik kesme
		msTick++;

	}
}
