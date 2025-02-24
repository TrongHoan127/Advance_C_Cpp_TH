#include "IoHwAb_MotorDriver.h"
#include "Pwm.h"  // Gọi API PWM từ MCAL
#include <stdio.h>
#include <stdlib.h>

// Giả lập cấu hình MotorDriver
static MotorDriver_ConfigType MotorDriver_CurrentConfig;

// Hàm khởi tạo MotorDriver với cấu hình
Std_ReturnType IoHwAb_MotorDriver_Init(const MotorDriver_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_MotorDriver_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình MotorDriver
    MotorDriver_CurrentConfig.Motor_Channel = ConfigPtr->Motor_Channel;
    MotorDriver_CurrentConfig.Motor_MaxTorque = ConfigPtr->Motor_MaxTorque;
    MotorDriver_CurrentConfig.Motor_MaxSpeed = ConfigPtr->Motor_MaxSpeed;
    // Gọi API từ MCAL để khởi tạo PWM
    Pwm_ConfigType pwmConfig = {
        .Pwm_Channel = MotorDriver_CurrentConfig.Motor_Channel,
        .Pwm_Period = 1000, // 1 giây (1000ms)
        .Pwm_DutyCycle = 0  // Khởi tạo với duty cycle = 0%
    };
    Pwm_Init(&pwmConfig);

    // In ra thông tin cấu hình MotorDriver
    printf("Motor Driver Initialized with Configuration:\n");
    printf(" - Motor Channel: %d\n", MotorDriver_CurrentConfig.Motor_Channel);
    printf(" - Max Torque: %d Nm\n", MotorDriver_CurrentConfig.Motor_MaxTorque);
    printf(" - Motor Channel: %d\n", MotorDriver_CurrentConfig.Motor_Channel);
    printf(" - Max Motor Speed: %d vong/p\n", MotorDriver_CurrentConfig.Motor_MaxSpeed);

    return E_OK;
}

// Hàm điều chỉnh mô-men xoắn mô-tơ
Std_ReturnType IoHwAb_MotorDriver_SetTorque(float TorqueValue) {
    // Kiểm tra giá trị mô-men xoắn hợp lệ
    if (TorqueValue < 0.0f || TorqueValue > MotorDriver_CurrentConfig.Motor_MaxTorque) {
        printf("Error: Torque value %.2f Nm out of range (Max: %d Nm).\n", TorqueValue, MotorDriver_CurrentConfig.Motor_MaxTorque);
        return E_NOT_OK;
    }

    // Tính toán tỷ lệ nhiệm vụ (duty cycle) dựa trên mô-men xoắn
    uint16_t dutyCycle = (uint16_t)((TorqueValue / MotorDriver_CurrentConfig.Motor_MaxTorque) * 100);

    // Gọi API từ MCAL để cài đặt duty cycle của PWM
    Pwm_SetDutyCycle(MotorDriver_CurrentConfig.Motor_Channel, dutyCycle);

    // In ra giá trị mô-men xoắn đã đặt
    printf("Setting Motor Torque to %.2f Nm on Channel %d\n", TorqueValue, MotorDriver_CurrentConfig.Motor_Channel);

    return E_OK;
}
// Hàm điều chỉnh tốc độ động cơ
Std_ReturnType IoHwAb_MotorDriver_SetSpeed(float MotorSpeedValue) {
    // Kiểm tra giá trị mô-men xoắn hợp lệ
    if (MotorSpeedValue < 0.0f || MotorSpeedValue > MotorDriver_CurrentConfig.Motor_MaxSpeed) {
        printf("Error: Motor Speed value %.2f vong/p out of range (Max: %d vong/p).\n", MotorSpeedValue, MotorDriver_CurrentConfig.Motor_MaxSpeed);
        return E_NOT_OK;
    }

    // Tính toán tỷ lệ nhiệm vụ (duty cycle) dựa trên tốc độ động cơ
    uint16_t dutyCycle = (uint16_t)((MotorSpeedValue / MotorDriver_CurrentConfig.Motor_MaxSpeed) * 100);

    // Gọi API từ MCAL để cài đặt duty cycle của PWM
    Pwm_SetDutyCycle(MotorDriver_CurrentConfig.Motor_Channel, dutyCycle);

    // In ra giá trị tốc độ động cơ đã đặt
    printf("Setting Motor Torque to %.2f Nm on Channel %d\n", MotorSpeedValue, MotorDriver_CurrentConfig.Motor_Channel);

    return E_OK;
}
