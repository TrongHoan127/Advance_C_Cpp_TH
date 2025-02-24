#ifndef IOHWAB_MOTORSPEEDSENSOR_H
#define IOHWAB_MOTORSPEEDSENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến tốc độ động cơ
typedef struct {
    uint8_t MotorSpeedSensor_Channel;   // Kênh ADC để đọc giá trị từ cảm biến tốc độ động cơ
    uint16_t MotorSpeedSensor_MaxValue; // Giá trị tốc độ tối đa mà cảm biến có thể đọc (vòng/p)
} MotorSpeedSensor_ConfigType;

// Prototype cho hàm khởi tạo cảm biến tốc độ động cơ
Std_ReturnType IoHwAb_MotorSpeedSensor_Init(const MotorSpeedSensor_ConfigType* ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến tốc độ động cơ
Std_ReturnType IoHwAb_MotorSpeedSensor_Read(float* MotorSpeedValue);

#endif /* IOHWAB_SPEEDSENSOR_H */
