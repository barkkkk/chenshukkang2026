//
// Created by 54945 on 2025/10/3.
//

#ifndef CSK1_CAL_MINMAX_H
#define CSK1_CAL_MINMAX_H

class M3508_Motor {
private:
    const float ratio_;

    float angle_ = 0.f;
    float delta_angle_ = 0.f;
    float ecd_angle_ = 0.f;
    float last_ecd_angle_ = 0.f;
    float delta_ecd_angle_ = 0.f;
    float rotate_speed_ = 0.f;
    float current_ = 0.f;
    float temp_ = 0.f;

public:
    explicit M3508_Motor(const float ratio) : ratio_(ratio) {};
    void canRxMsgCallback(const uint8_t rx_data[8]);
};

#endif //CSK1_CAL_MINMAX_H

