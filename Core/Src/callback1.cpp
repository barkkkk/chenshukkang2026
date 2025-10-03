//
// Created by 54945 on 2025/10/2.
//

#include "callback1.h"

#include "can.h"
#include "gpio.h"
#include "M3508_Motor.h"
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
extern M3508_Motor Motor;


// float linearMapping(int in, int in_min, int in_max, float out_min, float out_max) {
//     if (in_min == in_max) {
//         return out_min;
//     }
//     return out_min + (out_max - out_min) * (in - in_min) / (in_max - in_min);
// };
//
//
// class M3508_Motor {
// private:
//     const float ratio_;
//
//     float angle_ = 0.f;
//     float delta_angle_ = 0.f;
//     float ecd_angle_ = 0.f;
//     float last_ecd_angle_ = 0.f;
//     float delta_ecd_angle_ = 0.f;
//     float rotate_speed_ = 0.f;
//     float current_ = 0.f;
//     float temp_ = 0.f;
//
// public:
//     explicit M3508_Motor(const float ratio) : ratio_(ratio) {};
//     void canRxMsgCallback(const uint8_t rx_data[8]) {
//         int ecd_angle = (rx_data[0] << 8) | rx_data[1];
//         ecd_angle_ = linearMapping(ecd_angle,0,8191,0.0,360.0);
//         delta_ecd_angle_ = ecd_angle_ - last_ecd_angle_;
//         if (delta_ecd_angle_ > 180.0f) {
//             delta_ecd_angle_ -= 360.0f;
//         } else if (delta_ecd_angle_ < -180.0f) {
//             delta_ecd_angle_ += 360.0f;
//         }
//         last_ecd_angle_ = ecd_angle_;
//         delta_angle_ = delta_ecd_angle_ / ratio_;
//         angle_ += delta_angle_;
//
//         int rotate_speed = (rx_data[2] << 8) | rx_data[3];
//         rotate_speed_ = (float)rotate_speed;
//
//         int current = (rx_data[4] << 8) | rx_data[5];
//         current_ = linearMapping(current,-16384,16384,-20.0,20.0);
//
//         temp_ = rx_data[6];
//     };
// };




void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
    if (hcan->Instance == CAN1) {
        count++;
        HAL_CAN_GetRxMessage(&hcan1,CAN_RX_FIFO0, &rx_header,rx_data);
        Motor.canRxMsgCallback(rx_data);
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
