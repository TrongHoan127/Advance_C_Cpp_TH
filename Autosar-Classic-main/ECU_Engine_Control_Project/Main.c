#include "Os.h"
#include "Torque_Control.h"
#include "Speed_Control.h"
#include <stdio.h>

// Task để khởi tạo và cập nhật hệ thống điều khiển mô-men xoắn
void* Task_TorqueControl(void* arg) {
    // Gọi hàm khởi tạo Torque Control
    TorqueControl_Init();

    // Liên tục cập nhật hệ thống điều khiển mô-men xoắn
    while (1) {
        TorqueControl_Update();
        
        // Tạm dừng 1 giây trước khi cập nhật tiếp
        Os_Delay(1000);
    }

    return NULL;
}
// Task để khởi tạo và cập nhật hệ thống điều khiển tốc độ động cơ
void* Task_SpeedControl(void* arg) {
    // Gọi hàm khởi tạo Torque Control
    SpeedControl_Init();

    // Liên tục cập nhật hệ thống điều khiển tốc độ động cơ
    while (1) {
        SpeedControl_Update();
        
        // Tạm dừng 1 giây trước khi cập nhật tiếp
        Os_Delay(1000);
    }

    return NULL;
}

int main(void) {
    // Khởi tạo hệ điều hành
    Os_Init();

    // Tạo task chung cho Torque Control (khởi tạo + cập nhật)
    Os_CreateTask(Task_TorqueControl, "Torque Control");
    Os_CreateTask(Task_SpeedControl, "Speed Control");
    // Chờ các task hoàn thành
    Os_Shutdown();

    return 0;
}
