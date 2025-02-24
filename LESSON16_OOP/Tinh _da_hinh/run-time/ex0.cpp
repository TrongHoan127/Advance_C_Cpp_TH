#include<iostream>
#include <string>
using namespace std;
// tạo 1 class mới gom các biến chung của các class vào
class doituong{
    public:// kế thừa public
    string ten;
    int id;
    void display()
    {
        cout << "ten:"<<ten<<endl;
        cout << "id:"<<id<<endl;
    }
    

};
class SinhVien : public doituong
{
    public:
    //overload: kế thừa, đa hình tại trình phiên dịch
    string chuyenNganh;// C++ có thể đc 2 method giống nhau, nạp chồng hàm:overload, có quy luật
     // các class khác đều có và là hàm được viết sau nên k đc gọi
    
    // có 2 method display, 1 là display của đối tượng đc kế thừa, 2 là display riêng của sinh viên (nạp chồng hàm)
    void display() { // ưu tiên hàm display vừa mới viết ra hơn
        cout << "ten:"<<ten<<endl;
        cout << "id:"<<id<<endl;
        cout << "chuyennganh:" << chuyenNganh << endl;// 
    }
};

class HocSinh :public doituong
{
    public:
      
        string lop;
};

class GiaoVien: public doituong
{
    public:
       
        string chuyenMon;
};
int main()
{
    SinhVien sv1;
    
sv1.id = 1;// kế thừa id
sv1.chuyenNganh = "oto";// k nên dùng truy cập trực tiếp nên sẽ dùng private
sv1.display();// ưu tiên gọi ra cái chỉ riêng class sv có, vì sv1 thuộc class sv nên sẽ gọi ra có chuyên ngành
// test cách gọi 2 hàm display
doituong *dt;// dt con trỏ thuộc kiểu đối tượng
dt = &sv1;
dt ->display();// nên khi trỏ sẽ chỉ ra được hàm display thường ở class đối tượng
}// nếu muốn đã trỏ với sv1 phải gọi ra đc display của sv1 thì phải dùng virtual