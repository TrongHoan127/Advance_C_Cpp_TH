#include <stdio.h>
#include <stdint.h>

typedef struct  {
    uint32_t a;   // 4byte ,cấp phát bao nhiêu byte dựa vào theo kích thước thành phần: (biến) lớn nhất
    uint8_t b;  // 1 byte
    uint16_t c; // 2 byte   
}Example ;
// 4byte 1 lần cấp : 0xa0 0xa1 0xa2 0xa3 -> vừa đủ để lưu địa chỉ cho a
// tiếp theo cấp tiếp 4 ô: 0xa4 0xa5 0xa6 0xa7, chỉ có 0xa4 lưu địa chỉ cho b, 
//  0xa6 và 0xa7 đủ để cấp địa chỉ cho c (bắt đầu bằng địa chỉ chia hết cho 2) -> có 1 byte padding 0xa5
