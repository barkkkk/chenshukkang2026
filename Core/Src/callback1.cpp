//
// Created by 54945 on 2025/10/2.
//

#include "callback1.h"

#include "can.h"
#include "gpio.h"
#include "tim.h"
#include "main.h"
#include "usart.h"


extern uint8_t rx_msg[4];
extern uint8_t rx_data[8];
extern uint8_t tx_data[8];
extern CAN_RxHeaderTypeDef rx_header;
extern CAN_TxHeaderTypeDef tx_header;
extern uint32_t transmit_box;
extern uint32_t count;

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
    if (hcan->Instance == CAN1) {
        count++;
        HAL_CAN_GetRxMessage(&hcan1,CAN_RX_FIFO0, &rx_header,rx_data);
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == htim6.Instance){
        HAL_CAN_AddTxMessage(&hcan1,&tx_header,tx_data,&transmit_box);
    }
}



// R_W
// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//     if (huart == &huart7) {
//         if (rx_msg[0] == 'R') {
//             HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, GPIO_PIN_RESET);
//         }
//         else if (rx_msg[0] == 'M') {
//             HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, GPIO_PIN_SET);
//         }
//         HAL_UART_Receive_IT(&huart7, rx_msg, 1);
//
//     }
//
// }



// TIM
// void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
//     if (htim == &htim1) {
//         count1++;
//     }
// }

// EXIT
// void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
//     if (GPIO_Pin == GPIO_PIN_2) {
//         count1 = count1 + 1;
//         uint32_t arr_value = __HAL_TIM_GET_AUTORELOAD(&htim1) +1;
//         uint32_t brightness = (__HAL_TIM_GetCompare(&htim1,TIM_CHANNEL_2) + 100) % arr_value;
//         __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_2,brightness);
//     }
// }
