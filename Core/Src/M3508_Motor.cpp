//
// Created by 54945 on 2025/10/3.
//

#include "main.h"
#include "M3508_Motor.h"

M3508_Motor Motor(19.2f);

float linearMapping(int in, int in_min, int in_max, float out_min, float out_max) {
    if (in_min == in_max) {
        return out_min;
    }
    return out_min + (out_max - out_min) * (in - in_min) / (in_max - in_min);
};

void M3508_Motor::canRxMsgCallback(const uint8_t rx_data[8]) {
    int ecd_angle = (rx_data[0] << 8) | rx_data[1];
    ecd_angle_ = linearMapping(ecd_angle,0,8191,0.0,360.0);
    delta_ecd_angle_ = ecd_angle_ - last_ecd_angle_;
    if (delta_ecd_angle_ > 180.0f) {
        delta_ecd_angle_ -= 360.0f;
    } else if (delta_ecd_angle_ < -180.0f) {
        delta_ecd_angle_ += 360.0f;
    }
    last_ecd_angle_ = ecd_angle_;
    delta_angle_ = delta_ecd_angle_ / ratio_;
    angle_ += delta_angle_;

    int rotate_speed = (rx_data[2] << 8) | rx_data[3];
    rotate_speed_ = (float)rotate_speed;

    int current = (rx_data[4] << 8) | rx_data[5];
    current_ = linearMapping(current,-16384,16384,-20.0,20.0);

    temp_ = rx_data[6];
};