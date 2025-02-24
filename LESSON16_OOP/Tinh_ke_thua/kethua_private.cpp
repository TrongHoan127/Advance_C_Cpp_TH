#include<iostream>
#include <string>
#include <cctype>
using namespace std;
// tạo 1 class mới gom các biến chung của các class vào
class doituong{
    private:// kế thừa private
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
        cout << "ten:"<<getname()<<endl;
        cout << "id:"<<getid()<<endl;}
};
class SinhVien : public doituong
{
    public:
        
    string chuyenNganh;
    void display() { // over load : load lại
        cout << "ten:"<<getname()<<endl;
        cout << "id:"<<getid()<<endl;
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
}