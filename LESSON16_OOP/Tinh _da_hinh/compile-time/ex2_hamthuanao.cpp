#include <iostream>

class DT 
{ //khi trong quá trình compiler, class này sẽ biến mất vì những class con kế thừa sẽ định nghĩa lại
    public:// tất cả những method là method ảo thì sẽ biến mất class khi biên dịch
    virtual void func1()=0; // hàm thuần ảo
    virtual void func2()= 0;
};// nếu có biến thì sẽ k bị xóa đi or method có nội dung