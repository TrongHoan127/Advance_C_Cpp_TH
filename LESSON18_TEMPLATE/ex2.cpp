#include<iostream>
using namespace std; 
template <typename T> // cho phép định nghĩa kdl chung; k xác định trước tùy vào từng trường hợp
T sum(T a, T b )// hàm tổng quát cho vừa int vừa double
{
    return a+b; // tự xác định nhờ các giá trị truyền vào
}
template <typename T1, typename T2> // sẽ dùng đc cho sum (int,double)
auto sum(T1 a, T2 b) // dùng auto thay cho T, chỉ có ý nghĩa trong C++ , để xđ kiểu dl, kiểu trả về của 1 hàm
{// tự suy diễn kdl
    return a+b;
}
int main()
 {
    auto x = 5; // tự hiểu kdl khi dùng auto
    auto z = "hello word" ; // tự hiểu kdl
//sum(1,2); // tự hiểu T là int
//sum(2.2,3.4); // double T, hiểu ở trình phiên dịch
cout<< "tong la "<<sum(2.2,3.4)<<endl;
cout << sum(1,2.2) << endl; // dùng auto nên sẽ trả về số thực thay vì phải ép kdl theo T
     return 0 ;
 }