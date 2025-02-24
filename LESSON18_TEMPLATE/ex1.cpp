#include<iostream>
using namespace std; 
// int sum(int a, int b) // điểm chung: cùng tính tổng,2 tham số truyền vào cùng kdl, khác: khác kdl của tham số
// {
//     return a+b;
// }
// double sum(double a, double b) // vậy có thể gộp hàm k? => viết tổng quát
// {
//     return a+b;
// }
template <typename T> // cho phép định nghĩa kdl chung; k xác định trước tùy vào từng trường hợp
T sum(T a, T b )// hàm tổng quát cho vừa int vừa double
{
    return a+b; // tự xác định nhờ các giá trị truyền vào
}
template <typename T1, typename T2> // sẽ dùng đc cho sum (int,double)
T1 sum(T1 a, T2 b)
{
    return a+b;
}
int main()
 {
//sum(1,2); // tự hiểu T là int
//sum(2.2,3.4); // double T, hiểu ở trình phiên dịch
cout<< "tong la "<<sum(2.2,3.4)<<endl;
cout << sum(1,2.2) << endl; // 1 int,1 double sẽ lỗi nếu dùng chỉ 1 T, kết quả ra sẽ ép kiểu giống a
     return 0 ;
 }