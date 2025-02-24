#include<iostream>
#include <string>
#include <cctype>
using namespace std;
// tạo 1 class mới gom các biến chung của các class vào
class doituong{
    protected:// kế thừa protected
    string ten;
    int id;
    public:
    doituong()
    {
        static int newid=1;
        id = newid;
        newid++;
    }
    void setName(string newname)
    {// kiểm tra như bên đóng gói
        ten = newname;
    }
    string getname(){
        return ten;
    }
    int getid(){
        return id;
    }
    void display() { // over load : load lại
        cout << "ten:"<<ten<<endl;
        cout << "id:"<<id<<endl;}
};
class SinhVien : public doituong // sảy ra ở quá trình biên dịch -> compiler copy toàn bộ các biến hàm public và protected trừ private
{   private: string chuyenNganh;
    public:
        
    void setchuyennganh(string nganh)
    {
        chuyenNganh = nganh;
        
    }
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
    sv1.setName("hoan");
    sv1.display();
    //sv1.id = "hoan" sẽ bị sai vì biến được protected (k đc truy cập bởi object) nhưng biến đc sử dụng trong các class khác
}