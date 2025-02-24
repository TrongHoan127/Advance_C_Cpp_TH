#include <stdio.h>
#include "calculation.h"
int main()
{
 Equation ketqua;

    inputCoefficients(1,2,3); // chỉ thấy đc các hàm k có static
    result(&ketqua) ;// static toàn cục giúp giấu đi quá trình trung gian
    printf("x1 = %f\n",ketqua.x1 );
    printf("x2 = %f\n", ketqua.x2);
return 0;
}