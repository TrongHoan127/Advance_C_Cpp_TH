#include <iostream>
using namespace std;
void modifyByPointer(int *ptr)// cách tham chiếu này sẽ tốn 1 địa chỉ để cấp phát cho con trỏ
{
    *ptr = 30;
}
void modifyByReference (int &ref)
{
    ref = 100;
}

int main()
{
    int x = 10;
    modifyByPointer(&x);
    modifyByReference(x); // chỉ truyền vào tên của biến vì đã &ref ở trên
    cout << x << endl;// x thay đổi theo ref vì đã truyền địa chỉ vào
    // use trực tiếp
   // int &ref = x; // k tốn vùng nhớ trên ram và lấy giá trị cũng như địa chỉ của biến x
    return 0;
}