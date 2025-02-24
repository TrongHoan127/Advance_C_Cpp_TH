#include <stdio.h>
#include <stdint.h>
// tất cả thành phần dùng chung 1 vùng nhớ cao nhất là 4byte
typedef union {
    uint8_t a; 
    uint16_t b;
    uint32_t c;//4byte
    // bộ nhớ chỉ cấp phát 4 byte cho 3 tp đều sử dụng chung 0xa0 0xa1 0xa2 0xa3
}Data ;
int main()
{
    Data Example;
     printf("sizeof Example:%d\n", sizeof(Example));
     return 0;
}