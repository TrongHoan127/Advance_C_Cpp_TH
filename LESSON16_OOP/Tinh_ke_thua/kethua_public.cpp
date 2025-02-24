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
        
    string chuyenNganh;
    void display() { // over load : load lại
        cout << "ten:"<<ten<<endl;
        cout << "id:"<<id<<endl;
        cout << "chuyennganh:" << chuyenNganh << endl;// viết thêm để đủ chức năng khi thừa kế
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
sv1.display();

}