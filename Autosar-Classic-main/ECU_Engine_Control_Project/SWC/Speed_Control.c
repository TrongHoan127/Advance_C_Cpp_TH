#include "Rte_SpeedControl.h"   
#include "Speed_Control.h"
#include <stdio.h>  // Thư viện cho printf

// Hàm khởi tạo hệ thống điều khiển tốc độ động cơ
void SpeedControl_Init(void) {
    // Khởi tạo các cảm biến bàn đạp ga, tốc độ và tải trọng
    Std_ReturnType status;

    printf("Khởi tạo hệ thống Torque Control...\n");

    // Khởi tạo cảm biến bàn đạp ga
    status = Rte_Call_RpThrottleSensor_Init();
    if (status == E_OK) {
        printf("Cảm biến bàn đạp ga đã khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo cảm biến bàn đạp ga.\n");
        return;
    }

    // Khởi tạo cảm biến tốc độ động cơ thực tế
    status = Rte_Call_RpMotorSpeedSensor_Init();
    if (status == E_OK) {
        printf("Cảm biến tốc độ động cơ thực tế đã khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo cảm biến tốc độ.\n");
        return;
    }


    // Khởi tạo cảm biến dòng điện
    status = Rte_Call_RpCurrentSensor_Init();
    if (status == E_OK) {
        printf("Cảm biến dòng điện đã khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo cảm biến dòng điện.\n");
        return;
    }

    // Khởi tạo bộ điều khiển tốc độ động cơ (có thể là PWM hoặc module điều khiển động cơ)
    status = Rte_Call_PpMotorDriver_Init();
    if (status == E_OK) {
        printf("Bộ điều khiển tốc độ động cơ đã khởi tạo thành công.\n");
    } else {
        printf("Lỗi khi khởi tạo bộ điều khiển tốc độ động cơ.\n");
        return;
    }

    printf("Hệ thống Speed Control đã sẵn sàng.\n");
}

// Hàm cập nhật hệ thống điều khiển tốc độ động cơ
void SpeedControl_Update(void) {
    float throttle_input = 0.0f;
    float  current_input = 0.0f;
    float actual_speed = 0.0f;
    float desired_speed = 0.0f;
    float current_output = 0.0f;
    // Đọc dữ liệu từ cảm biến bàn đạp ga
    if (Rte_Read_RpThrottleSensor_ThrottlePosition(&throttle_input) == E_OK) {
        printf("Giá trị bàn đạp ga: %.2f%%\n", throttle_input * 100);
    } else {
        printf("Lỗi khi đọc cảm biến bàn đạp ga!\n");
    }

    // Đọc dữ liệu từ cảm biến dòng điện
    if (Rte_Read_RpCurrentSensor_Speed(&current_input) == E_OK) {
        printf("Dòng điện cấp cho động cơ hiện tại: %.2f A\n", current_input);
    } else {
        printf("Lỗi khi đọc cảm biến dòng điện!\n");
    }


    // Tính toán tốc độ theo yêu cầu
    if (throttle_input < 50.0f) {
        current_output = current_input*0.7f;  // Giảm cung cấp dòng điện nếu đạp ga nhỏ
    } else { current_input += 10.0f;}
    if (current_input > 50.0f) {
        current_output = current_input - 30.0f;  // giảm lại dòng điện cung cấp nếu trong động cơ dòng điện quá lớn 
    }
    desired_speed = current_output * MAX_SPEED;
    // Giới hạn tốc độ trong phạm vi an toàn
    if (desired_speed > MAX_SPEED) {
        desired_speed = MAX_SPEED;
    } else if (desired_speed < MIN_SPEED) {
        desired_speed = MIN_SPEED;
    }

    // In ra tốc độ yêu cầu
    printf("tốc độ yêu cầu: %.2f vòng/p\n", desired_speed);

    // Ghi tốc độ động cơ yêu cầu tới bộ điều khiển động cơ
    if (Rte_Write_PpMotorDriver_SetSpeed(desired_speed) == E_OK) {
        printf("Đã gửi tốc độ yêu cầu tới động cơ.\n");
    } else {
        printf("Lỗi khi gửi tốc độ yêu cầu tới động cơ!\n");
    }

    // Đọc tốc độ động cơ thực tế để so sánh với tốc độ yêu cầu
    if (Rte_Read_RpMotorSpeedSensor_ActualSpeed(&actual_speed) == E_OK) {
        printf(" tốc độ động cơ thực tế: %.2f vòng/p\n", actual_speed);
    } else {
        printf("Lỗi khi đọc tốc độ động cơ thực tế!\n");
    }

    // So sánh và điều chỉnh nếu có sự sai lệch giữa tốc độ động cơ thực tế và yêu cầu
    if (actual_speed < desired_speed) {
        printf("Tăng tốc độ động cơ để đạt mức yêu cầu.\n");
    } else if (actual_speed > desired_speed) {
        printf("Giảm tốc độ động cơ để đạt mức yêu cầu.\n");
    }
}
