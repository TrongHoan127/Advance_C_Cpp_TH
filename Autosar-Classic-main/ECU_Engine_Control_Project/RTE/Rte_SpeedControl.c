#include "Rte_SpeedControl.h"
#include "IoHwAb_ThrottleSensor.h"  // API IoHwAb để đọc cảm biến bàn đạp ga
#include "IoHwAb_MotorSpeedSensor.h"     // API IoHwAb để đọc cảm biến tốc độ động cơ
#include "IoHwAb_CurrentSensor.h"      // API IoHwAb để đọc cảm biến dòng điện
#include "IoHwAb_MotorControl.h"     // API IoHwAb để điều khiển tốc độ động cơ
#include "Std_Types.h"

// API để đọc dữ liệu từ cảm biến bàn đạp ga
Std_ReturnType Rte_Read_RpThrottleSensor_ThrottlePosition(float* ThrottlePosition) {
    if (ThrottlePosition == NULL) {
        return E_NOT_OK;  // Trả về lỗi nếu con trỏ NULL
    }
    return IoHwAb_ThrottleSensor_Read(ThrottlePosition);  // Gọi API từ IoHwAb để đọc giá trị từ cảm biến
}


// API để đọc dữ liệu từ cảm biến dòng điện
Std_ReturnType Rte_Read_RpCurrentSensor_Current(float* Currentinput) {
    if (Currentinput == NULL) {
        return E_NOT_OK;
    }
    return IoHwAb_CurrentSensor_Read(Currentinput);  // Gọi API từ IoHwAb để đọc giá trị từ cảm biến dòng điện
}

// API để đọc tốc độ thực tế từ cảm biến tốc độ động cơ thực tế
Std_ReturnType Rte_Read_RpMotorSpeedSensor_ActualSpeed(float* Actualspeed) {
    if (Actualspeed== NULL) {
        return E_NOT_OK;
    }
    return IoHwAb_MotorSpeedSensor_Read(Actualspeed);  // Gọi API từ IoHwAb để đọc tốc độ động cơ thực tế
}

// API để ghi dữ liệu tốc độ động cơ yêu cầu tới bộ điều khiển động cơ
Std_ReturnType Rte_Write_PpMotorDriver_SetSpeed(float SpeedValue) {
    return IoHwAb_MotorDriver_SetSpeed(SpeedValue);  // Gọi API từ IoHwAb để ghi tốc độ động cơ yêu cầu tới động cơ
}

// API khởi tạo cảm biến bàn đạp ga
Std_ReturnType Rte_Call_RpThrottleSensor_Init(void) {
    ThrottleSensor_ConfigType throttleSensorConfig = {
        .ThrottleSensor_Channel = 0  // Kênh ADC cho cảm biến bàn đạp ga
    };
    return IoHwAb_ThrottleSensor_Init(&throttleSensorConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến bàn đạp ga
}

// API khởi tạo cảm biến tốc động cơ thực tế
Std_ReturnType Rte_Call_RpSpeedSensor_Init(void) {
    // Cấu hình cho cảm biến tốc độ động cơ
    MotorSpeedSensor_ConfigType speedSensorConfig = {
        .MotorSpeedSensor_Channel = 1,        // Kênh ADC cho cảm biến tốc độ
        .MotorSpeedSensor_MaxValue = 3000      // Tốc độ tối đa giả lập (3000 vòng/p)
    };
    return IoHwAb_SpeedSensor_Init(&speedSensorConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến tốc độ
}

// API khởi tạo cảm biến dòng điện
Std_ReturnType Rte_Call_RpCurrentSensor_Init(void) {
    // Cấu hình cho cảm biến tải trọng
    CurrentSensor_ConfigType currentSensorConfig = {
        .CurrentSensor_Channel = 2,         // Kênh ADC cho cảm biến tải trọng
        .CurrentSensor_MaxValue = 50      // dòng điện tối đa giả lập (50A)
    };
    return IoHwAb_LoadSensor_Init(&currentSensorConfig);  // Gọi API từ IoHwAb để khởi tạo cảm biến tải trọng
}


// API khởi tạo bộ điều khiển tốc độ động cơ
Std_ReturnType Rte_Call_PpMotorControl_Init(void) {
    // Cấu hình cho bộ điều khiển mô-men xoắn
    MotorControl_ConfigType motorControlConfig = {
        .Motor_Channel = 1,              // Kênh điều khiển mô-tơ
        .Motor_MaxSpeed = 2500           // tốc độ động cơ tối đa giả lập (2500 vòng/p)
    };
    return IoHwAb_MotorControl_Init(&motorControlConfig);  // Gọi API từ IoHwAb để khởi tạo bộ điều khiển mô-men xoắn
}
