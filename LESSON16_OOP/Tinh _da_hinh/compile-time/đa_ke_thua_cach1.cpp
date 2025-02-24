#include <iostream>

using namespace std;

class A{// class cơ sở
    public:
        A(){ cout << "Constructor A\n"; }

        void hienThiA(){ cout << "Day la lop A\n"; }
};

class B : public A{
    public:
        B(){ cout << "Constructor B\n"; }

        void hienThiB(){ cout << "Day la lop B\n"; }
};

class C : public A {
    public:
        C(){ cout << "Constructor C\n"; }

        void hienThiC(){ cout << "Day la lop C\n"; }
};

class D : public B, public C{
    public:
        D(){ cout << "Constructor D\n"; }

        void hienThiD(){ cout << "Day la lop D\n"; }
};

int main() {
    D d;// class D có 2 phiên bản class A nên object d k biết gọi từ B hay C
    // constructor cũng có 2 phiên bản nhưng nó tự động chạy khi gọi object nên sẽ k báo lỗi
    // d.hienThiA(); // wrong
    // d.A::hienThiA();// wrong vì D k đc kế thừa trực tiếp từ A
    // Gọi phương thức từ lớp A qua B và C
    d.B::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua B; truy xong gọi hàm
    d.C::hienThiA(); // Gọi hàm hienThiA từ lớp A thông qua C

    // d.hienThiB();
    // d.hienThiC();
    // d.hienThiD();

    return 0;
}


