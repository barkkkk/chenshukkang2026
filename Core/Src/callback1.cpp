//
// Created by 54945 on 2025/10/2.
//

#include "callback1.h"
#include "gpio.h"
#include "tim.h"

extern uint32_t count1;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim == &htim1) {
        count1++;
    }
}

// EXIT
// void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
//     if (GPIO_Pin == GPIO_PIN_2) {
//         count1 = count1 + 1;
//         uint32_t arr_value = __HAL_TIM_GET_AUTORELOAD(&htim1) +1;
//         uint32_t brightness = (__HAL_TIM_GetCompare(&htim1,TIM_CHANNEL_2) + 100) % arr_value;
//         __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,brightness);
//     }
// }
