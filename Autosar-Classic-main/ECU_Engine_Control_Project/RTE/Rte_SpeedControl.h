#ifndef RTE_SPEEDCONTROL_H
#define RTE_SPEEDCONTROL_H

#include "Std_Types.h"  // Bao gồm các kiểu dữ liệu tiêu chuẩn
#include <stddef.h>  // Định nghĩa NULL


// API để đọc dữ liệu từ cảm biến bàn đạp ga
Std_ReturnType Rte_Read_RpThrottleSensor_ThrottlePosition(float* ThrottlePosition);

// API để đọc dữ liệu từ cảm biến dòng điện
Std_ReturnType Rte_Read_RpCurrentSensor_Current(float* Currentinput);

// API để đọc dữ liệu từ cảm biến tốc độ động cơ thực tế
Std_ReturnType Rte_Read_RpMotorSpeedSensor_ActualSpeed(float* Actualspeed);

// API để ghi dữ liệu tốc độ động cơ yêu cầu tới bộ điều khiển động cơ
Std_ReturnType Rte_Write_PpMotorDriver_SetSpeed(float SpeedValue);

// API khởi tạo cảm biến bàn đạp ga
Std_ReturnType Rte_Call_RpThrottleSensor_Init(void);

// API khởi tạo cảm biến tốc độ động cơ thực tế
Std_ReturnType Rte_Call_RpSpeedSensor_Init(void);

// API khởi tạo cảm biến dòng điện
Std_ReturnType Rte_Call_RpCurrentSensor_Init(void);

// API khởi tạo bộ điều khiển tốc độ động cơ
Std_ReturnType Rte_Call_PpMotorDriver_Init(void);

#endif // RTE_TORQUECONTROL_H
