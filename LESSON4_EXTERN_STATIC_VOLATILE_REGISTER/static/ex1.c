#include <stdio.h>
void count()
{ // 
     
    //int a=5;// Stack cấp phát 1 địa chỉ cho biến cục bộ, sau khi kết thúc hàm sẽ thu hồi địa chỉ
    static int a=5; //static cục bộ, nằm ở phân vùng BSS, nếu gt=0 thì ở data
    printf("a= %d\n",a++);// in ra a trước rồi mới cộng a

}
int main()
{
    count(); // nếu có static thì sẽ cấp phát địa chỉ cho biến 1 lần và sử dụng xuyên suốt 
    count(); // 7
    count(); // 8
    return 0 ;
}