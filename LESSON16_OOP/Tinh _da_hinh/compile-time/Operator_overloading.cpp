#include <iostream>
// nhưng các biến đc tạo bởi kdl tự tạo như class hay struct thì phải định nghĩa lại toán tử để sử dụng
using namespace std;
class complex 
{
private:
    double real;// thực
    double imag; // ảo
public:
complex(double r=0, double i=0): real(r),imag(i)
{}// constructor
    complex operator + (complex orther) // theo cú pháp
    {
        complex c;
        c.real = complex :: real + orther. real ;// cách 1
        c.imag = this -> imag + orther. imag;// cách 2
        return c;
    }
    complex operator - (complex tru)
    {
        complex t;// object trung gian để lưu trữ
        t.real = complex :: real - tru.real;
        t.imag = this ->real - tru.imag; // con trỏ this của complex operator
        return t;
    }
    bool operator == (complex orther)
    {
        return (this->real == orther.real&& this->imag == orther.imag);
    }// đúng trả true
    void display(){
        cout<< real << "+ "<< imag <<"i"<<endl;
    }
};
int main()
{   complex c1(1,2); // 1+2i
    complex c2(3,4);
    complex c3; // 0+0i
    complex c4;
    // c3 = c1+c2; wrong vì chưa định nghĩa
    //int a = 10;// biến thông thường sẽ đc dùng toán tử
    c3 = c1+c2;
    c4 = c1+c2+c3;// c1+c2 trước theo hàm định nghĩa r mới cộng c3
    c1.display();
    c2. display();
    c3.display();
    c4.display();
    if(c1 == c2)
    { cout<< "c1 = c2";}else {
        cout<<"c1 khac c2";
    }
    return 0;
}