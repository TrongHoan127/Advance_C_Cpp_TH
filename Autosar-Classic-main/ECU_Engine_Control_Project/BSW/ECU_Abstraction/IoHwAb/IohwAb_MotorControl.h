#ifndef IOHWAB_MOTORCONTROL_H
#define IOHWAB_MOTORCONTROL_H

#include "Std_Types.h"

// Cấu trúc cấu hình cho mô-tơ
typedef struct {
    uint8_t Motor_Channel;      // Kênh PWM điều khiển mô-tơ
    uint16_t Motor_MaxSpeed;    //tốc độ động cơ tối đa (vòng/p)
} MotorControl_ConfigType;

// Prototype khởi tạo mô-tơ
Std_ReturnType IoHwAb_MotorControl_Init(const MotorControl_ConfigType* ConfigPtr);
// Prototype điều chỉnh tốc độ động cơ
Std_ReturnType IoHwAb_MotorControl_SetSpeed(float MotorSpeedValue);
#endif /* IOHWAB_MOTORCONTROL_H */
