#include <stdio.h>
#include "IoHwAb_CurrentSensor.h"
#include "Adc.h"    // Gọi API từ MCAL để đọc giá trị từ ADC


// Giả lập cấu hình của cảm biến dòng điện
static CurrentSensor_ConfigType CurrentSensor_CurrentConfig;

// Hàm khởi tạo cảm biến dòng điện
Std_ReturnType IoHwAb_LoadSensor_Init(const CurrentSensor_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_LoadSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến dòng điện vào biến toàn cục
    CurrentSensor_CurrentConfig.CurrentSensor_Channel = ConfigPtr->CurrentSensor_Channel;
    CurrentSensor_CurrentConfig.CurrentSensor_MaxValue = ConfigPtr->CurrentSensor_MaxValue;

    // Gọi API từ MCAL để khởi tạo ADC
    Adc_ConfigType adcConfig;
    adcConfig.Adc_Channel = ConfigPtr->CurrentSensor_Channel;
    Adc_Init(&adcConfig);

    // In ra thông tin cấu hình cảm biến dòng điện
    printf("Current Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", CurrentSensor_CurrentConfig.CurrentSensor_Channel);
    printf(" - Max Current Value: %d A\n", CurrentSensor_CurrentConfig.CurrentSensor_MaxValue);
    return E_OK;
}

// Hàm đọc giá trị từ cảm biến dòng điện
Std_ReturnType IoHwAb_Sensor_Read(float* CurrentValue) {
    if (CurrentValue == NULL) {
        return E_NOT_OK;  // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị ADC từ MCAL
    uint16_t adcValue = 0;
    if (Adc_ReadChannel(CurrentSensor_CurrentConfig.CurrentSensor_Channel, &adcValue) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị ADC sang giá trị điện áp (A)
    *CurrentValue = ((float)adcValue / 1023.0f) * CurrentSensor_CurrentConfig.CurrentSensor_MaxValue;

    // In ra giá trị tải trọng
    printf("Current Sensor (ADC Channel %d): Current = %.2f A\n",
            CurrentSensor_CurrentConfig.CurrentSensor_Channel, *CurrentValue);

    return E_OK;
}
