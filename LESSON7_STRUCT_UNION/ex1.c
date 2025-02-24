#include <stdio.h>
#include <string.h> // Thêm thư viện cho strcpy
#include <stdlib.h> // Thêm thư viện cho malloc

// Cách 1: Dùng struct thông thường
struct student {
    char ten[50];
    int tuoi;
    int mssv;
};

struct student sv1, sv2; // Tạo hai đối tượng thuộc kiểu struct student

// Cách 2: Dùng typedef để đơn giản hóa cú pháp
typedef struct {
    char ten2[50]; // Không thể gán chuỗi trực tiếp, phải dùng strcpy
    int tuoi2;
    int mssv2;
} student2;

// Khai báo đối tượng
student2 *st2, st1;

int main() {
    // Gán chuỗi đúng cách
    student2 danhSachSV[] = {
    {.ten2 = "trong", .tuoi2 = 21, .mssv2 = 12345}
};
    

     //Cấp phát bộ nhớ cho con trỏ trước khi sử dụng
    st2 = &st1;  // Hoặc dùng malloc nếu cần cấp phát động
    st2->tuoi2 = 20;

    printf("Tuoi: %d\n", st2->tuoi2);

    return 0;
}
