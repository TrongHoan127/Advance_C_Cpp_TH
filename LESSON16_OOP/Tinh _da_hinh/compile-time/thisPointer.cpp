#include <iostream>
#include <string>
using namespace std;
class Person
{
    private:
        string name;
        int age;
        int id;
    public:
    Person()
    {
        static int newID = 0;
        newID ++;
        this ->id = newID;
        //this = nullptr;// lỗi: hằng con trỏ k cho phép thay đổi đối tượng
    }
    void setName(string newName){   // setter method : hàm lấy dl
        // kiểm tra điều kiện, kiểm tra chuỗi có kí tự lạ hay k
       this->name = newName;
    }
    
    string getName(){   // getter method: hàm trả về, xuất ra dữ liệu
        return this ->name;
    }

    int getID(){
        return this ->id;
    }

    void display(){
        cout << "Ten: " << this -> getName() << endl;
        cout << "ID: " << this -> getID() << endl;
    }
    void showaddr(){
        cout<<"dia chi la"<<this<<endl;
    }
};

int main(int argc, char const *argv[])
{
Person sv1;// tự tạo ra 1 con trỏ this =& sv1
Person sv2; // this2 =& sv2
// sv1.setName("Trung");
// sv1.display();
cout <<"addr of object 1:"<< &sv1<<endl;
sv1.showaddr();
cout <<"addr of object 2:"<< &sv2<<endl;
sv2.showaddr();
sv1.setName("hoan123@");
sv1.display();
return 0;
}




