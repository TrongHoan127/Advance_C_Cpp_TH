#include<iostream>
#include<string.h>
using namespace std;

class sinhvien  {
    public:
    string name;
    int id;
    
    sinhvien(string newName){
        static int ID = 1;
        id = ID;
        ID ++;
        name = newName;
    }
    void display(){
        cout <<"ten:" << name << endl;
        cout << "id:" << id <<  endl;
    }
    };
int main(int argc, char const *argv[])
{ //cách 1:
    sinhvien sv1("hoan"), sv2("thu"); // chưa giải quyết đc trường hợp vào tên"anh123@""
sv1.display();// khi bỏ dữ liệu trong public, ngdung đc truy cập thoải mái, nên có thể ghi lại dữ liệu -> ảnh hưởng đến chương trình
sv2.display();
sv1.id = 2; // k giải quyết đc trùng id, vì dữ liệu đc ghi lại từ hàm main
sv1.display(); // => để dữ liệu xử lí trong phạm vi private
//
return 0 ;
}
