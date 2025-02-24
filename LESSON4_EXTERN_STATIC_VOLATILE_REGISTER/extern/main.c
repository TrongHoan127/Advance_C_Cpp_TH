#include<stdio.h>
//#include"file1.c" //(casch1 nhưng khi include trùng file sẽ lỗi biến )
//#include"file2.c"
//cách 2: dùng extern
//extern int a;
//extern int b;

//extern void display1(); //chỉ khai báo k khai nội dung
//extern void display2();
// cách 3: dùng include file .h vào
#include "file1.h"
#include "file2.h"

int main(int argc, char const *argv[])
{
    a =20;
    printf("a=%d\n",a);

    b =50;
    printf("b=%d\n",b);

    display1();
    display2();
    return 0;
}