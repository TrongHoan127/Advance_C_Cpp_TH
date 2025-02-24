#include <iostream>
#include <string>
#include <cctype> // isdigit: kiểm tra ký tự có phải số, isalpha: kiểm tra ký tự có phải chữ cái
using namespace std;

class SinhVien{
    private:
        string name;
        int id;
        bool isValidName (string str) // hello123@ và kí tự null phía cuối nên length() = 10
        { // tính trừu tượng giống static toàn cục bên c (đóng gói thuật toán và logic trung gian trước khi đưa ra lq cuối cùng)
            for(int i=0; i<str.length(); i++)
            {
                if(isdigit(str[i])|| !isalpha(str[i]))
                {
                    return false;
                } 
        }
        return true;      
            } 
        
    public:
        SinhVien(){
            static int ID = 1;// dùng static để sv1 và sv2 cùng nhau truy cập tới 1 địa chỉ biển ID, dẫn đến k trùng lập ID
            id = ID;
            ID++;// cơ chế cho id tự động khác nhau
        }

        void setName(string newName){   // setter method : hàm lấy dl
            // kiểm tra điều kiện, kiểm tra chuỗi có kí tự lạ hay k
           
            if (isValidName(newName))
            { name = newName;}
            else{
                cout<< "tên không hợp lệ"<<endl;
            }
        }
        
        string getName(){   // getter method: hàm trả về, xuất ra dữ liệu
            return name;
        }

        int getID(){
            return id;
        }

        void display(){
            cout << "Ten: " << getName() << endl;
            cout << "ID: " << getID() << endl;
        }
};

int main(int argc, char const *argv[])
{
    SinhVien sv1, sv2;

   // sv1.setName("Trung");
   // sv1.display();

    sv2.setName("Anh");
    sv2.display();
    sv1.setName("hoan123@");
    sv1.display();
    return 0;
}


