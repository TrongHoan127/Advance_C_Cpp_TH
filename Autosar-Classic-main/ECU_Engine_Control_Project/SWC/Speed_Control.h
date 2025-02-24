#ifndef SPEED_CONTROL_H
#define SPEED_CONTROL_H

// Định nghĩa tốc độ động cơ tối đa và tối thiểu
#define MAX_SPEED 2500.0f
#define MIN_SPEED 0.0f

// Khai báo các hàm chính cho Speed Control
void SpeedControl_Init(void);   // Hàm khởi tạo hệ thống điều khiển TỐC ĐỘ
void SpeedControl_Update(void); // Hàm cập nhật hệ thống điều khiển TỐC ĐỘ

#endif // SPEED_CONTROL_H