 #include <stdio.h>
#include <setjmp.h>

jmp_buf buf1;  // buf sẽ có kiểu dữ liệu jmp_buf biến này có chức năng lưu lại trạng thái

enum ErrorCodes { // LỖI:0,1,2,3
    NO_ERROR,        // Không có lỗi
    FILE_ERROR,      // Lỗi đọc file
    NETWORK_ERROR,   // Lỗi mạng
    CALCULATION_ERROR // Lỗi tính toán
};

int exception;
char error_message[50];  // Biến lưu thông báo lỗi

// Macro để thực hiện cơ chế TRY-CATCH
#define TRY if ((exception = setjmp(buf1)) == 0)  
#define CATCH(X) else if (exception == X)
#define THROW(X, e_msg) {snprintf(error_message, sizeof(error_message), "%s", e_msg);longjmp(buf1, X); }

// Các hàm thực hiện các hoạt động cụ thể

void readFile() {
    printf("Đọc file...\n");
    int file = 0 ;// Mở file không tồn tại
    if (file == 0) {
        THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
       }
                            
}

void networkOperation() {
    printf("Thực hiện kết nối mạng...\n");
   // Giả lập lỗi mạng, ví dụ: không thể kết nối tới máy chủ
    int network_status = 0;  // 0: Kết nối không thành công, 1: Kết nối thành công
    if (network_status == 0) {
        THROW(NETWORK_ERROR, "Lỗi kết nối mạng: Không thể kết nối đến máy chủ.");
    }
}

double divide(int a, int b) {
    printf("Đang thực hiện phép chia %d / %d...\n", a, b);
    
    // Giả lập lỗi phép tính: nếu chia cho 0
    if (b == 0) {
        THROW(CALCULATION_ERROR, "Lỗi tính toán: Chia cho 0.");
    }
    
    return (double)a / b;
}

int main() {
        int a = 10, b = 0;
    TRY {
        readFile();           // Gọi hàm đọc file
        networkOperation();   // Gọi hàm kết nối mạng
        divide(a,b);      // Gọi hàm tính toán
    }
    CATCH(FILE_ERROR) {
        printf("Lỗi: %s\n", error_message);  // Xử lý lỗi đọc file
    }
    CATCH(NETWORK_ERROR) {
        printf("Lỗi: %s\n", error_message);  // Xử lý lỗi kết nối mạng
    }
    CATCH(CALCULATION_ERROR) {
        printf("Lỗi: %s\n", error_message);  // Xử lý lỗi tính toán
    }

    printf("Chương trình kết thúc an toàn.\n");  // Thông báo kết thúc chương trình

    return 0;
}