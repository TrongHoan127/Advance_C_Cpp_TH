#include <iostream>
#include <string>
using namespace std;
//trong c++ đc cho viết nhiều hàm giống nhau cùng lúc
int sum(int a, int b)// 2 tham số int
{
    return a+b;
}
double sum (int a, int b, double c)// 3 tham số
{ 
    return a+b+c;
}
double sum (double a, double b)// 2 tham số double
{
    return a+b;
}
// sẽ dựa vào tham số để gọi hàm
int main()
{
    cout<< sum(1,2)<<endl;// 2 int -> tìm kiếm bao nhiêu tham số -> kiểm tra kdl để chọn hàm
    cout<< sum(1.5,3.6)<<endl;
    cout<< sum(1,2,3.5)<<endl;
    cout<< sum(1.5,2.5,3)<<endl; // 3 tham số -> tìm hàm 3 tham số -> khác kdl thì sẽ tự động ép kiểu 1.5 ép về 1, 2.5 ép về 2 để phù hợp với hàm
    return 0; // cách xác định này sảy ra trong quá trình biên dịch
}