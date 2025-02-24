#include "IoHwAb_MotorSpeedSensor.h"
#include "Adc.h"   // Gọi API từ MCAL để đọc giá trị từ ADC
#include <stdio.h>
#include <stdlib.h>

// Giả lập cấu hình của cảm biến tốc độ
static MotorSpeedSensor_ConfigType MotorSpeedSensor_CurrentConfig;

// Hàm khởi tạo cảm biến tốc độ với cấu hình
Std_ReturnType IoHwAb_SpeedSensor_Init(const MotorSpeedSensor_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_MotorSpeedSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến tốc độ vào biến toàn cục
    MotorSpeedSensor_CurrentConfig.MotorSpeedSensor_Channel = ConfigPtr->MotorSpeedSensor_Channel;
    MotorSpeedSensor_CurrentConfig.MotorSpeedSensor_MaxValue = ConfigPtr->MotorSpeedSensor_MaxValue;

    // Gọi API từ MCAL để khởi tạo ADC
    Adc_ConfigType adcConfig;
    adcConfig.Adc_Channel = ConfigPtr->MotorSpeedSensor_Channel;
    Adc_Init(&adcConfig);

    // In ra thông tin cấu hình cảm biến tốc độ động cơ
    printf("Speed Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", MotorSpeedSensor_CurrentConfig.MotorSpeedSensor_Channel);
    printf(" - Max Motor Speed Value: %d vong/p\n", MotorSpeedSensor_CurrentConfig.MotorSpeedSensor_MaxValue);

    return E_OK;
}

// Hàm đọc giá trị từ cảm biến tốc độ
Std_ReturnType IoHwAb_MotorSpeedSensor_Read(float* MotorSpeedValue) {
    if (MotorSpeedValue == NULL) {
        return E_NOT_OK;  // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị từ kênh ADC
    uint16_t adcValue = 0;
    if (Adc_ReadChannel(MotorSpeedSensor_CurrentConfig.MotorSpeedSensor_Channel, &adcValue) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị ADC sang tốc độ (giả lập)
    *MotorSpeedValue = ((float)adcValue / 1023.0f) * MotorSpeedSensor_CurrentConfig.MotorSpeedSensor_MaxValue;

    // In ra giá trị tốc độ động cơ
    printf("Reading Motor Speed Sensor (ADC Channel %d): Motor Speed = %.2f vong/p\n",
           MotorSpeedSensor_CurrentConfig.MotorSpeedSensor_Channel, *MotorSpeedValue);

    return E_OK;
}
