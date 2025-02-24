#ifndef IOHWAB_CURRENTSENSOR_H
#define IOHWAB_CURRENTSENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến dòng điện (Current Sensor)
typedef struct {
    uint8_t CurrentSensor_Channel;   // Kênh ADC để đọc giá trị từ cảm biến
    uint16_t CurrentSensor_MaxValue; // Giá trị dòng điện tối đa mà cảm biến có thể đọc
} CurrentSensor_ConfigType;

// Khởi tạo cảm biến tải trọng
Std_ReturnType IoHwAb_CurrentSensor_Init(const CurrentSensor_ConfigType* ConfigPtr);

// Đọc giá trị từ cảm biến tải trọng
Std_ReturnType IoHwAb_CurrentSensor_Read(float* CurrentValue);

#endif /* IOHWAB_CURRENTSENSOR_H */