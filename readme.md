# Advance_C_Cpp
<details><summary>LESSON 1: COMPILER - MARCO</summary>
    <p>
        
## LESSON 1: COMPILER - MARCO
### Compiler
- Trong ngôn ngữ lập trình, Compiler (trình phiên dịch) là chương trình có nhiệm vụ xử lý chương trình ngôn ngữ bậc cao thành ngôn ngữ bậc thấp hơn để máy tính thực thi.
- Quá trình biên dịch gồm các giai đoạn như sau:
![maxresdefault](https://github.com/user-attachments/assets/3fbcf4bf-b3b6-41e9-8d26-e33c72ee3287)
#### Preprocessor (Tiền xử lý)
- Bộ tiền xử lý có nhiệm vụ thực hiện: 
    - Nhận mã nguồn, source code (gồm: c, .h, .cpp, .hpp,...)
    - Xóa bỏ tất cả các chú thích, comments của chương trình
    - Chỉ thị tiền xử lý ( bằng dấu #) cũng được xử lý
    - Đầu ra là file i
       ```c
       gcc -E main.c -o main.i
 #### Compiler 
 - Chuyển từ ngôn ngữ bậc cao sang ngôn ngữ bậc thấp assembly. Đầu vào là file .i, đầu ra file .s.
    ```c
    gcc main.i -S -o main.s
#### Assembler 
- Chuyển sang mã máy (0,1). Đầu vào là file .s, đầu ra là file .o hay còn gọi là file object.
  ```c
    gcc - c main.s -o main.o
#### Linker
- Liên kết các file object.o lại thành một chương trình duy nhất.
  ```c
     gcc test1.o test2.o main.o -o main
### Macro
- Chỉ thị tiền xử lý là những chỉ thị cung cấp cho bộ tiền xử lý các thông tin trước khi quá trình phiên dịch bắt đầu. Các chỉ thị tiền xử lý bắt đầu bằng ký tự #
   - #include (file header): Chèn nội dung của file vào vị trí mình chỉ định vào file i. Giúp chương trình dễ quản lí
     ```c
     #include <stdio.h>
     #include "test1.h"
   - #define: Được sử dụng để định nghĩa các hằng số hoặc các đoạn mã thay thế, không có kiểu dữ liệu. Việc sử dụng #define để định nghĩa được gọi là Macro, nơi nào có tên Macro sẽ được thay thế bằng nội dung của Macro đó
  - Ví dụ 1:
	 ```c
    	 #include <stdio.h>
		#define PI 3.14 // Định nghĩa hằng số Pi sử dụng #define//
		int main() {
		double radius = 5.0; // Sử dụng hằng số Pi trong chương trình //
		double area = PI * radius * radius;
	
		printf("Radius: %.2f\n", radius);
		printf("Area of the circle: %.2f\n", area);
	
		return 0;
		}
  - Ví dụ 2:
   	  ```c
   	  #include <stdio.h>

		// Định nghĩa macro để tìm số lớn hơn giữa hai số
		#define MAX(x, y) ((x) > (y) ? (x) : (y))
		
		int main() {
		int a = 10, b = 20;
		
		// Sử dụng macro để tìm số lớn hơn giữa a và b
		int maxNumber = MAX(a, b);
		
		printf("The bigger number between %d and %d is: %d\n", a, b, maxNumber);
		
		return 0;
		}
  - #undef: Để hủy định nghĩa một #define đã được định nghĩa trước đó.
    ```c
    #include <stdio.h>
	#define MAX_SIZE 100
	
	int main() {
	    printf("MAX_SIZE is defined as: %d\n", MAX_SIZE);
	    
	    // Bỏ định nghĩa của MAX_SIZE
	    #undef MAX_SIZE
	    
	    // Định nghĩa lại MAX_SIZE với giá trị khác
	    #define MAX_SIZE 50
	    
	    printf("MAX_SIZE is now redefined as: %d\n", MAX_SIZE);
	
	return 0;
	}
  - #if, #elif, #else: Kiểm tra điều kiện của Marco.
  	- #if: Sử dụng để bắt đầu 1 điều kiện xử lý.Nếu đúng thì các dòng lệnh sau #if sẽ được biên dịch , sai sẽ bỏ qua đến khi gặp #endif.
	- #elif: Để thêm 1 ĐK mới khi #if hoặc #elif sai.
	- #else: Dùng khi không có ĐK nào đúng
	- #ifdef: Dùng để kiểm tra 1 macro định nghĩa hay chưa.Nếu định nghĩa rồi thì mã sau ifdef sẽ được biên dịch.
	- #ifndef: Dùng để kiểm tra 1 macro định nghĩa hay chưa.Nếu chưa định nghĩa thì mã sau #ifndef sẽ được biên dịch.Thường dùng để kiểm tra macro đó đã dc định nghĩa trong file nào chưa, kết thúc thì #endif
   - Ví dụ 1:
	    ```c
	    #include <stdio.h>
		// Định nghĩa một macro
		#define VERSION 3
		
		int main() {
		    // Sử dụng #if, #elif, #else
		    #if VERSION == 1                               // Điều kiện #if sai, nếu không còn kiểm tra điều kiện nào
		                                                    // nữa đi tới #endif luôn
		    printf("This is version 1.\n");
		    #elif VERSION == 2                             // Tiếp tục kiểm tra với #elif
		    printf("This is version 2.\n");            
		    #else                                          // Không có điều kiện nào ở trên đúng
		    printf("This is another version.\n");
		    #endif
		
		return 0;
		}
	- Ví dụ 2:
  	 ```c
		    #include <stdio.h>
		// Định nghĩa một macro
		#define FEATURE_ENABLED
		
		int main() {
		    // Kiểm tra xem FEATURE_ENABLED đã được định nghĩa đúng không?
		    #ifdef FEATURE_ENABLED
		    printf("Feature is enabled.\n");
		    #endif
		    
		    // Kiểm tra xem ANOTHER_FEATURE chưa được định nghĩa đúng không?
		    #ifndef ANOTHER_FEATURE
		    printf("Another feature is not enabled.\n");
		    #endif
		
		return 0;
		}
#### Macro funtion 
- Macro function là khi đoạn mã sử dụng #define với tham số truyền vào để hoạt động giống như một hàm.

- Nếu macro function có nhiều dòng, mỗi dòng (trừ dòng cuối) phải kết thúc bằng ký tự \.
  ```c
	#include <stdio.h>
	
	#define DISPLAY_SUM(a,b)                        \
	printf("This is macro to sum 2 number\n");      \
	printf("Result is: %d", a+b);
	
	int main() {
		DISPLAY_SUM(5,6);
	return 0;
	}
- Ưu điểm của macro function so với function là tối ưu về tốc độ, nhưng không tối ưu về bộ nhớ.
#### Toán tử trong Macro
- Toán tử # (stringizing operator) chuyển đối số của macro thành chuỗi.
- Toán tử ## (concatenation operator) nối các đối số lại với nhau thành một chuỗi hoặc tên mới.
- Các toán tử này giúp tạo ra các macro linh hoạt và mạnh mẽ hơn, cho phép bạn thao tác với chuỗi và tên biến trong quá trình biên dịch.
- ví dụ 1:
  ```c
	   #include <stdio.h>
	
	#define TO_STRING(x) #x
	
	int main() {
	    int a = 5;
	    printf("Giá trị của a là: %s\n", TO_STRING(a));  // Kết quả sẽ là "a"
	    return 0;
	}
- ví dụ 2:
  ```c
	  #include <stdio.h>
	
	#define CONCAT(x, y) x ## y
	
	int main() {
	    int xy = 10;
	    printf("Giá trị của xy là: %d\n", CONCAT(x, y));  // Kết quả sẽ là 10
	    return 0;
	}
  - Trong ví dụ trên, CONCAT(x, y) sẽ nối x và y lại với nhau thành xy. Kết quả là việc gọi CONCAT(x, y) sẽ được thay thế bằng xy, do đó giá trị của biến xy là 10.
#### Variadic Marco
- Variadic macro là một loại macro trong ngôn ngữ C (và C++) cho phép bạn định nghĩa macro nhận một số lượng đối số không xác định (hay còn gọi là đối số biến đổi). Điều này hữu ích khi bạn muốn tạo một macro có thể làm việc với nhiều đối số mà không cần phải xác định số lượng đối số cụ thể.
- Giả sử bạn muốn định nghĩa một macro LOG có thể nhận một số lượng tham số không xác định để in ra một thông báo cùng với các tham số đó:
	```c
	#include <stdio.h>
	
	#define LOG(fmt, ...) printf(fmt, __VA_ARGS__)
	
	int main() {
	    int a = 10;
	    float b = 3.14;
	    
	    LOG("a = %d, b = %.2f\n", a, b);  // Gọi macro với 2 tham số
	    LOG("Only one parameter: %d\n", a);  // Gọi macro với 1 tham số
	
	    return 0;
	}
- Giải thích:

- LOG(fmt, ...) là variadic macro. fmt là tham số bắt buộc, còn ... đại diện cho các tham số còn lại (tùy chọn).
- Trong thân macro, bạn sử dụng __VA_ARGS__ để đại diện cho các tham số bổ sung được truyền vào macro.
- __VA_ARGS__ là một biến đặc biệt trong ngôn ngữ C giúp lấy tất cả các tham số được truyền vào macro.
- Kết quả của chương trình trên sẽ là:
	- a = 10, b = 3.14
	- Only one parameter: 10
</details>

<details><summary>LESSON 2: STDARG- ASSERT</summary>
    <p>	
	    
 ## LESSON 2: STDARG - ASSERT	
 ### Thư viện STDARG
 - Thư viện <stdarg.h> trong C cung cấp các cơ chế để làm việc với các tham số biến (variadic parameters) trong các hàm và macro. Đây là một thư viện rất hữu ích khi bạn muốn định nghĩa các hàm hoặc macro có thể nhận một số lượng tham số không cố định, chẳng hạn như các hàm printf hoặc scanf.
 - Thư viện này cung cấp ba macro chính giúp bạn làm việc với các tham số biến:
	- va_list: Đây là kiểu dữ liệu được sử dụng để giữ thông tin về các tham số biến. Bản chất là con trỏ kiểu char được định nghĩa lại tên bằng typedef: typedef char* va_list;
	- va_start: Dùng để khởi tạo một đối tượng va_list và bắt đầu xử lý các tham số biến. Hàm này mang các kí tự vào chuỗi, tạo một con trỏ có giá trị bằng địa chỉ kí tự đầu tiên của chuỗi không xác định và thực hiện vòng lặp so sánh các kí tự trong chuỗi có giống với từng kí tự của label count không và con trỏ địa chỉ tăng dần dần ứng với địa chỉ của các kí tự tiếp theo của chuỗi. Sau khi xác định được kí tự giống với label count thì mới bắt đầu mang các kí tự sau dấu , vào chuỗi. 
	- va_arg: Dùng để lấy giá trị của một tham số biến trong danh sách tham số và ép kiểu dữ liệu thành kiểu dữ liệu mong muốn
	- va_end: Dùng để kết thúc việc truy cập các tham số biến và giải phóng tài nguyên.
- Cú pháp của các macro trong <stdarg.h>:
	- va_list:Được sử dụng để khai báo một biến sẽ chứa các tham số biến.
		```c

		va_list args;
	- va_start: Dùng để bắt đầu truy xuất các tham số biến. va_start nhận hai đối số: Đối số đầu tiên là biến va_list bạn đã khai báo. Đối số thứ hai là tên của tham số cuối cùng trong danh sách tham số cố định (tham số trước danh sách tham số biến).
		```c

		va_start(args, last_fixed_param);
	- va_arg:Dùng để truy xuất một tham số trong danh sách tham số biến. Bạn cần chỉ định kiểu dữ liệu của tham số bạn muốn truy xuất.
		```c

		type arg = va_arg(args, type); //type là kiểu dữ liệu của tham số bạn muốn lấy (ví dụ: int, double, char, ...).
	- a_end: Dùng để kết thúc truy xuất các tham số biến và giải phóng tài nguyên. Đây là bước quan trọng để tránh rò rỉ tài nguyên.
		```c

		va_end(args);
- Ví dụ về việc sử dụng <stdarg.h>:
- Ví dụ: Viết một hàm sum nhận một số lượng tham số không xác định và tính tổng các tham số đó.
	```c

	#include <stdio.h>
	#include <stdarg.h>
	
	// Hàm sum với các tham số biến
	int sum(int num, ...) {
	    int total = 0;
	    
	    // Khai báo va_list để truy cập các tham số biến
	    va_list args;
	    
	    // Khởi tạo va_list, đối số thứ hai là tham số cuối cùng cố định (num)
	    va_start(args, num);
	    
	    // Duyệt qua các tham số và tính tổng
	    for (int i = 0; i < num; i++) {
	        total += va_arg(args, int);  // Lấy giá trị của tham số kiểu int
	    }
	    
	    // Kết thúc truy xuất tham số biến
	    va_end(args);
	    
	    return total;
	}
	
	int main() {
	    int result = sum(4, 1, 2, 3, 4);  // Gọi sum với 4 tham số
	    printf("Tổng là: %d\n", result);  // Kết quả sẽ là 10
	    
	    return 0;
	}
- Giải thích:

	- Hàm sum nhận một tham số đầu vào num xác định số lượng tham số tiếp theo.
	- Sau đó, hàm sử dụng va_start để khởi tạo danh sách tham số biến và va_arg để lấy từng giá trị từ danh sách tham số.
	- Cuối cùng, va_end được gọi để kết thúc quá trình truy xuất tham số biến.

### Thư viện ASSERT	
- Thư viện assert.h là thư viện để hỗ trợ debug chương trình.

- Hàm assert(): dùng để kiểm tra điều kiện, nếu đúng thì chương trình tiếp tục còn sai thì dừng lại ngay lập tức và báo lỗi.

- Ví dụ báo lỗi chia cho 0:
  ```c
	#include <stdio.h>
	#include <assert.h>
	
	double thuong(int a, int b) {
	    assert( b != 0 && "Mẫu bằng 0");
	    return (double) a/b;
	}
	
	int main() {
	    printf("Thuong: %f\n", thuong(6, 0)); 
	    return 0;
	}
- Báo lỗi:
	```c
	> Assertion failed: b != 0 && "Mẫu bằng 0", file tempCodeRunnerFile.c, line 5
- Thường thấy hơn sẽ sử dụng macro để định nghĩa một lỗi.
	```c
	#include <stdio.h>
	#include <assert.h>
	#define LOG(condition, cmd) assert(condition && #cmd)
	
	double thuong(int a, int b) {
	    LOG(b != 0, "Mau bang bang 0");
	}
	
	int main() {
	    thuong(6,0);
	    return 0;
	}

</details>


<details><summary>LESSON 3: POINTER</summary>
    <p>
        
## LESSON 3: POINTER
### Khái niệm và các loại Pointer
Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một đối tượng (biến,hàm,mảng) khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn. Dưới đây là một số khái niệm cơ bản về con trỏ trong C:
#### Cách khai báo: 
   
    int *ptr;  // con trỏ đến kiểu int
    char *ptr_char;  // con trỏ đến kiểu char
    float *ptr_float;  // con trỏ đến kiểu float
- Lấy địa chỉ của một biến:
   ```c 
    int x = 10;
    int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
- Sử dụng con trỏ để truy cập giá trị:
    int y = *ptr_x;  // y sẽ bằng giá trị của x
 ![image](https://github.com/user-attachments/assets/2799e903-2562-470a-b884-70fd4158ad98)
     - chú ý: địa chỉ con trỏ đang trỏ tới: ptr = 0x01; địa chỉ của con trỏ: &ptr = 0xf1;giá trị tại địa chỉ con trỏ trỏ tới *ptr = *(0x01)=5
- Kích thước của con trỏ sẽ phụ thuộc kiến trúc máy tính và trình biên dịch. Ta có thể dùng sizeof() để kiểm tra kích thước của con trỏ:
  ```c 
  #include <stdio.h>
  int main() {
    int *ptr;
    printf("Size of pointer: %lu bytes\n", sizeof(ptr));
    return 0;
  }


- Ví dụ:
  ```c
  #include <stdio.h>
  void swap(int *a, int *b)
  {
    int tmp = *a;
    *a = *b;
    *b = tmp;

  }
  int main()
  {
   int a = 10, b = 20;
   swap(&a, &b);

   printf("value a is: %d\n", a);
   printf("value b is: %d\n", b);

    return 0;
  }

 #### Các loại Pointer:
##### Void pointer:
- Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.
  ```c
  void *ptr_void;
- Ví dụ:
  ```c
     #include <stdio.h>
     #include <stdlib.h>

     int main() {
   
	    int value = 5;
	    double test = 15.7;
	    char letter = 'A';
	   
	    void *ptr = &value;
	    printf("value is: %d\n", *(int*)(ptr));
	
	    ptr = &test;
	    printf("value is: %f\n", *(double*)(ptr));
	
	    ptr = &letter;
	    printf("value is: %c\n", *(char*)(ptr));
	   
	    return 0;
       }


#### Pointer to Constant:
- Định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
- Ví dụ:
  ```c
	#include <stdio.h>
	#include <stdlib.h>
	
	int main() {
	    
	    int value = 5;
	    int const *ptr_const = &value;
	
	    //*ptr_const = 7; // wrong
	    //ptr_const++; // right
	    
	    printf("value: %d\n", *ptr_const);
	
	    value = 9;
	    printf("value: %d\n", *ptr_const);
	
	    return 0;
	}


#### Constant Pointer:
- Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
- Ví dụ:
  ```c
	#include <stdio.h>
	#include <stdlib.h>
	
	
	int main() {
	    
	    int value = 5;
	    int test = 15;
	    int *const const_ptr = &value;
	
	    printf("value: %d\n", *const_ptr);
	
	    *const_ptr = 7;
	    printf("value: %d\n", *const_ptr);
	
	    //const_ptr = &test; // wrong
	    
	    return 0;
	}




#### Function pointer:
- Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
- Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
- Ví dụ:
  ```c
	#include <stdio.h>
	
	// Hàm mẫu 1
	void greetEnglish() {
	    printf("Hello!\n");
	}
	
	// Hàm mẫu 2
	void greetFrench() {
	    printf("Bonjour!\n");
	}
	
	int main() {
	    // Khai báo con trỏ hàm
	    void (*ptrToGreet)();
	
	    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
	    ptrToGreet = greetEnglish;
	
	    // Gọi hàm thông qua con trỏ hàm
	    (*ptrToGreet)();  // In ra: Hello!
	
	    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
	    ptrToGreet = greetFrench;
	
	    // Gọi hàm thông qua con trỏ hàm
	    (*ptrToGreet)();  // In ra: Bonjour!
	
	    return 0;
	}

- Trong ví dụ này, ptrToGreet là một con trỏ hàm có thể trỏ đến các hàm greetEnglish và greetFrench. Việc này giúp linh hoạt trong việc chọn và sử dụng hàm tương ứng tại thời điểm chạy.
- Ví dụ 2:
  ```c
	#include <stdio.h>
	
	void sum(int a, int b)
	{
	    printf("Sum of %d and %d is: %d\n",a,b, a+b);
	}
	
	void subtract(int a, int b)
	{
	    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
	    
	}
	
	void multiple(int a, int b)
	{
	    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
	    
	}
	
	void divide(int a, int b)
	{
	    if (b == 0)
	    {
	        printf("Mau so phai khac 0\n");
	        return;
	    }
	    
	    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
	    
	}
	
	void calculator(void (*ptr)(int a, int b), int a, int b)
	{
	    printf("Program calculate: \n");
	    ptr(a,b);
	}
	
	int main()
	{
	    void (*ptrToFunc)(int,int);
	    ptrToFunc = &divide;
	
	    calculator(ptrToFunc,5,2);
	
	    return 0;
	}



	
- Trong ví dụ này, ptrToFunc là một con trỏ hàm trỏ đến các hàm sum, subtract, multiple, divide. Hàm calculator với 3 tham số truyền vào là: con trỏ hàm, a, b, và sẽ call function mà con trỏ đang trỏ tới và truyền vào 2 tham số a và b.
Pointer to pointer:
#### Con trỏ đến con trỏ (Pointer to Pointer)
- là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
 - Ví dụ:
   ```c

	#include <stdio.h>
	
	int main() {
	    int value = 42;
	    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến
	
	    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ
	
	    printf("Value: %d\n", **ptr2);
	
	    return 0;
	      }
- Trong ví dụ này:
	- ptr1 là một con trỏ thường trỏ đến biến value.
	- ptr2 là một con trỏ đến con trỏ, trỏ đến địa chỉ của ptr1.
	- Khi sử dụng **ptr2, chúng ta có thể truy cập giá trị của biến value.
#### NULL pointer
 - Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.
 - Ví dụ:
    ```c
	#include <stdio.h>
	
	int main() {
	    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ
	
	    if (ptr == NULL) {
	        printf("Pointer is NULL\n");
	    } else {
	        printf("Pointer is not NULL\n");
	    }
	
	    return 0;
	}

- Trong ví dụ này:
	- Con trỏ ptr được khai báo và được gán giá trị NULL.
	- Một điều kiện kiểm tra xem con trỏ có trỏ đến một đối tượng nào đó hay không.
	- Nếu con trỏ bằng NULL, chương trình in ra "Pointer is NULL", ngược lại nếu con trỏ không bằng NULL, chương trình in ra "Pointer is not NULL".
	- Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.
</details>
<details><summary>LESSON 4: EXTERN - STATIC- VOLATILE</summary>
  <p>
  
 ## LESSON 4: EXTERN - STATIC- VOLATILE
 ### EXTERN
 - Khái niệm Extern trong ngôn ngữ lập trình C được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.
- Ví dụ:
 	 ```c
	- File main.c
	#include <stdio.h>
	int value = 90;
	extern void display();
	int main()
	{
		printf("hello\n");
		display();
	}
	- File other.c
	 ```c
	#include <stdio.h>
	extern int value;
	void display()
	{
		printf("value: %d\n", value);
	}
- Chia sẻ biến và hàm giữa các file nguồn:
	- Extern cho phép bạn chia sẻ biến và hàm giữa nhiều file nguồn trong một chương trình.
	- Điều này hữu ích khi bạn muốn tách chương trình thành các phần nhỏ để quản lý dễ dàng hơn.
- Chia sẻ biến và hàm giữa các module hoặc thư viện:
	- Extern có thể được sử dụng để kết nối các module hoặc thư viện trong một dự án lớn.
- Khai báo hàm trong trường hợp định nghĩa sau:
	- Nếu bạn muốn sử dụng một hàm trước khi nó được định nghĩa trong mã nguồn, bạn có thể sử dụng extern để khai báo hàm.
- Biến toàn cục giữa các tệp nguồn:
	- Khi có một biến toàn cục được sử dụng trong nhiều file nguồn, extern giúp các file nguồn biết về sự tồn tại của biến đó.
- Chia sẻ hằng số giữa các file nguồn:
  	- Nếu bạn có một hằng số được sử dụng ở nhiều nơi, bạn có thể sử dụng extern để chia sẻ giá trị của hằng số đó giữa các file nguồn.
### STATIC
#### Static local vabribles
- Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.
- -Biến sẽ chỉ được khởi tạo 1 lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm và và không được khởi tạo lại trong các lần gọi tiếp theo.
	```c
	#include <stdio.h>
	
	void exampleFunction() {
	    static int count = 0; 
	    count++;
	    printf("Count: %d\n", count);
	}
	
	int main() {
	    exampleFunction();  // In ra lần 1: 1
	    exampleFunction();  // In ra lần 2: 2
	    exampleFunction();  // In ra lần 3: 3
	    return 0;
	}
 - Ứng dụng: Lưu trữ trạng thái giữa các lần gọi hàm: Sử dụng biến static để theo dõi trạng thái trạng thái giữa các lần gọi hàm mà không cần sử dụng biến toàn cục.
 #### Static global variables
 - Biến toàn cục tĩnh là các biến được khai báo với từ khóa static ở ngoài tất cả các hàm (tức là trong phạm vi toàn cục của file). Nó có những tính chất đặc biệt như sau: -Phạm vi truy cập chỉ giới hạn trong file: Chỉ có thể truy cập được trong file nơi nó được khai báo, không thể được sử dụng bởi các file khác, ngay cả khi chúng được khai báo là extern. Khác với biến toàn cục không có từ khóa static, có thể được truy cập từ các file khác nếu được khai báo extern.
 - Thời gian tồn tại: Biến toàn cục tĩnh có thời gian tồn tại từ khi chương trình bắt đầu cho đến khi chương trình kết thúc, tương tự như các biến toàn cục thông thường.
 - Ví dụ file main.c:
   ```c
	#include <stdio.h>
	extern void display();
	//extern int s_g_value;      // Không được phép, vì s_g_value là biến toàn cục tĩnh của file other.c!!
	extern int g_value;
	int main() {
	    printf("hello\n");
	    g_value = 40;
	    display();
	return 0;
	}
- Ở file other.c:
  ```c
	#include <stdio.h>
	int g_value = 30;
	static int s_g_value = 20;
	void display() {
		printf("static global value: %d\n", s_g_value);
		printf("global value: %d\n", g_value);
	}
 ### VOLATILE
 - Từ khóa volatile trong ngôn ngữ lập trình C được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó (do tính năng optimization của compiler), giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.
- Volatile đại diện cho các biến có thể thay đổi bất thường mà không thông qua nguồn source code.
  	```c
	#include "stm32f10x.h"
	volatile int i = 0;
	int a = 100;
	int main()
	{
		
		while(1)
		{
			i = *((int*) 0x20000000);
			if (i > 0)
			{
				break;
			}
			
		}
		a = 200;
	}
 - Trong lập trình nhúng, chúng ta hay gặp đoạn code khi ta khai báo 1 biến đếm count, mỗi khi bấm nút xảy ra ngắt ngoài, chúng ta tăng biến đếm count. Tuy nhiên, khi chúng ta bật tính năng tối ưu code của compiler, nó sẽ hiểu rằng các biến như vậy dường như không thay đổi giá trị bởi phần mềm nên compiler có xu hướng loại bỏ biến count để có thể tối ưu kích cỡ file code chạy được sinh ra.
### REGISTER
- Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập. Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này.
  ![image](https://github.com/user-attachments/assets/f2c460ef-9b41-4355-8b3a-940415611fc3)
- Ví dụ:
  	```c
	#include <stdio.h>
	#include <time.h>
	
	int main() {
	    // Lưu thời điểm bắt đầu
	    clock_t start_time = clock();
	
	    // Đoạn mã của chương trình
	    for (int i = 0; i < 1000000; ++i) {
	        // Thực hiện một số công việc bất kỳ
	    }
	
	    // Lưu thời điểm kết thúc
	    clock_t end_time = clock();
	
	    // Tính thời gian chạy bằng miligiây
	    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
	
	    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);
	
	    return 0;
	}

 
 </details>
 <details><summary>LESSON 5: GOTO - SETJMP</summary>
  <p>
  
 ## LESSON 5: GOTO - SETJMP
 ### GOTO
- goto là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một câu lệch đã được đặt trước đó trong cùng một hàm. Mặc dù nó cung cấp khả năng kiểm soát flow của chương trình, nhưng việc sử dụng goto thường được xem là không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.
- Cách sử dụng goto trong C/C++:
	-Cú pháp:

	```c

	goto label;
- Trong đó: label là một nhãn (label) được định nghĩa trước trong chương trình, là tên của vị trí mà bạn muốn nhảy đến. Nhãn này phải kết thúc bằng dấu hai chấm (:).
- Ví dụ:

	```c

	#include <stdio.h>
	
	int main() {
	    int x = 10;
	
	    if (x == 10) {
	        goto jump_here; // Nhảy đến nhãn jump_here nếu x == 10
	    }
	
	    printf("Không bao giờ đến đây.\n"); // Dòng này sẽ bị bỏ qua vì goto đã nhảy qua
	
	jump_here:
	    printf("Đã nhảy đến nhãn jump_here.\n");
	
	    return 0;
	}
 
- Giải thích ví dụ:
	- Câu lệnh goto jump_here;: Chương trình sẽ nhảy đến vị trí có nhãn jump_here: ngay khi điều kiện if (x == 10) đúng.
	- jump_here:: Đoạn mã sau nhãn này sẽ được thực thi khi chương trình nhảy tới đó.
	- Dòng "Không bao giờ đến đây." sẽ không bao giờ được in ra vì câu lệnh goto đã chuyển điều khiển ra ngoài đoạn mã đó
  ### SETJMP
  - setjmp.h là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là setjmp và longjmp. Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ này.
- Cú pháp:
  	```c

	#include <setjmp.h>
	
	int setjmp(jmp_buf env);
- Trong đó:
	- jmp_buf env: Là một mảng hoặc cấu trúc được sử dụng để lưu trữ thông tin trạng thái của ngữ cảnh chương trình tại thời điểm gọi setjmp. Nó sẽ chứa thông tin cần thiết để chương trình có thể quay lại điểm gọi hàm setjmp.
	- Hàm setjmp trả về giá trị 0 khi nó được gọi lần đầu tiên, và sẽ trả về giá trị khác (thường là một giá trị không bằng 0) khi chương trình quay lại từ hàm longjmp.
- Mô tả:
	- setjmp được sử dụng để lưu lại trạng thái của ngữ cảnh chương trình tại một điểm cụ thể (gọi là "checkpoint").
	- longjmp sau đó có thể được sử dụng để quay lại điểm đó, thay vì tiếp tục chạy từ vị trí mà chương trình bị tạm dừng.
- Cách hoạt động:
	- Gọi setjmp: Khi setjmp được gọi, nó lưu lại trạng thái của chương trình (ví dụ, các thanh ghi, con trỏ, v.v.) trong biến env (được khai báo kiểu jmp_buf).
	- Quay lại với longjmp: Khi gặp lỗi hoặc cần nhảy ra một điểm khác trong chương trình, bạn có thể gọi hàm longjmp(env, value) để quay lại điểm gọi setjmp, đồng thời trả về giá trị value từ hàm setjmp. Điều này làm cho chương trình "nhảy" về lại điểm đó.
- Ví dụ về cách sử dụng setjmp và longjmp:
	```c

	#include <stdio.h>
	#include <setjmp.h>
	
	jmp_buf env;

	void func() {
	    printf("Bắt đầu func.\n");
	    longjmp(env, 1);  // Quay lại setjmp và trả về giá trị 1
	    printf("Không bao giờ in dòng này.\n");
	}
	
	int main() {
	    if (setjmp(env) == 0) {
	        // Đây là lần gọi đầu tiên của setjmp
	        printf("Điều khiển đang ở trong main.\n");
	        func();  // Gọi hàm func, sau đó longjmp sẽ quay lại đây
	    } else {
	        // Sau khi longjmp được gọi
	        printf("Điều khiển quay lại từ longjmp.\n");
	    }
	
	    return 0;
	}
- Giải thích ví dụ:
	- Gọi setjmp(env) lần đầu tiên: Khi setjmp được gọi trong hàm main, chương trình lưu trạng thái ngữ cảnh vào biến env và trả về giá trị 0. Sau đó, chương trình tiếp tục bình thường và gọi hàm func().
	- Gọi longjmp(env, 1) trong func: Trong hàm func, câu lệnh longjmp(env, 1) sẽ khiến chương trình quay lại điểm gọi setjmp trong hàm main. Lúc này, setjmp không trả về 0 nữa mà trả về giá trị 1, vì vậy đoạn mã trong else sẽ được thực thi.
- Kết quả chương trình:
	```css
	Điều khiển đang ở trong main.
	Bắt đầu func.
	Điều khiển quay lại từ longjmp.
</details>

<details><summary>LESSON 6: BITMASK </summary>

 <p>
	 
## BITMASK
### Khái niệm bitmask
- Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).
- Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.
- Thay vì sử dụng một biến riêng cho mỗi cờ (flag), bạn có thể sử dụng bitmask để lưu trữ nhiều giá trị nhị phân (on/off, true/false).
	```c
 	uint8_t bitmask = 0b10101010;
- Giả sử ta có một dãy bitmask 8 bit (1 byte) để lưu trữ trạng thái của 8 thiết bị khác nhau. Mỗi thiết bị có thể ở trạng thái bật (1) hoặc tắt (0).
![image](https://github.com/user-attachments/assets/b1dc5d6c-e078-4548-8130-9b6d8938fd3d)
### Các toán tử bitwise
- NOT bitwise
	- int result = ~num ;
	- Kết quả là bit đảo ngược của số đó.
- AND bitwise
	- int result = num1 & num2;
	- Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0.
- OR bitwise
	- int result = num1 | num2;
	-Kết quả là 1 nếu có hơn một bit tương ứng là 1
- XOR bitwise
   	- int result = num1 ^ num2;
	- Kết quả là 1 nếu chỉ có một bit tương ứng là 1

- Shift left và Shift right bitwise
	- Dùng để di chuyển bit sang trái hoặc sang phải.
	- Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
	- Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).
	- int resultLeftShift = num << shiftAmount;
	- int resultRightShift = num >> shiftAmount;
- ví dụ:
  ```c
	#include <stdio.h>
	#include <stdint.h>
	
	#define ENABLE 1
	#define DISABLE 0
	
	typedef struct {
	    uint8_t LED1 : 1;
	    uint8_t LED2 : 1;
	    uint8_t LED3 : 1;
	    uint8_t LED4 : 1;
	    uint8_t LED5 : 1;
	    uint8_t LED6 : 1;
	    uint8_t LED7 : 1;
	    uint8_t LED8 : 1;
	} LEDStatus;
	void displayAllStatusLed(LEDStatus status) {
	 	uint8_t* statusPtr = (uint8_t*)&status;
			for (int j = 0; j < 8; j++) {
			printf("LED%d: %d\n", j+1, (*statusPtr >> j) & 1);
	}
	}
	int main() {
	    LEDStatus ledStatus = {.LED7 = ENABLE};
	
	    // Bật LED 1 và 3
	    ledStatus.LED1 = ENABLE;
	    ledStatus.LED3 = ENABLE;
	    displayAllStatusLed(ledStatus);
		
	    return 0;
	}
</details>
   <details><summary>LESSON 7: STRUCT - UNION </summary>
  <p>
  
 ## LESSON 7: STRUCT - UNION
 ### STRUCT
 #### Khái niệm
 - struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. Các biến này có thể là các kiểu dữ liệu khác nhau (int, float, char, ...), và mỗi biến trong struct gọi là thành viên (member) hoặc trường (field).
#### Tính năng
- Gom nhóm các dữ liệu khác nhau: Bạn có thể sử dụng struct để gom các thành viên có kiểu dữ liệu khác nhau vào một đối tượng duy nhất.
- Tăng tính tổ chức: Khi làm việc với các dữ liệu liên quan nhưng khác kiểu, struct giúp bạn giữ chúng trong một đơn vị duy nhất, dễ dàng quản lý và sử dụng.
- Dễ dàng mở rộng: Bạn có thể thêm, sửa hoặc xóa các thành viên trong một struct mà không ảnh hưởng đến các phần khác của chương trình
#### Cấu trúc cơ bản của struct
	struct StructName {
	    data_type member1;
	    data_type member2;
	    data_type member3;
	    // ...
	};
  - ví dụ:
    ```c
	struct Point {
	    int x;
	    int y;
	};
#### Khởi tạo và truy cập thành viên
 	struct StructName p1 = {10,20};
  - để truy cập thành viên, sử dụng toán tử (.);
    ```c
    	printf("X coordinate: %d\n", p1.x);
#### Sử Dụng Tham Số Trong Hàm:
- Bạn có thể truyền một biến thuộc kiểu struct như một tham số cho một hàm.
 	```c
	void printPoint(struct Point p) {
	    printf("(%d, %d)\n", p.x, p.y);
	}
#### Truyền Con Trỏ đến Struct:
- Bạn có thể truyền con trỏ đến struct như một tham số cho một hàm, cho phép thay đổi giá trị của struct bên trong hàm.
	 ```c
	void updatePoint(struct Point* p, int newX, int newY) {
	    p->x = newX;
	    p->y = newY;
	}
#### Sử Dụng typedef để Tạo Bí Danh:
- Bạn có thể sử dụng typedef để tạo bí danh cho struct, giúp rút ngắn cú pháp khi khai báo biến.
	```c
	typedef struct Point {
	    int x;
	    int y;
	} Point;
- Sau đó, bạn có thể khai báo biến như sau:
	```c
	Point p1 = {10, 20};



#### kích thước của struct
- Kích thước của một struct trong C phụ thuộc vào các thành phần bên trong nó và cách chúng được sắp xếp trong bộ nhớ.
  ```c
	  typedef struct {
	    uint8_t c;    // Kiểu uint1_t = 1 byte = 8 bit
	    uint16_t a;    // Kiểu uint16_t = 2 bytes, kích thước lớn nhất.
	    uint32_t  b;    // Kiểu uint8_t = 4 bytes, kích thước lớn nhất
	} examp1;
- Kích thước các thành viên: Tổng kích thước các thành viên theo thứ tự khai báo.
- Padding: Cộng thêm số byte padding cần thiết để đáp ứng yêu cầu alignment của hệ thống.
- Kết quả: Kích thước của struct sẽ là kích thước tổng cộng của tất cả các thành viên cộng với padding, sao cho kích thước của struct là bội số của yêu cầu alignment cuối cùng.
  ![image](https://github.com/user-attachments/assets/2bb17363-a533-4e93-b1d6-b5e63b3f49b2)
  ```c
  struct Example {
    uint8_t a;    
    uint32_t b;
    uint16_t c;  
  };
![image](https://github.com/user-attachments/assets/3f64fb7f-48a3-4912-88f5-1183e11cb6b8)

    ```c
	struct Example1 {
	    uint8_t arr1[5];
	    uint16_t arr2_1;  
	    uint16_t arr2_2; 
	    uint16_t arr2_3; 
	    uint16_t arr2_4;   
            uint32_t arr3[2];
	           };
   
![image](https://github.com/user-attachments/assets/e629f46d-0804-44d1-b9c2-27501d627192)
### UNION
- Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào một cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng.
- Kích thước của union sẽ bằng kích thước của thành viên lớn nhất.
#### Khởi tạo
- Cú pháp định nghĩa union trong C như sau:
  	```c
	union TenUnion {
	    kieuDuLieu1 thanhVien1;
	    kieuDuLieu2 thanhVien2;
	    // ...
	};
- Ví dụ:
  	 ```c
	union Data {
	    int i;
	    float f;
	    char str[20];
		};
	int main() {
	    // Khai báo một biến kiểu union Data
	    union Data data;
	
	    // Gán giá trị cho thành viên i
	    data.i = 10;
	    printf("data.i: %d\n", data.i);
	
	    // Gán giá trị cho thành viên f
	    data.f = 220.5;
	    printf("data.f: %.2f\n", data.f);
	
	    // Gán giá trị cho thành viên str
	    snprintf(data.str, sizeof(data.str), "Hello, Union!");
	    printf("data.str: %s\n", data.str);
	
	    return 0;
	}
- union Data có ba thành viên:
	- i là một biến kiểu int.
	- f là một biến kiểu float.
	- str là một mảng ký tự (chuỗi) có độ dài 20.
  	-  Khi gán giá trị cho data.i, sau đó gán giá trị cho data.f, và cuối cùng là gán giá trị cho data.str, ta thấy rằng chỉ có một giá trị duy nhất được lưu tại một thời điểm trong bộ nhớ của union.
#### Địa chỉ các biến thành phần:
	```c
	Dia chi data:	00000097873FF9E4
	Dia chi data.a: 00000097873FF9E4
	Dia chi data.b: 00000097873FF9E4
	Dia chi data.c: 00000097873FF9E4
- Điều này có nghĩa là union chỉ có thể lưu trữ một giá trị cho một thành phần tại một thời điểm.
#### Truy cập thành viên
	```c
	union Data data;
	data.i = 10;
	printf("Value of i: %d\n", data.i);
#### Sử dụng trong các tình huống đặc biệt
- union thường được sử dụng khi bạn có một biến có thể chứa một trong các kiểu dữ liệu khác nhau và bạn chỉ cần sử dụng một kiểu dữ liệu tại một thời điểm.
	 ```c
	union Value {
	    int intValue;
	    float floatValue;
	    char stringValue[20];
	 };
#### Kích thước của UNION
- Kích thước của union là kích thước của thành viên lớn nhất. Ví dụ, nếu trong union có một int (4 bytes) và một double (8 bytes), thì kích thước của union sẽ là 8 bytes (kích thước của double).
### Ứng dụng kết hợp struct và union
	
	 #include <stdio.h>
	#include <stdint.h>
	#include <string.h>
	
	
	typedef union {
	    struct {
	        uint8_t id[2];
	        uint8_t data[4];
	        uint8_t check_sum[2];
	    } data;
	
	    uint8_t frame[8];
	
	} Data_Frame;
	
	
	int main(int argc, char const *argv[])
	{
	    Data_Frame transmitter_data;
	    
	    strcpy(transmitter_data.data.id, "10");
	    strcpy(transmitter_data.data.data, "1234");
	    strcpy(transmitter_data.data.check_sum, "70");
	
			Data_Frame receiver_data;
	    strcpy(receiver_data.frame, transmitter_data.frame);
		
	    
	    return 0;
	}
 ### So sánh giữa struct và union
![image](https://github.com/user-attachments/assets/7239cec4-2c31-4297-99da-2011137f776e)
</details>
 <details><summary>LESSON 8: MEMORY LAYOUT </summary>
  <p>
	  
 ## LESSON 8: MEMORY LAYOUT
- Bố cục bộ nhớ (Memory Layout) là cách mà dữ liệu được tổ chức và lưu trữ trong bộ nhớ của máy tính. Nó bao gồm việc dữ liệu được sắp xếp như thế nào trong bộ nhớ khi chương trình đang chạy, cách các loại dữ liệu khác nhau được lưu trữ và cách bộ nhớ được phân bổ.
- Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.
- Chương trình C/C++ được tổ chức lưu trong memory layout (phân vùng nhớ) thành các phần như sau:
### Text segment
- Đặc điểm: Segment mã chứa mã nguồn đã biên dịch của chương trình, tức là các chỉ thị máy tính. Cụ thể, Text Segment chứa mã máy đã được biên dịch từ mã nguồn của chương trình và được CPU thực thi để thực hiện các hành động quy định trong chương trình.
- Hoạt động:
	- Chỉ có quyền đọc và thực thi: Thường thì phần này được đánh dấu là chỉ đọc để tránh sửa đổi mã chương trình (mã máy), (không có quyền ghi).
	- Chứa mã máy (chương trình): Bao gồm các hàm và chỉ thị của chương trình đã biên dịch(tập hợp các lệnh thực thi được CPU hiểu được).
 	- Kích thước cố định: kích thước của text segment thường là cố định nên giúp hệ điều hành và CPU dễ dàng quản lí vùng nhớ này
  	- Lưu trữ các hằng số, con trỏ kiểu char 
   ![image](https://github.com/user-attachments/assets/622cf571-2e60-46f4-a268-4a371f55a55b)
	```c
	 #include <stdio.h>
	
	const int a = 10;
	char arr[] = "Hello";
	char *arr1 = "Hello";
	
	int main() {
	   
	
	    printf("a: %d\n", a);
	
	    arr[3] = 'W';
	    printf("arr: %s", arr);
	
	    arr1[3] = 'E';
	    printf("arr1: %s", arr1);
	
	    
	    return 0;
	}
### Data segment - Initialized Data Segment
- Đặc điểm: Segment dữ liệu dùng để lưu trữ các dữ liệu tĩnh gồm các biến toàn cục và biến tĩnh (static) đều được khởi tạo với giá trị khác 0, tức là các biến mà không phụ thuộc vào thời gian chạy của chương trình.
- Hoạt động:
	- Biến toàn cục: Biến được khai báo ngoài các hàm, có thể truy cập từ bất kỳ đâu trong chương trình.
	- Biến tĩnh: Biến được khai báo với từ khóa static trong C/C++, giữ giá trị giữa các lần gọi hàm. Có thể được truy cập chỉ trong phạm vi của hàm được khai báo.
	- Khởi tạo: Segment này chứa cả các biến toàn cục/tĩnh đã khởi tạo và chưa khởi tạo (phần chưa khởi tạo thường gọi là BSS).
   		- Initialized Data Segment (Dữ liệu Đã Khởi Tạo): Chứa giá trị của các biến toàn cục và biến tĩnh được khởi tạo với giá trị ban đầu. Dữ liệu này được sao chép từ bộ nhớ của chương trình thực thi.
 	- Quyền truy cập là đọc và ghi, tức có thể đọc và thay đổi giá trị của biến.
  	- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc
 	- Kích thước của Data Segment có thể thay đổi trong quá trình thực thi của chương trình.
![image](https://github.com/user-attachments/assets/955c4a78-cfc1-487f-be5c-7e7b0b14e12d)
	```c
 	#include <stdio.h>
	int a = 10;
	double d = 20.5;
	
	static int var = 5;
	
	void test()
	{
	    static int local = 10;
	}
	
	
	int main(int argc, char const *argv[])
	{  
	    a = 15;
	    d = 25.7;
	    var = 12;
	    printf("a: %d\n", a);
	    printf("d: %f\n", d);
	    printf("var: %d\n", var);
	
	
	
	    return 0;
	}
	```c 
	 #include <stdio.h>
	
	const int a = 10;			    // Hằng số
	char *arr1 = "Hello";			// Con trỏ kiểu char
	
	int main() 
	{
	    //a=10;             		// Không được phép thay đổi->Bị lỗi
	    //arr1[3] = 'E';
	
	    printf("a: %d\n", a);
	    printf("arr1: %s", arr1);
	
	    return 0;
	}
### Bss segment - Uninitialized Data Segment
- Chứa các biến toàn cục khởi tạo với giá trị bằng 0 hoặc không gán giá trị.
- Chứa các biến static với giá trị khởi tạo bằng 0 hoặc không gán giá trị.
- Quyền truy cập là đọc và ghi, tức là có thể đọc và thay đổi giá trị của biến .
- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.
- Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo): Chứa giá trị mặc định của các biến toàn cục và biến tĩnh mà không cần khởi tạo giá trị ban đầu. Dữ liệu trong phân vùng này thường được xác định bởi giá trị 0.
![image](https://github.com/user-attachments/assets/c3af5bad-21b7-4afd-9151-4ae99843b3ba)
	```c
	#include <stdio.h>
	typedef struct 
	{
	    int x;
	    int y;
	} Point_Data;
	
	
	int a = 0;
	int b;
	
	static int global = 0;
	static int global_2;
	static Point_Data p1 = {5,7};
	void test()
	{
	    static int local = 0;
	    static int local_2;
	}
	
	int main() {
	    printf("a: %d\n", a);
	    printf("global: %d\n", global);
	    return 0;
	}
### Stack
- Đặc điểm: Bộ nhớ stack được sử dụng để lưu trữ các biến cục bộ (tức là các biến được khai báo trong các hàm và chỉ có giá trị trong phạm vi của hàm đó) và thông tin về các lời gọi hàm, tham số truyền vào.
- Hoạt động:
	- Lưu trữ lời gọi hàm: Mỗi lần hàm được gọi, một "stack frame" được tạo ra để lưu trữ các biến cục bộ của hàm, địa chỉ trả về và các thông tin liên quan khác. Sau khi ra khỏi hàm, sẽ thu hồi vùng nhớ.
	- Nguyên tắc LIFO (Last In, First Out): Bộ nhớ stack hoạt động theo kiểu dữ liệu vào sau sẽ ra trước (mới gọi hàm sẽ nằm trên cùng).
	- Giới hạn: Stack có kích thước cố định, nếu vượt quá có thể gây ra lỗi "stack overflow."
   	- Quyền truy cập: Đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.
	- Kích thước cố định: Tùy thuộc vào hệ điều hành khác nhau.
   	- Stack pointer: Con trỏ ngăn xếp (stack pointer) giữ địa chỉ hiện tại của stack và được cập nhật liên tục khi dữ liệu được đẩy vào hoặc lấy ra.
- Stack là một cơ chế quan trọng trong quá trình thực thi chương trình và thường được sử dụng để quản lý luồng thực thi, gọi hàm, và theo dõi các biến cục bộ. Các ngôn ngữ lập trình thường sử dụng ngăn xếp để triển khai thực thi hàm và quản lý các biến cục bộ.
	```c
	#include <stdio.h>
	void test()
	{
	    int test = 0;
	    test = 5;
	    printf("test: %d\n",test);
	}
	
	int sum(int a, int b)
	{
	    int c = a + b;
	    printf("sum: %d\n",c);
	    return c;
	}
	
	int main() {
	
	    sum(3,5);
	    /*
	        0x01
	        0x02
	        0x03
	    */
	   test();
	   /*
	    int test = 0; // 0x01
	   */
	    return 0;
	}
 ### Heap
- Đặc điểm: Bộ nhớ heap dùng để phân bổ bộ nhớ động, tức là bộ nhớ được cấp phát khi chương trình đang chạy (cấp phát động).
- Hoạt động:
	- Cấp phát động: Dữ liệu như đối tượng, cấu trúc dữ liệu có thể được cấp phát bộ nhớ tại thời điểm chạy.Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
	- Quản lý bộ nhớ: Người lập trình phải giải phóng bộ nhớ khi không còn sử dụng để tránh rò rỉ bộ nhớ (memory leaks).
	- Phân mảnh: Khi bộ nhớ được cấp phát và giải phóng, có thể tạo ra các khoảng trống, dẫn đến phân mảnh bộ nhớ.
   	- Quyền truy cập: Bộ nhớ trên heap thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong suốt thời gian chương trình chạy.
   	- Cấp Phát và Giải Phóng Bộ Nhớ: Các hàm như malloc()(Tham số truyền vào: kích thước mong muốn(byte), Giá trị trả về: con trỏ void), calloc(), realloc(), và free() được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.
	- Kích Thước Thay Đổi: Kích thước của heap có thể thay đổi trong quá trình thực thi của chương trình, tùy thuộc vào các thao tác cấp phát và giải phóng bộ nhớ.
	- Không Giữ Giá Trị Mặc Định: Bộ nhớ trên heap không giữ giá trị mặc định như trong Data Segment. Nếu không được khởi tạo, giá trị của biến trên heap sẽ không xác định.
	```c
	 #include <stdlib.h>
	int main() {
	    int *arr_malloc, *arr_calloc;
	    size_t size = 5;
	
	    // Sử dụng malloc
	    arr_malloc = (int*)malloc(size * sizeof(int));
	
	    // Sử dụng calloc
	    arr_calloc = (int*)calloc(size, sizeof(int));
	
	    // ...
	
	    // Giải phóng bộ nhớ
	    free(arr_malloc);
	    free(arr_calloc);
	
	    return 0;
	}
- ví dụ
  	``c
	  #include <stdio.h>
	 #include <stdlib.h>
	int main(int argc, char const *argv[])
	{  
	    int soluongkytu = 0;
	
	    char* ten = (char*) malloc(sizeof(char) * soluongkytu);
	    for (int i = 0; i < 3; i++)
	    {
	        printf("Nhap so luong ky tu trong ten: \n");
	        scanf("%d", &soluongkytu);
	        ten = realloc(ten, sizeof(char) * soluongkytu);
	        printf("Nhap ten cua ban: \n");
	        scanf("%s", ten);
	
	        printf("Hello %s\n", ten);
	    }
	    return 0;
	}
### Stack và Heap
- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).
- Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động giải phóng khi hàm thực hiện xong công việc của mình.
- Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay giải phóng vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ.
  ```c
	  #include <stdio.h>
	  #include <stdlib.h>
	
	void test1()
	{
	    int array[3];
	    for (int i = 0; i < 3; i++)
	    {
	        printf("address of array[%d]: %p\n", i, (array+i));
	    }
	    printf("----------------------\n");
	}
	
	void test2()
	{
	    int *array = (int*)malloc(3*sizeof(int));
	    for (int i = 0; i < 3; i++)
	    {
	        printf("address of array[%d]: %p\n", i, (array+i));
	    }
	    printf("----------------------\n");
	    //free(array);
	}
	int main(int argc, char const *argv[])
	{  
	    test1();
	    test1();
	    test2();
	    test2();
	    return 0;
	}
- Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
	```c
	int foo(int x){
	    printf("De quy khong gioi han\n");
	    return foo(x);
	}
- Heap: Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
	```c
	int *A = (int *)malloc(18446744073709551615)
 </details>
 <details><summary>LESSON 10: LINKED LIST </summary>
  <p>
  
 ## LESSON 10: LINKED LIST
 ### Khái niệm Linked list 
 - Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes) được lưu trữ không liền kề nhau trong bộ nhớ, mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.
- Khác với mảng (array), trong đó các phần tử được lưu trữ liên tiếp trong bộ nhớ, linked list cho phép linh hoạt hơn trong việc thêm và xóa phần tử mà không cần phải thay đổi kích thước hoặc di chuyển các phần tử khác.
![image](https://github.com/user-attachments/assets/edcf0aa4-5c38-4d7b-8846-c8435ea056c6)
### Các loại linked list
- Có hai loại linked list chính:
	- Singly Linked List (Danh sách liên kết đơn): Mỗi nút chỉ chứa một con trỏ đến nút tiếp theo trong chuỗi.
	- Doubly Linked List (Danh sách liên kết đôi): Mỗi nút chứa hai con trỏ, một trỏ đến nút tiếp theo và một trỏ đến nút trước đó.
### Tính chất
- Danh sách liên kết có thể mở rộng và thu hẹp một cách linh hoạt.
- Mặc định nodes sẽ chưa liên kết với nhau => phải liên kết các nodes thông qua con trỏ.
- Phần tử cuối cùng trong Linked list sẽ trỏ vào NULL (con trỏ NULL), đánh dấu sự kết thúc của danh sách.
- Linked list có thể thay đổi kích thước linh hoạt. Bạn có thể thêm hoặc xóa các node mà không cần phải thay đổi kích thước của danh sách hoặc di chuyển các phần tử khác, như trong mảng.
- Để truy cập một phần tử bất kỳ trong linked list, bạn phải bắt đầu từ node đầu tiên và duyệt lần lượt qua các node tiếp theo cho đến khi tìm thấy phần tử cần tìm. Điều này làm cho việc truy cập các phần tử ngẫu nhiên (random access) kém hiệu quả hơn so với mảng.
- Đây là kiểu cấu trúc dữ liệu kiểu cấp phát động có nghĩa là còn bộ nhớ thì còn cấp phát được, cấp phát đến khi nào hết bộ nhớ thì thôi - Vùng nhớ cấp phát : Heap.
- Linked list chỉ sử dụng bộ nhớ cho các node đã được tạo ra. Điều này giúp tiết kiệm bộ nhớ khi số lượng phần tử thay đổi liên tục. Không lãng phí bộ nhớ nhưng cần thêm bộ nhớ để lưu phần con trỏ.
- Thêm hoặc xóa node ở đầu hoặc giữa danh sách có thể thực hiện nhanh chóng (O(1)) nếu bạn đã có địa chỉ của node cần thay đổi. Tuy nhiên, nếu muốn xóa hoặc thêm ở cuối danh sách, bạn cần phải duyệt qua danh sách trước (O(n)).
### Cấu trúc của 1 node
- Trong C, ta thường dùng cấu trúc (struct) để định nghĩa một node. Cấu trúc này bao gồm:
	- Dữ liệu (data): chứa giá trị hoặc thông tin của phần tử.
	- Con trỏ (pointer): chứa địa chỉ của node tiếp theo trong danh sách.
 		```c
		  typedef struct Node { // có Node ở dòng 1 để khi phiên dịch mã sẽ hiểu Node* next ở dòng 3, không báo lỗi
		    int data;           // Giá trị (dữ liệu) của node
		    struct Node* next;  // Con trỏ trỏ đến node tiếp theo
		};
  	- Node ở đây có phần dữ liệu là kiểu số nguyên, ngoài ra nó có 1 con trỏ next trỏ tới chính struct node (là địa chỉ của node tiếp theo trong linked list)
### Các thao tác với linked list
#### Khởi tạo Node 
    ```c
	#include <stdio.h>
	#include <stdlib.h>
	
	struct Node {
	    int data;     // Dữ liệu của node
	    struct Node* next; // Con trỏ tới node tiếp theo
	  };
	
	// Khởi tạo một node mới với dữ liệu là 10
	struct Node* createNode(int data) {
	    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // khởi tạo địa chỉ cho Node
	    newNode->data = data;
	    newNode->next = NULL; // chưa liên kết Node với nhau thì phải Null trước
	    return newNode; // trả về lại vị trí của newNode
	    }
	
	int main() {
	    struct Node* node1 = createNode(10);
	    printf("Data of the new node: %d\n", node1->data);
	    return 0;
	    }
#### Thêm một Node vào vị trí cuối cùng trong list
![image](https://github.com/user-attachments/assets/bd1b4279-90f5-4346-985b-9762961f2952)
- quy trình thêm một node vào cuối danh sách là:
	- Tạo node mới với dữ liệu bạn muốn thêm.
	- Nếu danh sách rỗng, gán node mới làm head.
	- Nếu danh sách không rỗng, duyệt qua danh sách đến node cuối cùng, sau đó gán con trỏ next của node cuối cùng trỏ đến node mới.
    ```c
	#include <stdio.h>
	#include <stdlib.h>
	
	struct Node {
	    int data;
	    struct Node* next;
	};
	
	// Hàm tạo node mới
	struct Node* createNode(int data) {
	    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	    newNode->data = data;
	    newNode->next = NULL;
	    return newNode;
	}
	
	// Hàm thêm node vào cuối danh sách
	void append(struct Node** head, int data) {
	    struct Node* newNode = createNode(data);
	    
	    // Nếu danh sách rỗng, gán node mới làm head
	    if (*head == NULL) {
	        *head = newNode;
	        return;
	    }
	
	    // Duyệt đến node cuối cùng
	    struct Node* last = *head;
	    while (last->next != NULL) {
	        last = last->next;
	    }
	
	    // Gán con trỏ next của node cuối cùng trỏ đến node mới
	    last->next = newNode;
	}
	
	// Hàm in danh sách liên kết
	void printList(struct Node* head) {
	    struct Node* temp = head;
	    while (temp != NULL) {
	        printf("%d -> ", temp->data);
	        temp = temp->next;
	    }
	    printf("NULL\n");
	}
	
	int main() {
	    struct Node* head = NULL;
	    
	    append(&head, 10);
	    append(&head, 20);
	    append(&head, 30);
	    
	    printList(head);  // Output: 10 -> 20 -> 30 -> NULL
	    return 0;}
#### Chèn một node vào vị trí đầu tiên trong list
- Tạo một node mới với dữ liệu bạn muốn chèn.
- Gán con trỏ next của node mới trỏ đến head hiện tại (node đầu tiên của danh sách).
- Cập nhật head để trỏ đến node mới
  ```c
	  // Hàm thêm một node vào đầu danh sách
	void insertAtHead(struct Node** head, int data) {
	    struct Node* newNode = createNode(data);  // Tạo node mới với dữ liệu
	
	    // Gán con trỏ next của node mới trỏ đến node đầu tiên (head) hiện tại
	    newNode->next = *head;
	    
	    // Cập nhật head để trỏ đến node mới
	    *head = newNode;
	}
	
	// Hàm in danh sách liên kết
	void printList(struct Node* head) {
	    struct Node* temp = head;
	    while (temp != NULL) {
	        printf("%d -> ", temp->data);  // In dữ liệu của node
	        temp = temp->next;             // Di chuyển đến node tiếp theo
	    }
	    printf("NULL\n");  // In kết thúc danh sách
	}
#### Chèn một node vào vị trí bất kì
- Tạo một node mới với dữ liệu bạn muốn chèn.
- Duyệt đến vị trí chèn: Bạn cần duyệt qua danh sách cho đến vị trí cần chèn. Vị trí này sẽ được chỉ định dưới dạng chỉ số (index).
- Chỉnh sửa các con trỏ: Sau khi tìm thấy vị trí chèn, bạn sẽ thực hiện các bước sau:
	- Gán con trỏ next của node mới trỏ tới node tại vị trí tiếp theo (nếu có).
	- Gán con trỏ next của node trước vị trí chèn (node tại vị trí index-1) trỏ tới node mới.
   ```c
	   // Hàm thêm một node vào vị trí bất kỳ trong danh sách
	void insertAtPosition(struct Node** head, int data, int position) {
	    // Nếu vị trí không hợp lệ (vị trí nhỏ hơn 0)
	    if (position < 0) {
	        printf("Vị trí không hợp lệ.\n");
	        return;
	    }
	
	    // Tạo node mới với dữ liệu cần thêm
	    struct Node* newNode = createNode(data);
	
	    // Nếu thêm ở đầu (vị trí 0)
	    if (position == 0) {
	        newNode->next = *head;  // Con trỏ next của node mới trỏ đến node đầu tiên
	        *head = newNode;        // Cập nhật head trỏ đến node mới
	        return;
	    }
	
	    // Duyệt đến node trước vị trí cần chèn (node ở vị trí position - 1)
	    struct Node* temp = *head;
	    for (int i = 0; i < position - 1 && temp != NULL; i++) {
	        temp = temp->next;
	    }
	
	    // Nếu temp là NULL, vị trí quá lớn, không thể thêm
	    if (temp == NULL) {
	        printf("Vị trí vượt quá danh sách hiện tại.\n");
	        free(newNode);
	        return;
	    }
	
	    // Gắn con trỏ next của node mới trỏ đến node tiếp theo của node hiện tại
	    newNode->next = temp->next;
	
	    // Gắn con trỏ next của node hiện tại trỏ đến node mới
	    temp->next = newNode;
	}
#### Xóa node đầu list
 	```c
		// Hàm xóa node đầu tiên trong danh sách
	void deleteAtHead(struct Node** head) {
	    // Kiểm tra danh sách có rỗng không
	    if (*head == NULL) {
	        printf("Danh sách rỗng, không có node để xóa.\n");
	        return;
	    }
	
	    // Lưu trữ node đầu tiên
	    struct Node* temp = *head;
	
	    // Cập nhật head để trỏ đến node tiếp theo
	    *head = (*head)->next;
	
	    // Giải phóng bộ nhớ của node đầu tiên
	    free(temp);
	}
#### xóa node cuối list
	```c
	// Hàm xóa node cuối cùng trong danh sách
	void deleteAtEnd(struct Node** head) {
	    // Kiểm tra danh sách có rỗng không
	    if (*head == NULL) {
	        printf("Danh sách rỗng, không có node để xóa.\n");
	        return;
	    }
	
	    // Nếu chỉ có một node duy nhất
	    if ((*head)->next == NULL) {
	        free(*head);  // Giải phóng bộ nhớ của node duy nhất
	        *head = NULL; // Cập nhật head về NULL
	        return;
	    }
	
	    // Duyệt đến node trước node cuối cùng
	    struct Node* temp = *head;
	    while (temp->next != NULL && temp->next->next != NULL) {
	        temp = temp->next;  // Di chuyển đến node trước node cuối cùng
	    }
	
	    // Xóa node cuối cùng
	    free(temp->next);  // Giải phóng bộ nhớ của node cuối cùng
	    temp->next = NULL;  // Cập nhật con trỏ next của node trước node cuối cùng thành NULL
#### Lấy kích thước của list
	```c
	// Hàm lấy kích thước của danh sách liên kết
	int getSize(struct Node* head) {
	    int size = 0;  // Khởi tạo biến đếm kích thước
	    struct Node* temp = head;
	    
	    // Duyệt qua danh sách và đếm số node
	    while (temp != NULL) {
	        size++;
	        temp = temp->next;  // Di chuyển đến node tiếp theo
	    }
	    
	    return size;
	}
  </details>
 <details><summary>LESSON 11: STACK AND QUEUE </summary>
  <p>
  
 ## LESSON 11: STACK AND QUEUE
 ### STACK
 - Trong ngôn ngữ C, stack (ngăn xếp) là một vùng nhớ được sử dụng để lưu trữ dữ liệu tạm thời trong suốt quá trình thực thi chương trình. Nó đặc biệt quan trọng trong quản lý bộ nhớ, đặc biệt khi làm việc với các hàm, các biến cục bộ, và các đối số của hàm.
#### Đặc điểm của Stack:
- Nguyên lý hoạt động (Last In, First Out - LIFO): Stack hoạt động theo nguyên lý LIFO, nghĩa là dữ liệu được lưu vào stack sẽ được lấy ra theo thứ tự ngược lại (mới nhất vào trước, cũ nhất ra trước). Trong thuật ngữ ngăn xếp, hoạt động chèn được gọi là hoạt động PUSH và hoạt động xóa được gọi là hoạt động POP.
  ![image](https://github.com/user-attachments/assets/c8833a29-ef73-4d44-9667-a1ecf25bf818)
- Lưu trữ dữ liệu tạm thời: Stack chủ yếu dùng để lưu trữ:
	- Các biến cục bộ (local variables)
	- Các tham số (parameters) của hàm
	- Địa chỉ trả về (return addresses) khi gọi hàm
- Tự động cấp phát và giải phóng bộ nhớ:
	- Bộ nhớ trên stack được cấp phát khi một hàm được gọi và giải phóng khi hàm đó hoàn tất.
	- Vì vậy, stack có tính "tự động" trong việc quản lý bộ nhớ: không cần phải dùng malloc() hay free() như với heap (đống).
-Hạn chế về kích thước: Kích thước của stack là có hạn và thường nhỏ hơn so với heap. Nếu chương trình sử dụng quá nhiều bộ nhớ trên stack (ví dụ: đệ quy quá sâu), có thể dẫn đến stack overflow.
#### Các thao tác trên Stack
- "push" để thêm một phần tử vào đỉnh của stack
- "pop" để xóa một phần tử ở đỉnh stack.
- “top” để lấy giá trị của phần tử ở đỉnh stack.
- Is_Full(): Kiểm tra xem ngăn xếp đã đầy chưa
- Is_Empty(): Kiểm tra xem ngăn xếp có trống hay không.
#### Định nghĩa Stack
	 ```c
	typedef struct Stack {
	    int* items; // mảng chứa các giá trị trong ngăn xếp
	    int size;   // kích thước của mảng đó
	    int top;   // giá trị của phần tử trên cùng
	  } Stack;
 #### Khởi tạo 1 stack
 	```c
	void initialize( Stack *stack, int size) {
	    stack->items = (int*) malloc(sizeof(int) * size); //cấp phát động 1 mảng chứa các giá trị
	    stack->size = size; // truyền vào kích thước mong muốn
	    stack->top = -1; // gắn giá trị trên cùng bằng -1
	}
#### Hoạt động Is_Full() trong cấu trúc dữ liệu ngăn xếp
	```c
	int Is_Full( Stack stack) {
	    return stack.top == stack.size - 1;
	}
#### Hoạt động Is_Empty() trong cấu trúc dữ liệu ngăn xếp
	 ```c
	int Is_Empty( Stack stack) {
	    return stack.top == -1;
	 }
#### Hoạt động Push() trong cấu trúc dữ liệu ngăn xếp
	```c
	void Push( Stack *stack, int value) {
	    if (!is_full(*stack)) {
	        stack->items[++stack->top] = value;
	    } else {
	        printf("Stack overflow\n");
	    }
	}
#### Hoạt động Pop() trong cấu trúc dữ liệu ngăn xếp
	```c
	int Pop( Stack *stack) {
	    if (!is_empty(*stack)) {
	        return stack->items[stack->top--];
	    } else {
	        printf("Stack underflow\n");
	        return -1;
	    }
	}
#### Hoạt động Top() trong cấu trúc dữ liệu ngăn xếp
	```c
	int Top( Stack stack) {
	    if (!is_empty(stack)) {
	        return stack.items[stack.top];
	    } else {
	        printf("Stack is empty\n");
	        return -1;
	    }
	}
#### ví dụ
	```c
	#include <stdio.h>
	#include <stdlib.h>
	
	typedef struct Stack {
	    int* items;
	    int size;
	    int top;
	} Stack;
	
	void initialize( Stack *stack, int size) {
	    stack->items = (int*) malloc(sizeof(int) * size);
	    stack->size = size;
	    stack->top = -1;
	}
	
	int is_empty( Stack stack) {
	    return stack.top == -1;
	}
	
	int is_full( Stack stack) {
	    return stack.top == stack.size - 1;
	}
	
	void push( Stack *stack, int value) {
	    if (!is_full(*stack)) {
	        stack->items[++stack->top] = value;
	    } else {
	        printf("Stack overflow\n");
	    }
	}
	
	int pop( Stack *stack) {
	    if (!is_empty(*stack)) {
	        return stack->items[stack->top--];
	    } else {
	        printf("Stack underflow\n");
	        return -1;
	    }
	}
	
	int top( Stack stack) {
	    if (!is_empty(stack)) {
	        return stack.items[stack.top];
	    } else {
	        printf("Stack is empty\n");
	        return -1;
	    }
	}
	
	int main() {
	    Stack stack1;
	    initialize(&stack1, 5);
	
	
	    push(&stack1, 10);
	    push(&stack1, 20);
	    push(&stack1, 30);
	    push(&stack1, 40);
	    push(&stack1, 50);
	    push(&stack1, 60);
	
	    printf("Top element: %d\n", top(stack1));
	
	    printf("Pop element: %d\n", pop(&stack1));
	    printf("Pop element: %d\n", pop(&stack1));
	
	    printf("Top element: %d\n", top(stack1));
	
	    return 0;
	}
 ### QUEUE
 - Queue (hàng đợi) là một cấu trúc dữ liệu dùng để lưu trữ và quản lý các phần tử theo nguyên lý FIFO (First In, First Out - Vào trước, ra trước). Điều này có nghĩa là phần tử được thêm vào đầu tiên sẽ được lấy ra đầu tiên. Queue thường được sử dụng trong các bài toán yêu cầu xử lý các phần tử theo thứ tự thời gian như trong các hệ thống lên lịch, xử lý sự kiện, hoặc các thuật toán tìm kiếm.
   ![image](https://github.com/user-attachments/assets/93917cbc-0101-45df-a710-3f3ce897ddae)
#### Đặc điểm của Queue
- Chỉ để cập tới Circular queue, ta có hai từ khóa front và rear:
	- front đại diện cho vị trí của phần tử đầu tiên trong hàng đợi. Đây là phần tử sẽ được lấy ra đầu tiên khi thực hiện thao tác dequeue (lấy phần tử ra).
	-rear đại diện cho vị trí của phần tử cuối cùng trong hàng đợi. Đây là phần tử cuối cùng được thêm vào khi thực hiện thao tác enqueue (thêm phần tử vào).
- Khi queue rỗng, front và rear bằng -1.
- Khi queue đầy, (rear + 1) % size == front.
- Khi thực hiện dequeue, chỉ số front sẽ được tăng lên để trỏ tới phần tử tiếp theo trong hàng đợi.
- Khi thực hiện enqueue, rear sẽ được tăng lên để trỏ tới vị trí mới cho phần tử vừa được thêm vào hàng đợi.
- Nếu hàng đợi đầy, rear sẽ quay vòng theo cơ chế vòng tròn (circular queue), điều này có nghĩa là khi rear đạt tới giới hạn của mảng, nó sẽ quay về 0 để sử dụng lại vị trí cũ chỉ khi có phần tử được dequeue.
  #### Các thao tác trên Queue
- enqueue(): Thêm 1 phần tử dữ liệu vào trong hàng đợi
- dequeue(): Xóa 1 phần tử từ hàng đợi
- Front(): lấy phần tử ở đầu hàng đợi, mà không xóa phần tử này
- Is_Full(): Kiểm tra xem hàng đợi đã đầy chưa
- Is_Empty(): Kiểm tra xem hàng đợi có trống hay không
  	```c
	#include <stdio.h>
	#include <stdlib.h>
	
	
	typedef struct Queue {
	    int* items;
	    int size;
	    int front, rear;
	} Queue;
	
	void initialize(Queue *queue, int size) 
	{
	    queue->items = (int*) malloc(sizeof(int)* size);
	    queue->front = -1;
	    queue->rear = -1;
	    queue->size = size;
	}
	
	int is_empty(Queue queue) {
	    return queue.front == -1;
	}
	
	int is_full(Queue queue) {
	    return (queue.rear + 1) % queue.size == queue.front;
	}
	
	void enqueue(Queue *queue, int value) {
	    if (!is_full(*queue)) {
	        if (is_empty(*queue)) {
	            queue->front = queue->rear = 0;
	        } else {
	            queue->rear = (queue->rear + 1) % queue->size;
	        }
	        queue->items[queue->rear] = value;
	    } else {
	        printf("Queue overflow\n");
	    }
	}
	
	int dequeue(Queue *queue) {
	    if (!is_empty(*queue)) {
	        int dequeued_value = queue->items[queue->front];
	        if (queue->front == queue->rear) {
	            queue->front = queue->rear = -1;
	        } else {
	            queue->front = (queue->front + 1) % queue->size;
	        }
	        return dequeued_value;
	    } else {
	        printf("Queue underflow\n");
	        return -1;
	    }
	}
	
	int front(Queue queue) {
	    if (!is_empty(queue)) {
	        return queue.items[queue.front];
	    } else {
	        printf("Queue is empty\n");
	        return -1;
	    }
	}
	
	int main() {
	    Queue queue;
	    initialize(&queue, 3);
	
	    enqueue(&queue, 10);
	    enqueue(&queue, 20);
	    enqueue(&queue, 30);
	
	    printf("Front element: %d\n", front(queue));
	
	    printf("Dequeue element: %d\n", dequeue(&queue));
	    printf("Dequeue element: %d\n", dequeue(&queue));
	
	    printf("Front element: %d\n", front(queue));
	
	    enqueue(&queue, 40);
	    enqueue(&queue, 50);
	    printf("Dequeue element: %d\n", dequeue(&queue));
	    printf("Front element: %d\n", front(queue));
	
	    return 0;
	}

</details>
   
 <details><summary>LESSON 12: BINARY SEARCH - FILE OPERATIONS - CODE STANDARDS </summary>
  <p>
  
 ## LESSON 12: BINARY SEARCH - FILE OPERATIONS - CODE STANDARDS
 ### BINARY SEARCH
 - Binary Search (tìm kiếm nhị phân) là một thuật toán tìm kiếm hiệu quả trong một danh sách đã được sắp xếp (tăng dần hoặc giảm dần). Thuật toán này hoạt động bằng cách liên tục chia đôi danh sách và so sánh giá trị cần tìm với phần tử ở giữa, từ đó loại bỏ một nửa của danh sách và tiếp tục tìm kiếm trong nửa còn lại.
#### Các bước mô tả thuật toán
- Khởi tạo: Đặt hai chỉ số left và right lần lượt trỏ tới phần tử đầu và phần tử cuối của danh sách.
- Tính giữa: Tính chỉ số của phần tử ở giữa danh sách bằng công thức: mid = (left + right) /2
- So sánh:
	- Nếu phần tử giữa bằng giá trị cần tìm, thuật toán kết thúc và trả về chỉ số của phần tử.
	- Nếu phần tử giữa lớn hơn giá trị cần tìm, tìm kiếm sẽ tiếp tục ở nửa bên trái của danh sách, tức là điều chỉnh lại right = mid - 1.
	- Nếu phần tử giữa nhỏ hơn giá trị cần tìm, tìm kiếm sẽ tiếp tục ở nửa bên phải của danh sách, tức là điều chỉnh lại left = mid + 1.
- Lặp lại: Lặp lại bước 2 và 3 cho đến khi giá trị được tìm thấy hoặc không còn phần tử nào để kiểm tra (left > right).
#### Đặc điểm:
- Thời gian chạy: Thuật toán tìm kiếm nhị phân có thời gian chạy O(log n), rất nhanh khi so với tìm kiếm tuyến tính O(n), đặc biệt là với các danh sách có kích thước lớn.
- Yêu cầu: Danh sách phải được sắp xếp (theo thứ tự tăng dần hoặc giảm dần).
#### Ví dụ tìm kiếm nhị phân
	 ```c
	#include <stdio.h>
	#include <stdlib.h>
	
	int binarySearch(int* arr, int l, int r, int x)
	{
	    if (r >= l)
	    {
	        int mid = (r + l) / 2;
	
	  
	        if (arr[mid] == x)  return mid;
	
	   
	        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
	
	  
	        return binarySearch(arr, mid + 1, r, x);
	    }
	
	
	
	
	    return -1;
	}
	
	void swap(int *a, int *b)
	{
	    int temp = *a; // 0x02 (10), 0x03 (20)
	    *a = *b;
	    *b = temp;
	}
	
	void bubbleSort(int arr[], int n)
	{
	    int i, j;
	    for (i = 0; i < n - 1; i++)
	    {
	       
	        for (j = 0; j < n - i - 1; j++)
	        {
	           
	            if (arr[j] > arr[j + 1])
	                swap(&arr[j], &arr[j + 1]);
	        }
	    }
	}
	
	int main()
	{
		int n, x, i;
	    printf("Nhap so phan tu cua mang: ");
	    scanf_s("%d", &n);
	    int* arr = (int*)malloc(n * sizeof(int));
	    printf("Nhap cac phan tu cua mang: ");
	    for (i = 0; i < n; i++)
	    {
	        scanf_s("%d", &arr[i]);
	    }
	
	    bubbleSort(arr, n);
	    for (int i = 0; i < n; i++)
	    {
	        printf_s("i = %d\n", arr[i]);
	    }
	
	    printf_s("Nhap gia tri can tim: ");
	    scanf_s("%d", &x);
	    int result = binarySearch(arr, 0, n - 1, x);
	    if (result == -1)
	        printf_s("Khong tim thay %d trong mang.\n", x);
	    else
	        printf_s("Tim thay %d tai vi tri %d trong mang.\n", x, result);
	    free(arr);
	    return 0;
	}
### FILE OPERATIONS
- Ngôn ngữ lập trình C cung cấp một số thư viện và hàm tiêu biểu để thực hiện các thao tác với file. 
- File CSV (Comma-Separated Values) là một loại file văn bản được sử dụng để lưu trữ và truyền tải dữ liệu có cấu trúc dưới dạng bảng, trong đó các dữ liệu của các cột được phân tách bằng dấu phẩy (,) hoặc một ký tự ngăn cách khác.
#### Mở file
- Để mở một file, bạn có thể sử dụng hàm fopen(). Hàm này trả về một con trỏ FILE, và cần được kiểm tra để đảm bảo file đã mở thành công.
	```c
	FILE *file = fopen(const char *file_name, const char *access_mode);
	// filename: Tên tệp tin.
	// mode: Chế độ mở tệp tin (ví dụ: "r", "w", "a", "r+", "w+", ...).
#### Đọc file
- Đọc từ tệp tin: Sau khi mở tệp tin, bạn có thể đọc dữ liệu từ tệp bằng các hàm như fgetc(), fgets(), hoặc fread().
	- fgetc(FILE *stream): Đọc một ký tự từ tệp tin.
	- fgets(char *str, int num, FILE *stream): Đọc một dòng từ tệp tin.
	- fread(void *ptr, size_t size, size_t count, FILE *stream): Đọc dữ liệu vào bộ nhớ.
#### Ghi file
- Ghi vào tệp tin: Bạn có thể ghi dữ liệu vào tệp bằng các hàm như fputc(), fputs(), hoặc fwrite().

	- fputc(int char, FILE *stream): Ghi một ký tự vào tệp.
	- fputs(const char *str, FILE *stream): Ghi một chuỗi vào tệp.
	- fwrite(const void *ptr, size_t size, size_t count, FILE *stream): Ghi dữ liệu vào tệp từ bộ nhớ.
 #### Đóng file
- Đóng tệp tin: Sau khi hoàn thành việc thao tác với tệp, bạn cần đóng tệp để giải phóng tài nguyên bằng cách sử dụng hàm fclose().

	```c
	int fclose(FILE *stream);
#### Kiểm tra lỗi hoặc kết thúc tệp
- feof(FILE *stream): Kiểm tra nếu con trỏ tệp đang ở cuối tệp.
- ferror(FILE *stream): Kiểm tra nếu có lỗi xảy ra khi làm việc với tệp.
#### Di chuyển con trỏ tệp:
- fseek(FILE *stream, long offset, int whence): Di chuyển con trỏ tệp đến vị trí mới.
- ftell(FILE *stream): Lấy vị trí hiện tại của con trỏ tệp.
- rewind(FILE *stream): Đặt con trỏ tệp về vị trí đầu của tệp.
  
#### Ví dụ về thao tác với tệp tin trong C:
	```c

	#include <stdio.h>
	
	int main() {
	    FILE *file;
	    char str[100];
	
	    // Mở tệp để ghi
	    file = fopen("example.txt", "w");
	    if (file == NULL) {
	        printf("Không thể mở tệp\n");
	        return 1;
	    }
	
	    // Ghi vào tệp
	    fprintf(file, "Hello, World!\n");
	    fclose(file);
	
	    // Mở tệp để đọc
	    file = fopen("example.txt", "r");
	    if (file == NULL) {
	        printf("Không thể mở tệp\n");
	        return 1;
	    }
	
	    // Đọc dữ liệu từ tệp
	    while (fgets(str, sizeof(str), file)) {
	        printf("%s", str);
	    }
	
	    fclose(file);
	
	    return 0;
	}
#### Các chế độ mở tệp tin:
Tham số truyền vào access_mod là quyền sử dụng file:

- r: Mở file với chế độ chỉ đọc file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- rb: Mở file với chế độ chỉ đọc file theo định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- w: Mở file với chế độ ghi vào file. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- wb: Mở file với chế độ ghi vào file theo định dạng binary. Nếu file đã tồn tại, thì sẽ ghi đè vào nội dung bên trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- a: Mở file với chế độ nối. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- ab: Mở file với chế độ nối dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử cuối cùng trong file. Nếu file chưa tồn tại thì sẽ tạo một file mới. Nếu không mở được file thì trả về NULL.
- r+: Mở file với chế độ đọc và ghi file. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
- rb+: Mở file với chế độ đọc và ghi file dưới định dạng binary. Nếu mở file thành công thì trả về địa chỉ của phần tử đầu tiên trong file, nếu không thì trả về NULL.
</details>
<details><summary>LESSON 13: CLASS </summary>
  <p>
  
 ## LESSON 13:CLASS
 ### Định nghĩa Class
 - Trong C++, từ khóa "class" được sử dụng để định nghĩa một lớp, là một cấu trúc dữ liệu tự định nghĩa có thể chứa dữ liệu và các hàm thành viên liên quan. 
 	```cpp
  	class ClassName {
	private:
	    // Các thành phần riêng tư (private) chỉ có thể truy cập bên trong lớp
	    // Dữ liệu thành viên, hàm thành viên, ...
	
	protected:
	    // Các thành phần bảo vệ (protected) tương tự như private, nhưng có thể truy cập từ lớp kế thừa
	
	public:
	    // Các thành phần công khai (public) được truy cập từ bên ngoài lớp
	    // Dữ liệu thành viên, hàm thành viên, ...
	    // Hàm thành viên và các phương thức khác có thể được định nghĩa tại đây
	    // ...
    	 };
- Các hàm trong Class được gọi là phương thức, các biến thì được gọi là thuộc tính. Các phương thức và thuộc tính có các mức độ triển khai khác nhau như:
	- Public: Các hàm khác có thể truy cập được các phương thức, thuộc tính từ bên ngoài lớp.
	- Private: Chỉ có khả năng truy cập từ bên trong lớp, bên ngoài muốn truy cập thì phải gián tiếp thông qua các hàm get, set.
	- Protected: Truy cập cục bộ trong Class hoặc các Class kế thừa. Các cách triển khai này nhằm mục đích đảm báo tính bảo mật cho các thuộc tính, phương thức trong Class bằng cách hạn chế quyền truy cập từ bên ngoài.
	
- ví dụ:
	```cpp
 	#include <iostream>
	using namespace std;
	
	class TenLop {
	private:
	    // Các thuộc tính riêng tư
	    int thuocTinh1;
	    int thuocTinh2;
	
	public:
	    // Constructor
	    TenLop(int thamSo1, int thamSo2) {
	        thuocTinh1 = thamSo1;
	        thuocTinh2 = thamSo2;
	    }
	
	    // Phương thức để thiết lập giá trị
	    void setThuocTinh1(int giaTri) {
	        thuocTinh1 = giaTri;
	    }
	
	    void setThuocTinh2(int giaTri) {
	        thuocTinh2 = giaTri;
	    }
	
	    // Phương thức để lấy giá trị
	    int getThuocTinh1() {
	        return thuocTinh1;
	    }
	
	    int getThuocTinh2() {
	        return thuocTinh2;
	    }
	
	    // Phương thức hiển thị thông tin
	    void hienThi() {
	        cout << "Thuoc tinh 1: " << thuocTinh1 << ", Thuoc tinh 2: " << thuocTinh2 << endl;
	    }
	};
	
	int main() {
	    // Tạo một đối tượng từ lớp TenLop
	    TenLop doiTuong(10, 20);
	
	    // Gọi phương thức của đối tượng
	    doiTuong.hienThi();
	
	    // Thay đổi giá trị thuộc tính và hiển thị lại
	    doiTuong.setThuocTinh1(30);
	    doiTuong.setThuocTinh2(40);
	    doiTuong.hienThi();
	
	    return 0;
	}
 	- class TenLop: Khai báo một lớp với tên là TenLop.
	- Thuộc tính (thuocTinh1, thuocTinh2): Được khai báo trong phần private, nghĩa là chỉ có thể truy cập thông qua các phương thức của lớp.
	- Phương thức (setThuocTinh1, getThuocTinh1, hienThi): Được khai báo trong phần public, nghĩa là có thể truy cập từ bên ngoài lớp.
	- Constructor: Phương thức đặc biệt có cùng tên với lớp, được gọi khi một đối tượng của lớp được tạo ra để khởi tạo giá trị ban đầu cho các thuộc tính.
 ### Các cách thức truy tập thuộc tính và phương thức trong class
 #### Truy cập thuộc tính và phương thức kiểu công khai
 - Để truy cập một thuộc tính thuộc kiểu Public:
	```cpp
		// Tạo một đối tượng từ lớp TenLop
		    TenLop doiTuong(10, 20);
		
		    // Gọi phương thức của đối tượng
		    doiTuong.hienThi();
		
		    // Thay đổi giá trị thuộc tính và hiển thị lại
		    doiTuong.setThuocTinh1(30);
		    doiTuong.setThuocTinh2(40);
- Ta sẽ trực tiếp lấy giá trị của thuộc tính đó thông qua cú pháp tenClass.tenThuocTinh
- Tương tự với các phương thức được gọi cũng có cú pháp tenClass.tenPhuongThuc()
#### Truy cập thuộc tính và phương thức kiểu riêng tư
	```cpp
 
 	private:
	// Các thuộc tính riêng tư
	int thuocTinh1;
	int thuocTinh2;
- Các thuộc tính và phương thức private không thể được truy cập trực tiếp từ bên ngoài lớp. Phải sử dụng các phương thức công khai(các method public) để truy cập hoặc thay đổi giá trị.
- ví dụ:
  	```cpp
  	 #include <iostream>
	using namespace std;
	
	class Person {
	private:
	    string name;
	    int age;
	
	public:
	    // Setter cho thuộc tính name
	    void setName(string n) {
	        name = n;
	    }
	
	    // Getter cho thuộc tính name
	    string getName() {
	        return name;
	    }
	
	    // Setter cho thuộc tính age
	    void setAge(int a) {
	        if (a >= 0) {
	            age = a;
	        } else {
	            cout << "Invalid age!" << endl;
	        }
	    }
	
	    // Getter cho thuộc tính age
	    int getAge() {
	        return age;
	    }
	};
	
	int main() {
	    Person p;
	
	    p.setName("Alice");
	    p.setAge(20);
	
	    cout << "Name: " << p.getName() << ", Age: " << p.getAge() << endl;
	
	    return 0;
	}
#### Truy cập thuộc tính và phương thức thông qua con trỏ
-  ta sẽ tạo một đối tượng tên Test1 và tạo một đối tượng con trỏ ptr trỏ đến Test1. Khi đó để truy cập các thuộc tính của Test1 thông qua ptr ta phải thay dấu . thành ->
	```cpp
	#include <iostream>
	using namespace std;
	
	class Test {
	public:
	    int value;
	
	    void display() {
	        cout << "Giá trị của Value: " << value << endl;
	    }
	};
	
	int main() {
	    Test Test1;
	    Test* ptr = &Test1;  // Tạo con trỏ trỏ đến object Test1
	
	    ptr->value = 100;  // Thay đổi giá trị thuộc tính thông qua con trỏ
	
	    ptr->display();  // Gọi phương thức in ra giá trị value thông qua con trỏ
	
	    return 0;
	}

  ### Constructor
-  Constructor trong C++ là một method sẽ được tự động gọi khi khởi tạo object. Constructor sẽ có tên trùng với tên của class. Mục đích chính của constructor là khởi tạo giá trị ban đầu cho các thuộc tính của đối tượng hoặc thực hiện các thao tác thiết lập cần thiết.
#### Đặc điểm
- Tên Method trùng tên Class: Constructor có tên giống với tên lớp.
- Không có kiểu trả về: Constructor không có kiểu trả về, kể cả void.
- Tự động được gọi: Khi một đối tượng được tạo, constructor sẽ tự động được gọi mà không cần gọi trực tiếp.
- Có thể có tham số: Constructor có thể nhận tham số để khởi tạo giá trị cho các thuộc tính.
#### Cú pháp Constructor
- ví dụ:
	```cpp

	class ClassName {
	public:
	    ClassName(); // Constructor không tham số
	    ClassName(int x, int y); // Constructor có tham số
	};
#### Constructor không có tham số
- ví dụ 1:
	```cpp

	#include <iostream>
	using namespace std;
	
	class Person {
	private:
	    string name;
	
	public:
	    // Constructor không tham số
	    Person() {
	        name = "Unknown";
	        cout << "Constructor is called!" << endl;
	    }
	
	    void display() {
	        cout << "Name: " << name << endl;
	    }
	};
	
	int main() {
	    Person p; // Gọi constructor tự động
	    p.display();
	    return 0;
	}
- Kết quả:
  	```cpp
	Constructor is called!
	Name: Unknown
#### Constructor có tham số
- ví dụ 2:
	```cpp
	#include <iostream>
	using namespace std;
	
	class Person {
	private:
	    string name;
	    int age;
	
	public:
	    // Constructor có tham số
	    Person(string n, int a) {
	        name = n;
	        age = a;
	    }
	
	    void display() {
	        cout << "Name: " << name << ", Age: " << age << endl;
	    }
	};
	
	int main() {
	    Person p("Alice", 25); // Truyền tham số cho constructor
	    p.display();
	
	    return 0;
	}
- Kết quả:
	Name: Alice, Age: 25
#### Constructor mặc định và overloading constructor
- ví dụ 3:
	```cpp

	#include <iostream>
	using namespace std;
	
	class Rectangle {
	private:
	    int width, height;
	
	public:
	    // Constructor không tham số
	    Rectangle() {
	        width = height = 0;
	    }
	
	    // Constructor có tham số
	    Rectangle(int w, int h) {
	        width = w;
	        height = h;
	    }
	
	    int getArea() {
	        return width * height;
	 }
	};
	
	int main() {
	    Rectangle rect1; // Gọi constructor không tham số
	    Rectangle rect2(5, 10); // Gọi constructor có tham số
	
	    cout << "Area of rect1: " << rect1.getArea() << endl;
	    cout << "Area of rect2: " << rect2.getArea() << endl;
	
	    return 0;
	}
- Kết quả:
  	```cpp
	Area of rect1: 0
	Area of rect2: 50
### Destructor
- Destructor là một phương thức đặc biệt của lớp, được gọi tự động khi đối tượng của lớp đó bị hủy (ra khỏi phạm vi hoạt động hoặc chương trình kết thúc). Destructor thường được sử dụng để giải phóng tài nguyên như bộ nhớ động, đóng file hoặc dọn dẹp các thao tác khác.
#### Đặc điểm
- Tên giống với tên lớp, nhưng có thêm dấu ~ ở đầu: Destructor có tên giống với tên lớp nhưng có dấu ~ đứng trước (ví dụ, nếu tên lớp là MyClass, destructor sẽ có tên là ~MyClass).
- Không có tham số: Destructor không nhận tham số nào.
- Không có kiểu trả về: Destructor không có kiểu trả về, kể cả void.
- Tự động được gọi: Destructor được tự động gọi khi:
	- Đối tượng đi ra khỏi phạm vi (scope).
	- Đối tượng bị xóa bằng từ khóa delete.
	- Chương trình kết thúc.
 #### Cú pháp
 - Cú pháp:
 	```cpp
	 class ClassName {
	public:
	    ~ClassName();  // Destructor có dấu ~ đứng trước tên lớp
	};
- Ví dụ 1: Destructor đơn giản
	```cpp

	#include <iostream>
	using namespace std;
	
	class Demo {
	public:
	    Demo() {
	        cout << "Constructor called!" << endl;
	    }
	
	    ~Demo() {
	        cout << "Destructor called!" << endl;
	    }
	};
	
	int main() {
	    Demo obj;
	    cout << "Inside main function." << endl;
	
	    return 0;
	}
- Kết quả:

	```cpp
	Constructor called!
	Inside main function.
	Destructor called!
 - ví dụ 2: Destructor giải phóng bộ nhớ động
   	```cpp
	 #include <iostream>
	using namespace std;
	
	class Array {
	private:
	    int* data;
	    int size;
	
	public:
	    // Constructor cấp phát bộ nhớ
	    Array(int s) {
	        size = s;
	        data = new int[size];
	        cout << "Memory allocated for array of size " << size << endl;
	    }
	
	    // Destructor giải phóng bộ nhớ
	    ~Array() {
	        delete[] data;
	        cout << "Memory deallocated!" << endl;
	    }
	
	    void setValue(int index, int value) {
	        if (index >= 0 && index < size) {
	            data[index] = value;
	        }
	    }
	
	    int getValue(int index) {
	        if (index >= 0 && index < size) {
	            return data[index];
	        }
	        return -1;
	    }
	};
	
	int main() {
	    Array arr(5);
	    arr.setValue(0, 42);
	    cout << "Value at index 0: " << arr.getValue(0) << endl;
	
	    return 0;
	}
- Kết quả:
	```cpp
	Memory allocated for array of size 5
	Value at index 0: 42
	Memory deallocated!
 ### Static 
 #### Static Property
 - Static property (thuộc tính tĩnh) là một thuộc tính dùng chung cho tất cả các đối tượng của lớp. Thay vì mỗi đối tượng có một bản sao riêng của thuộc tính đó, các đối tượng sẽ chia sẻ một bản sao duy nhất.
- Đặc điểm:
	- Khi một property trong class được khai báo với từ khóa static, thì tất cả các object sẽ dùng chung địa chỉ của property này.
	- Các đối tượng sử dụng dung một địa chỉ của thuộc tính, nên thuộc tính này có giá trị như nhau với các đối tượng khác nhau
	- Cần phải khởi tạo bên ngoài Class, khởi tạo toàn cục, cấp phát địa chỉ cho biến static trước khi khởi tạo object
	- Bạn có thể truy cập static property bằng cách sử dụng tên class hoặc thông qua một đối tượng của class
	- Truy cập: Có thể truy cập staticVar bằng cách dùng MyClass::staticVar hoặc obj.staticVar.
- Lưu ý:
	- Static property không thể được khởi tạo trực tiếp bên trong class (trừ khi là const static).
	- Nếu cần các phép toán phức tạp cho việc khởi tạo, bạn có thể sử dụng một hàm static hoặc một khối static trong file định nghĩa.
- Ví dụ:
  	```cpp
	#include <iostream>
	using namespace std;
	
	class Counter {
	public:
	    static int count;  // Khai báo static property
	
	    Counter() {
	        count++;  // Tăng giá trị thuộc tính tĩnh mỗi khi tạo đối tượng
	    }
	
	    static void showCount() {
	        cout << "Current count: " << count << endl;
	    }
	};
	
	// Định nghĩa và khởi tạo static property bên ngoài lớp
	int Counter::count = 0;
	
	int main() {
	    Counter c1, c2;
	    Counter::showCount();  // Truy cập thuộc tính tĩnh qua tên lớp
	
	    return 0;
	}
- Kết quả:
	```cpp
	Current count: 2
- Giải thích
	- Counter::count = 0; là phần định nghĩa thuộc tính tĩnh bên ngoài lớp.
	- Mỗi khi tạo một đối tượng của lớp Counter, giá trị count tăng thêm 1.
	- Counter::showCount() truy cập vào thuộc tính tĩnh mà không cần thông qua bất kỳ đối tượng nào.
 #### Static method
 - Static method (phương thức tĩnh) trong C++ là một hàm thành viên của class nhưng không hoạt động trên instance cụ thể nào của class. Thay vào đó, nó thuộc về class và có thể được gọi mà không cần tạo instance của class.
- Đặc điểm của Static Method:
	- Không cần instance: Static method có thể được gọi trực tiếp thông qua tên class mà không cần tạo object.( các method còn lại của class phải truy cập thông qua object)
	- Không thể truy cập non-static members: Static method không thể trực tiếp truy cập các thuộc tính hoặc phương thức không static của class, vì chúng không có ngữ cảnh (context) của một instance cụ thể.
	-Có thể truy cập static members: Static method có thể truy cập các thuộc tính và phương thức static khác của class.
- ví dụ:
  	```cpp
	   class MyClass {
	public:
	    static void staticMethod() {
	        std::cout << "Static method called" << std::endl;
	    }
	
	    static int staticVar;
	
	    static void setStaticVar(int value) {
	        staticVar = value;
	    }
	
	    static int getStaticVar() {
	        return staticVar;
	    }
	};
	
	// Định nghĩa và khởi tạo static property
	int MyClass::staticVar = 0;
	
	int main() {
	    // Gọi static method trực tiếp thông qua class
	    MyClass::staticMethod();
	
	    // Gọi static method để thay đổi static property
	    MyClass::setStaticVar(10);
	    std::cout << "StaticVar: " << MyClass::getStaticVar() << std::endl;
	
	    return 0;
	}
 </details>
  <details><summary>LESSON 14: AUTOSAR CLASSIC  </summary>
  <p>
	  
 ## LESSON 14: AUTOSAR CLASSIC
 ### Khái niệm
- AUTOSAR (AUTomotive Open System ARchitecture) Classic Platform là một tiêu chuẩn kiến trúc phần mềm dành cho hệ thống nhúng trên ô tô, đặc biệt tập trung vào các hệ thống điều khiển thời gian thực và an toàn chức năng. Đây là nền tảng truyền thống của AUTOSAR, phù hợp với các ECU (Electronic Control Unit) có tài nguyên hạn chế nhưng yêu cầu hiệu suất cao.
### Lí do cần có Autosar classic
- Automotive là một hệ thống phức tạp bao gồm nhiều hệ thống nhỏ hơn gọi là ECUs - Electronic Control Unit, nên việc bảo trì và phát triển phần mềm cho từng ECU là việc không dễ. Độ phức tạp càng tăng thêm khi các ECU khác nhau sử dụng các MCU khác nhau để đáp ứng các yêu cầu về mặt ứng dụng và chi phí. Vì vậy, có thể chúng ta sẽ cần phát triển rất nhiều phần mềm khác nhau cho các MCU này.
- Với cách viết phần mềm thông thường, để giao tiếp giữa nhiều ECU khác nhau, nhà phát triển sẽ cần tạo ra các giao thức, tiêu chuẩn giao tiếp, gọi là Custom standard. Việc này rất tốt, nhưng lần sau làm việc với chiếc xe khác, các ECU khác thì lại rất khó để maintain và tốn nhiều chi phí hơn.
- Một chiếc ô tô có nhiều bộ phận được sản xuất bởi các công ty khác nhau được gọi là công ty tier 1, cung cấp phụ tùng cho các OEM như BMW, Volkswagen, ... Ngày nay, hầu hết các bộ phận cơ khí đều trở nên thông minh hơn bằng cách thêm các ECU vào. Vì vậy cũng cần có các tiêu chuẩn để giao tiếp với cả những ECU của OEM khác nhau này.
    ⏩ Với những lý do nêu trên, cần có một số tiêu chuẩn thiết kế phần mềm để có thể thống nhất việc phát triển và giao tiếp giữa các ECU khác nhau, của các OEM khác nhau. Và AUTOSAR sinh ra từ đây để giải quyết những vấn đề trên.
### Lợi ích của Autosar classic 
##### 1. Chuẩn hóa và tái sử dụng phần mềm 🔄
- Trước AUTOSAR: Mỗi nhà sản xuất ô tô (OEM) và nhà cung cấp (Tier-1) tự phát triển phần mềm cho từng loại ECU, gây khó khăn trong việc tích hợp và bảo trì.
- Với AUTOSAR: Các thành phần phần mềm (Software Components - SWC) được chuẩn hóa, có thể tái sử dụng trên nhiều dòng xe và ECU khác nhau, giúp tiết kiệm chi phí và thời gian phát triển.
##### 2. Tương thích giữa các nhà cung cấp khác nhau 🌍
- AUTOSAR tạo ra một giao diện chung giữa các thành phần phần mềm, giúp OEM dễ dàng tích hợp phần mềm từ nhiều nhà cung cấp mà không lo vấn đề tương thích.
- Các nhà cung cấp phần mềm, phần cứng và công cụ phát triển có thể hợp tác dễ dàng hơn.
##### 3. Hỗ trợ đa dạng giao thức truyền thông 📡
- AUTOSAR Classic hỗ trợ nhiều giao thức truyền thông phổ biến trong ô tô như:
	✅ CAN (Controller Area Network)
	✅ LIN (Local Interconnect Network)
	✅ FlexRay
	✅ Ethernet
-> Điều này giúp hệ thống có thể giao tiếp dễ dàng giữa các ECU mà không cần phải thay đổi nhiều về phần mềm.
##### 4. Đảm bảo an toàn và bảo mật 🔐
- AUTOSAR tuân thủ tiêu chuẩn ISO 26262 về An toàn chức năng trong ô tô, giúp đảm bảo hệ thống không gây nguy hiểm trong trường hợp lỗi xảy ra.
- Các cơ chế bảo mật như mã hóa dữ liệu, phát hiện xâm nhập giúp bảo vệ hệ thống khỏi các cuộc tấn công mạng.
##### 5. Hỗ trợ hệ thống thời gian thực (Real-Time) ⏱️
- AUTOSAR Classic được thiết kế để hoạt động trên các hệ thống thời gian thực cứng (Hard Real-Time), yêu cầu độ chính xác cao.
- Phù hợp với các hệ thống điều khiển quan trọng như: Hệ thống phanh ABS/ Hộp số tự động/✅ Điều khiển động cơ (ECU Engine Control Unit)
##### 6. Giảm chi phí và thời gian phát triển ⏳💰
- Nhờ tính mô-đun và tiêu chuẩn hóa, các nhà phát triển không cần viết lại phần mềm từ đầu mỗi khi có thay đổi phần cứng hoặc tính năng mới.
- Dễ dàng bảo trì và nâng cấp hệ thống khi có công nghệ mới mà không phải sửa đổi toàn bộ phần mềm.
##### 7. Tích hợp dễ dàng với các công cụ phát triển 🛠️
- AUTOSAR Classic được hỗ trợ bởi nhiều công cụ phát triển mạnh mẽ như Vector, Elektrobit, dSPACE, ETAS, giúp việc thiết kế, kiểm thử và triển khai trở nên dễ dàng hơn.
- Hỗ trợ các hệ điều hành thời gian thực (RTOS) như OSEK, Tresos, PikeOS,...
![image](https://github.com/user-attachments/assets/b78d3f56-f746-44b6-a81c-84f04ff51555)
### Kiến trúc
![image](https://github.com/user-attachments/assets/59eb35c7-e564-4413-886d-80effbec2132)
- Kiến trúc phân lớp của AUTOSAR:
	- Application Layer: Bao gồm các thành phần phần mềm ứng dụng, thực hiện các chức năng cụ thể của xe (như kiểm soát động cơ, phanh, v.v).
	- Runtime Environment (RTE): Là lớp trung gian giữa phần mềm ứng dụng và phần mềm cơ bản, giúp phần mềm ứng dụng có thể giao tiếp với nhau một cách chuẩn hóa (liên kết SWC và BSW).
	- Basic Software (BSW): Là phần mềm cơ bản, bao gồm các thành phần phần mềm tiêu chuẩn để quản lý các chức năng hệ thống, giao tiếp và điều khiển phần cứng.
#### Application layer
- Bao gồm nhiều khối phần mềm ứng dụng (Software Component - SWC). Mỗi SWC thực hiện 1 chức năng cụ thể trong hệ thống ECU. 
- SWC chỉ quan tâm đến logic (tính toán số học, khởi động thế nào), không cần quan tâm đến phần cứng. Tuy nhiên, SWC vẫn có thể giao tiếp với nhau và giao tiếp với phần cứng thông qua RTE.
![image](https://github.com/user-attachments/assets/cb2577eb-68c0-4584-b6fb-8ef8a77fe281)
#### Runtime Environment (RTE)
- RTE đóng vai trò quan trọng trong việc kết nối Software Components (SWC) và Basic Software (BSW) thông qua một kiến trúc trừu tượng.
- Một số chức năng của RTE:
	- Truyền thông tin giữa các SWCs: RTE cung cấp cơ chế truyền thông để các thành phần phần mềm (SWCs) có thể trao đổi dữ liệu hoặc gọi dịch vụ với nhau mà không cần biết chi tiết về các phần còn lại của hệ thống. 
	- Kết nối với BSW: RTE cung cấp giao diện để các SWCs có thể tương tác với BSW. Điều này giúp các SWCs có thể sử dụng các dịch vụ hoặc điều khiển phần cứng một cách dễ dàng.
	- Hỗ trợ việc lập lịch và điều phối thực thi của các SWCs theo các sự kiện hoặc chu kỳ định sẵn. 
#### Basic Software (BSW)
- Basic Software (BSW) là một trong ba thành phần chính của kiến trúc AUTOSAR, đóng vai trò nền tảng để hỗ trợ phần mềm ứng dụng (SWC) hoạt động trên phần cứng. BSW cung cấp các dịch vụ cơ bản như quản lý phần cứng, giao tiếp, chẩn đoán, và các dịch vụ hệ thống.
- BSW được chia thành 3 lớp chính:
	- Service Layer.
	- ECU Abstraction Layer.
	- Microcontroller Abstraction Layer - MCAL.
##### Service Layer:
- Đây là lớp cao nhất trong BSW, cung cấp các dịch vụ hệ thống và tiện ích cho các phần mềm ứng dụng (SWC) và các lớp khác của BSW. Các dịch vụ này bao gồm quản lý thời gian thực, chẩn đoán, quản lý lỗi, quản lý nguồn, v.v.
##### ECU Abstraction Layer:
- Lớp này cung cấp một giao diện trừu tượng cho tất cả các thiết bị ngoại vi và phần cứng cụ thể của ECU. Nó ẩn đi sự khác biệt về phần cứng của các thiết bị ngoại vi khác nhau và cung cấp một giao diện tiêu chuẩn cho các lớp bên trên (Service Layer và SWC).
##### MCAL:
- Đây là lớp thấp nhất trong BSW, cung cấp giao diện trừu tượng để tương tác trực tiếp với các thành phần phần cứng của vi điều khiển, chẳng hạn như bộ xử lý trung tâm (CPU), các thiết bị ngoại vi tích hợp (như ADC, PWM, UART), và các bộ định thời (timer).

 </details>
 
<details><summary>LESSON 16: OPP </summary>
  <p>

## LESSON 16: OOP
### Tính đóng gói
- Tính đóng gói (Encapsulation) là một trong bốn đặc tính cơ bản của lập trình hướng đối tượng (OOP) trong C++. Tính đóng gói đề cập đến việc gói gọn dữ liệu (thuộc tính) và các phương thức (hàm) liên quan trong một lớp, đồng thời che giấu chi tiết triển khai bên trong lớp đó khỏi bên ngoài. Ẩn đi các property “mật” khỏi người dùng. Và để làm được điều này, ta sẽ khai báo các property ở quyền truy cập private (tức là không thể truy cập trực tiếp tới các property này thông qua object). 
- Trong trường hợp ta muốn đọc hoặc ghi các property này, thì ta sẽ truy cập gián tiếp thông qua các method ở quyền truy cập public.
- Getter: Được sử dụng để lấy giá trị của một thuộc tính property.
- Setter: Được sử dụng để đặt, thay đổi giá trị và kiểm tra tính hợp lệ của property.
- Lợi ích của tính đóng gói
	- Bảo vệ dữ liệu: Ngăn chặn việc truy cập và sửa đổi trực tiếp dữ liệu từ bên ngoài lớp.
	- Kiểm soát truy cập: Cung cấp cơ chế để kiểm soát cách dữ liệu được sử dụng thông qua các phương thức getter và setter.
	- Tăng tính bảo trì: Dễ dàng thay đổi hoặc nâng cấp mã nguồn bên trong lớp mà không ảnh hưởng đến mã bên ngoài lớp.
	- Tăng tính tái sử dụng: Lớp được thiết kế rõ ràng, có thể tái sử dụng ở các phần khác của chương trình.
 - Cách thể hiện tính đóng gói trong C++
	- Tính đóng gói được thể hiện thông qua các mức truy cập:
		- private: Thành phần chỉ có thể được truy cập từ bên trong lớp.
		- protected: Thành phần có thể truy cập từ lớp cơ sở và các lớp dẫn xuất (kế thừa).
		- public: Thành phần có thể truy cập từ bất kỳ đâu bên ngoài lớp.
  - ví dụ:
    
    ```c
   	#include <iostream>
	#include <string>
	using namespace std;
	class SinhVien{
	    private:
	        string name;
	        int id;
	   
	    public:
	        // Contructor
	        SinhVien(){
	            static int ID = 1;
	            id = ID;
	            ID++;
	        }
	
	        // Setter-thêm tên mới
	        void setName(string newName){   
	            // Kiểm tra kí tự đặc biệt
	            name = newName;
	        }
	
	        // Getter-lấy tên sv
	        string getName(){   
	            return name;
	        }
	
	        // Getter-lấy id sv
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
	
	    sv1.setName("Trung");
	    sv1.display();
	
	    sv2.setName("Tuan");
	    sv2.display();
	
	    return 0;
	}
 - ví dụ 2:
   	```c
	#include <iostream>
	using namespace std;
	
	class BankAccount {
	private:
	    // Thuộc tính private (chỉ truy cập được bên trong lớp)
	    string accountHolder;
	    double balance;
	
	public:
	    // Constructor để khởi tạo tài khoản
	    BankAccount(string name, double initialBalance) {
	        accountHolder = name;
	        if (initialBalance >= 0)
	            balance = initialBalance;
	        else
	            balance = 0;
	    }
	
	    // Getter để lấy thông tin số dư
	    double getBalance() const {
	        return balance;
	    }
	
	    // Setter để nạp tiền vào tài khoản
	    void deposit(double amount) {
	        if (amount > 0) {
	            balance += amount;
	            cout << "Deposit successful. New balance: " << balance << endl;
	        } else {
	            cout << "Invalid deposit amount!" << endl;
	        }
	    }
	
	    // Setter để rút tiền từ tài khoản
	    void withdraw(double amount) {
	        if (amount > 0 && amount <= balance) {
	            balance -= amount;
	            cout << "Withdrawal successful. New balance: " << balance << endl;
	        } else {
	            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
	        }
	    	}
	};
	int main() {
	    // Tạo tài khoản ngân hàng
	    BankAccount account("John Doe", 1000.0);
	
	    // Truy cập thông qua các phương thức public
	    cout << "Initial balance: " << account.getBalance() << endl;
	
	    account.deposit(500);   // Nạp tiền
	    account.withdraw(300);  // Rút tiền
	
	    return 0;
		}
### Tính kế thừa
- Tính kế thừa ( Inheritance) là khả năng sử dụng lại các property và method của một class trong một class khác. Ta chia chúng làm 2 loại là class cha và class con. Để kế thừa từ class khác, ta dùng ký tự ":".
- Có 3 kiểu kế thừa là public, private và protected. Những property và method được kế thừa từ class cha sẽ nằm ở quyền truy cập của class con tương ứng với kiểu kế thừa.
- Lợi ích của tính kế thừa
	- Tái sử dụng mã nguồn: Các thuộc tính và phương thức của lớp cha có thể được sử dụng lại bởi lớp con mà không cần viết lại.
	- Mở rộng tính năng: Lớp con có thể thêm hoặc ghi đè (override) các thuộc tính/phương thức từ lớp cha để cung cấp các chức năng mới.
	- Tăng tính tổ chức: Tạo mối quan hệ phân cấp rõ ràng giữa các lớp, giúp dễ dàng quản lý và phát triển mã.
 #### Đặc điểm của tính kế thừa
	- Các member public của class cha vẫn sẽ là public trong class con.
	- Các member protected của class cha vẫn sẽ là protected trong class con.
	- Các member private của class cha không thể truy cập trực tiếp từ class con nhưng có thể được truy cập gián tiếp qua các phương thức public hoặc protected của class cha
#### Cú pháp:
	```c
 
	class LớpCha {
	    // Các thuộc tính và phương thức của lớp cha
	};
	
	class LớpCon : public LớpCha {
	    // Lớp con thừa hưởng tất cả các thuộc tính và phương thức công khai hoặc được bảo vệ của lớp cha
	};
 - ví dụ:
	```c
	 #include <iostream>
	using namespace std;
	
	// Class cha
	class Animal {
	public:
	    void eat() {
	        cout << "Animal is eating" << endl;
	    }
	    // public method, truy cập private gián tiếp!
	    void accessPrivate() {
	        breathe();
	    }
	
	protected:
	    void sleep() {
	        cout << "Animal is sleeping" << endl;
	    }
	
	private:
	    void breathe() {
	        cout << "Animal is breathing" << endl;
	    }
	};
	
	// Class con
	class Dog : public Animal {
	public:
	    void accessProtected() {
	        // sleep() truy cập thoải mái ở trong class con.
	        sleep();  
	    }
	};
	
	int main() {
	    Dog myDog;
	    // eat() ở class cha là public ở class con là public, eat() truy cập ở đâu cũng được.
	    myDog.eat(); 
	    // sleep() ở class cha là protected ở class con là protected, sleep() truy cập qua phương thức public của class con.
	    myDog.accessProtected();
	    // breathe() ở class cha là private, chỉ truy cập gián tiếp qua các phương thức public hoặc protected của class cha.
	    myDog.accessPrivate();    
	}
 - ví dụ kế thừa protected và private:
	```c
	#include <iostream>
	#include <string>
	
	using namespace std;
	
	class DoiTuong{
	    protected:
	        string ten;
	        int id;
	
	    public:
	        DoiTuong(){  
	            static int ID = 1;
	            id = ID;
	            ID++;
	        }
	
	        void setName(string _ten){
	            // check chuỗi nhập vào
	            ten = _ten;
	        }
	
	        void display(){
	            cout << "ten: " << ten << endl;
	            cout << "id: " << id << endl;
	        }
	};
	
	class SinhVien : protected DoiTuong{
	    protected:
	        string chuyenNganh;
	
	    public:
	        void setChuyenNganh(string _nganh){
	            chuyenNganh = _nganh;
	        }
	
	        void setNameSV(string _ten){
	            ten = _ten;
	        }
	
	        void display(){ // override
	            cout << "ten: " << ten << endl;
	            cout << "id: " << id << endl;
	            cout << "chuyen nganh: " << chuyenNganh << endl;
	        }
	};
	
	int main(int argc, char const *argv[])
	{
	    SinhVien sv1;
	    sv1.setNameSV("Trung");
	    sv1.setChuyenNganh("TDH");
	    sv1.display();
	    return 0;
	}
### Ghi đè hàm
- Ghi đè hàm (Method Overriding) trong lập trình hướng đối tượng (OOP) là một cơ chế cho phép lớp dẫn xuất (lớp con) thay thế hoặc tái định nghĩa một phương thức được kế thừa từ lớp cơ sở (lớp cha). Khi ghi đè, lớp con sẽ cung cấp cách triển khai mới cho phương thức đó, trong khi vẫn giữ cùng tên, kiểu trả về, và tham số.
#### Đặc điểm của ghi đè hàm
- Cùng tên, kiểu trả về và tham số: Phương thức ghi đè trong lớp con phải có cùng chữ ký (signature) với phương thức trong lớp cha.
- Sử dụng từ khóa virtual: Phương thức trong lớp cha cần được khai báo là virtual để hỗ trợ ghi đè.
- Hỗ trợ tính đa hình: Khi sử dụng con trỏ hoặc tham chiếu đến lớp cha để gọi phương thức, việc thực thi phương thức sẽ dựa vào đối tượng thực tế (runtime).
- Từ khóa override (tùy chọn): Trong C++11 trở đi, từ khóa override được dùng để chỉ rõ rằng phương thức đang ghi đè một phương thức từ lớp cha.
#### Cú pháp
	```c
		class LớpCha {
		public:
		    virtual void phươngThức() {
		        // Triển khai của lớp cha
		    }
		};
		
		class LớpCon : public LớpCha {
		public:
		    void phươngThức() override {
		        // Triển khai mới của lớp con
		    }
		};
	- ví dụ:
		```c
	 	#include <iostream>
	using namespace std;
	
	class Animal {
	public:
	    void sound() {
	        cout << "Some generic sound" << endl;
	    }
	};
	
	class Dog : public Animal {
	public:
	    // Function overriding
	    void sound() {
	        cout << "Woof!" << endl;
	    }
	};
	
	int main() {
	    Dog myDog;  
	    myDog.sound(); 
	    // Gọi method sound() của Dog, output: "Woof!"
	}
- ví dụ 2
	```c
	 #include <iostream>
	using namespace std;
	
	// Lớp cha
	class Animal {
	public:
	    virtual void makeSound() const {
	        cout << "Animal is making a sound." << endl;
	    }
	};
	
	// Lớp con kế thừa và ghi đè hàm
	class Dog : public Animal {
	public:
	    void makeSound() const override {
	        cout << "Dog is barking." << endl;
	    }
	};
	
	// Lớp con khác kế thừa và ghi đè hàm
	class Cat : public Animal {
	public:
	    void makeSound() const override {
	        cout << "Cat is meowing." << endl;
	    }
	};
	
	int main() {
	    Animal* animal1 = new Dog();  // Con trỏ kiểu lớp cha trỏ đến đối tượng lớp con
	    Animal* animal2 = new Cat();
	
	    animal1->makeSound();  // Gọi phương thức của lớp Dog
	    animal2->makeSound();  // Gọi phương thức của lớp Cat
	
	    delete animal1;
	    delete animal2;
	
	    return 0;
	}
### Tính đa hình
- Tính đa hình ( Polymorphism) có nghĩa là "nhiều dạng" và nó xảy ra khi chúng ta có nhiều class có liên quan với nhau thông qua tính kế thừa.
- Tính đa hình có thể được chia thành hai loại chính:
	- Đa hình tại thời điểm biên dịch (Compile-time Polymorphism): Thực hiện nhờ cơ chế nạp chồng (overloading).
		- Nạp chồng hàm (Function Overloading): Nhiều hàm có cùng tên nhưng khác tham số.
		- Nạp chồng toán tử (Operator Overloading): Thay đổi cách hoạt động của các toán tử.
	- Đa hình tại thời điểm chạy (Runtime Polymorphism): Thực hiện nhờ cơ chế ghi đè hàm (overriding) và sử dụng con trỏ hoặc tham chiếu.
		- Được hỗ trợ bởi từ khóa virtual trong C++.
- Đa hình tại thời điểm biên dịch
- Ví dụ nạp chồng hàm:
	```c
	#include <iostream>
	using namespace std;
	
	class Calculator {
	public:
	    int add(int a, int b) {
	        return a + b;
	    }
	
	    double add(double a, double b) {
	        return a + b;
	    }
	
	    int add(int a, int b, int c) {
	        return a + b + c;
	    }
	};
	
	int main() {
	    Calculator calc;
	    cout << "Sum of 2 integers: " << calc.add(5, 10) << endl;
	    cout << "Sum of 2 doubles: " << calc.add(3.5, 2.5) << endl;
	    cout << "Sum of 3 integers: " << calc.add(1, 2, 3) << endl;
	
	    return 0;
	}
- Ví dụ nạp chồng toán tử:
	```c
	#include <iostream>
	using namespace std;
	
	class Complex {
	private:
	    double real, imag;
	
	public:
	    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
	
	    // Nạp chồng toán tử "+"
	    Complex operator+(const Complex& other) {
	        return Complex(real + other.real, imag + other.imag);
	    }
	
	    void display() const {
	        cout << real << " + " << imag << "i" << endl;
	    }
	};
	
	int main() {
	    Complex c1(3.5, 2.5), c2(1.5, 4.5);
	    Complex c3 = c1 + c2; // Sử dụng toán tử "+" đã được nạp chồng
	    c3.display();
	    return 0;
	}
- Đa hình tại thời điểm chạy
- Ví dụ ghi đè hàm và đa hình động:
  	```c
	#include <iostream>
	using namespace std;
	
	// Lớp cha
	class Shape {
	public:
	    virtual void draw() const {
	        cout << "Drawing a generic shape." << endl;
	    }
	};
	
	// Lớp con 1
	class Circle : public Shape {
	public:
	    void draw() const override {
	        cout << "Drawing a circle." << endl;
	    }
	};
	
	// Lớp con 2
	class Rectangle : public Shape {
	public:
	    void draw() const override {
	        cout << "Drawing a rectangle." << endl;
	    }
	};
	
	int main() {
	    Shape* shape1 = new Circle();     // Con trỏ kiểu lớp cha trỏ đến lớp con
	    Shape* shape2 = new Rectangle();
	
	    shape1->draw(); // Gọi phương thức của lớp Circle
	    shape2->draw(); // Gọi phương thức của lớp Rectangle
	
	    delete shape1;
	    delete shape2;
	
	    return 0;
	}
	- Giải thích ví dụ:
		- Từ khóa virtual: Cho phép phương thức draw của lớp con được ghi đè.
		- Đa hình động: Việc gọi phương thức draw phụ thuộc vào đối tượng thực tế (Circle hoặc Rectangle) được con trỏ trỏ tới.
### Tính trừu tượng
- Tính trừu tượng đề cập đến việc ẩn đi các chi tiết cụ thể của một đối tượng và chỉ hiển thị những gì cần thiết để sử dụng đối tượng đó.
- Nó có sự tương đồng với tính đóng gói nhưng tính đóng gói là ẩn đi các property còn tính trừu tượng là ẩn đi các method hay quá trình tính toán.
  	```c
	#include <iostream>
	#include <string>
	#include <cmath>
	
	using namespace std;
	
	class GiaiPhuongTrinh{
	    private:
	        // Tính đóng gói-ẩn các property	
	        double a;
	        double b;
	        double c;
	        double x1;
	        double x2;
	        double delta;
	
	        // Tính trừu tượng-ẩn các method
	        void tinhNghiem(){	
	            delta = b*b - 4*a*c;
	            if (delta < 0){
	                delta = -1;
	            }
	            else if (delta == 0){
	                x1 = x2 = -b/ (2*a);
	            }
	            else if (delta > 0){
	                x1 = (-b + sqrt(delta))/(2*a);
	                x2 = (-b - sqrt(delta))/(2*a);
	            }
	        }
	       
	    public:
	        // Chỉ show ra phần sử dụng đơn giản cho user
	        void enterNumber(double num_a, double num_b, double num_c);
	        void printResult();
	
	};
	
	void GiaiPhuongTrinh::enterNumber(double num_a, double num_b, double num_c){
	    a = num_a;
	    b = num_b;
	    c = num_c;
	}
	
	void GiaiPhuongTrinh::printResult(){
	    tinhNghiem();
	    if (delta == -1){
	        cout << "PT vo nghiem" << endl;
	    }
	    else if (delta == 0){
	        cout << "PT co nghiem chung: " << x1 << endl;
	    }
	    else if (delta > 0){
	        cout << "PT co 2 nghiem: \n";
	        cout << "x1: " << x1 << endl;
	        cout << "x2: " << x2 << endl;
	    }
	}
	int main()
	{
	  GiaiPhuongTrinh phuongtrinh1;
	  phuongtrinh1.enterNumber(1,5,4);
	  phuongtrinh1.printResult();
	  return 0;
	}
 </details>
 
 <details><summary>LESSON 17: VIRTUAL FUNCTION </summary>
  <p>
  
 ## LESSON 17: Virtual Function
 ###  Khái niệm
- Hàm ảo là một hàm thành viên được khai báo trong class cơ sở( là class được các class con khác kế thừa chung) với từ khóa virtual.
	```cpp
	class Base{
	    public:
	        virtual void display(){
	            cout << "Display from Base class" << endl;
+ Khi một hàm là virtual, nó có thể được ghi đè (override) trong class con để cung cấp cách triển khai riêng.
+ Nếu lớp con không ghi đè (không cung cấp cách triển khai cụ thể) thì nội dung trong hàm ảo (method) sẽ được định nghĩa là nội dung mặc định trong cơ sở (class gốc)
+ Khi gọi một hàm ảo thông qua một con trỏ hoặc tham chiếu đến lớp con, hàm sẽ được quyết định dựa trên đối tượng thực tế (object) mà con trỏ hoặc tham chiếu đang trỏ tới chứ không dựa vào kiểu dữ liệu mà con trỏ được định nghĩa.
### Override và tính đa hình Run - time
- runtime : thay đổi đột ngột, đưa ra quyết định trong quá trình chạy
- Override là việc ghi đè hàm ảo ở class con bằng cách định nghĩa lại nó. Nó cho phép các lớp con kế thừa ghi đè (override), gom 2 phiên bản method lại thành 1 và chọn phiên bản mới nhất (tính đa hình) -> khi biên dịch sẽ chỉ ra đc 1 method chung (ghi đè lên nhau)

-  Khi một hàm ảo được ghi đè, hành vi của nó sẽ phụ thuộc vào kiểu của đối tượng thực tế, chứ không phải kiểu của con trỏ hay tham chiếu.
- Tính đa hình Run-time xảy ra khi quyết định gọi hàm nào (phiên bản của class cha hay class con) được đưa ra tại thời điểm chạy, không phải lúc biên dịch, giúp mở rộng chức năng. Điều này giúp chương trình linh hoạt hơn, cho phép việc mở rộng chức năng mà không cần sửa đổi mã nguồn hiện tại.

   
    + còn overload vẫn giữ 2 phiên bản (tại thời điểm compiler, của tính kế thừa) -> ẩn 1 method để compiler
- đa hình run time: 
    + là khả năng chọn phương thức (method)(đa hình) nào đc gọi ra tại thời điểm chạy (runtime) dựa trên loại thực sự của object, không phải kiểu của con trỏ đang trỏ tới
    + mỗi thời điểm cho trỏ tới 1 object khác nhau, căn cứ vào object thuộc class sẽ cho ra mối method khác nhau(phụ thuộc class), chạy trong quá trình runtime
    --> có lệnh chuyển object, chuyển đc method theo object --> đa hình trong thời điểm chạy
- hàm thuần ảo(Pure virtual Function) không có giá trị, những class con kế thừa phải bắt buộc có nội dung ghi đè override lên hàm thuần ảo, k sẽ bị lỗi chương trình
- không thể tạo ra đối tượng từ class có chứ hàm thuần ảo( nhưng có thể tạo con trỏ đc)
- đa kế thừa: kế thừa từ nhiều class khác nhau, use chức năng của những class đó
  </details>
 <details><summary>LESSON 19: NAMESPACE </summary>
  <p>
  
 ## LESSON 19: NAMESPACE
### Định nghĩa Namespace
- Namespace là cách nhóm các định danh như tên biến, hàm, class,... vào một không gian tách biệt.
- Namespace được sử dụng để tránh xung đột tên khi có các định danh giống nhau được khai báo trong các phần của chương trình hoặc các thư viện khác nhau.
- Ví dụ cho việc sử dụng namespace tránh xung đột:
	```c
	#include <iostream>
	using namespace std;
	
	// Khai báo namespace đầu tiên
	namespace Math {
	    int add(int a, int b) {
	        return a + b;
	    }
	}
	
	// Khai báo namespace thứ hai
	namespace Physics {
	    int add(int a, int b) {
	        return a + b + 10; // Một phép cộng khác, thêm 10 vào kết quả
	    }
	}
	
	int main() {
	    // Gọi hàm add trong namespace Math
	    int sumMath = Math::add(3, 4); // Kết quả: 7
	
	    // Gọi hàm add trong namespace Physics
	    int sumPhysics = Physics::add(3, 4); // Kết quả: 17
	
	    cout << "Tong theo Math::add(3, 4) = " << sumMath << endl;        // In ra 7
	    cout << "Tong theo Physics::add(3, 4) = " << sumPhysics << endl;  // In ra 17
	
	    return 0;
	}
 - ví dụ 2:
	```c
 	#include <iostream>
	using namespace std;
	namespace A{
	    char *name = (char*)"Trung 20";
	
	    void display(){
	        cout << "Name: " << name << endl;
	    }
	}
	namespace B{
	    char *name = (char*)"Trung 21";
	
	    void display(){
	        cout << "Name: " << name << endl;
	    }
	}
	int main(int argc, char const *argv[])
	{
	    cout << "Name: " << A::name << endl;
	    cout << "Name: " << B::name << endl;
	
	    A::display();
	    B::display();
	    return 0;
	}



### Namespace ẩn danh
- Namespace ẩn danh là một namespace không có tên cụ thể.
- Sử dụng để giới hạn phạm vi của các hàm, biến, hoặc lớp trong một file cụ thể (tức là các file khác không thể sử dụng được dù có từ khóa extern).
- Nó tương đương vơi việc sử dụng từ khóa static khai báo toán cục.
- Giúp tránh xung đột tên khi làm việc với các chương trình lớn hoặc nhiều file.
- Ví dụ về namespace ẩn danh:
	```c
	namespace {
	    int hiddenVariable = 42;
	
	    void hiddenFunction() {
	        cout << "Hello from an anonymous namespace!" << endl;
	    }
	}
### Từ khóa using
- Từ khóa using cho phép bạn sử dụng các phần tử trong namespace mà không cần phải sử dụng toán tử '::' mỗi khi truy cập.
	```c
	#include <iostream>
	using namespace std;
	using namespace Math;  
	
	// Khai báo namespace Math
	namespace Math {
	    int add(int a, int b) {
	        return a + b;
	    }
	}
	
	int main() {
	    // Gọi hàm add trực tiếp mà không cần Math::
	    int sumMath = add(3, 4); // Kết quả: 7
	
	    cout << "Tong theo add(3, 4) = " << sumMath << endl; // In ra 7
	
	    return 0;
	}
- Lưu ý: Chỉ sử dụng using namespace khi member muốn truy cập đến là duy nhất(chỉ 1 namespace).
- Ví dụ về lỗi khí cố sử dụng using namespace cho hai namespace định nghĩa cùng tên thành viên:
	```c
	#include <iostream>
	using namespace std;
	using namespace Math;
	using namespace Physics;
	
	// Cả hai namespace đều có hàm add()
	namespace Math {
	    int add(int a, int b) {
	        return a + b;
	    }
	}
	
	namespace Physics {
	    int add(int a, int b) {
	        return a + b + 10;
	    }
	}
	
	int main() {
	    // Lỗi: add không rõ ràng vì có hai hàm add từ các namespace khác nhau
	    int result = add(3, 4);
	    cout << "Kết quả: " << result << endl;
	    return 0;
	}
### Namespace lồng nhau
- Là một namespace có thể chứa một namespace khác bên trong nó.
- Ví dụ về namespace lồng nhau:
	```c
	#include <iostream>
	using namespace std;
	
	// Khai báo namespace bên ngoài
	namespace Outer {
	    void displayOut() {
	        cout << "Hello from Outer namespace" << endl;
	    }
	
	    // Khai báo namespace bên trong
	    namespace Inner {
	        void displayIn() {
	            cout << "Hello from Inner namespace" << endl;
	        }
	    }
	}
	
	int main() {
	    // Đưa các thành phần của Outer vào phạm vi hiện tại
	    using namespace Outer;
	
	    // Gọi hàm displayOut từ namespace Outer
	    displayOut(); // Tương đương với Outer::displayOut()
	    Inner::displayIn();
	
	    // Đưa các thành phần của Inner vào phạm vi hiện tại
	    using namespace Outer::Inner;
	
	    // Gọi hàm displayIn từ namespace Inner
	    displayIn(); // Tương đương với Outer::Inner::displayIn()
	
	    return 0;
	}
### Namespace mở rộng
- Namespace mở rộng là tính năng có thể được mở rộng namespace bằng cách khai báo nhiều lần cùng một tên namespace trong các phần khác nhau của chương trình kể cả ở file khác.
- Các khai báo này sẽ được ghép lại thành một namespace duy nhất cho nên không được định nghĩa trùng trên các thành viên trong namespace.
- Ví dụ về namespace mở rộng:
- Ở file mở rộng
	```c
	// morong.cpp
	#include <iostream>
	using namespace std;
	
	// Mở rộng namespace Math để định nghĩa hàm khác
	namespace Math {
	    void sum(int a, int b) {
	        cout << "Sum: " << a + b << endl;
	    }
	}
- Ở file main
	```c
	// file main.c
	#include <iostream>
	#include "morong.cpp"
	using namespace std;
	
	// Khai báo và định nghĩa hàm trong namespace Math
	namespace Math {
	    void subtract(int a, int b) {
	        cout << "Subtract: " << a - b << endl;
	    }
	}

- Tiếp tục mở rộng namespace Math để định nghĩa hàm khác
	```c
	namespace Math {
	    void multiply(int a, int b) {
	        cout << "Multiply: " << a * b << endl;
	    }
	}
 
	int main() {
	    // Gọi các hàm trong namespace Math
	    Math::sum(3, 4);        
	    Math::multiply(3, 4);   
	    Math::subtract(5, 3);
	    return 0;
	}
 ### Namespace tiêu chuẩn (std) trong C++
- namespace std cung câp tất cả các thành phần của thư viện chuẩn C++ (như cout, cin, vector, string).
- Ví dụ sử dụng cout:
	```c
	#include <iostream>
	using std::cout;
	using std::endl;
	
	int main() {
	    cout << "Hello, World!" << endl;
	    return 0;
	}
 - ví dụ khác:
   	```c
	#include <iostream>
	
	using namespace std;
	
	namespace std{
	    struct{
	        int x;
	        int y;
	    } point;
	
	    void display(){
	        cout << "x = " << point.x << endl;
	        cout << "y = " << point.y << endl;
	    }
	}
	
	int main(int argc, char const *argv[])
	{
	    std::cout << "Hello world!" << std::endl;
	
	    cout << "Hello world!" << endl;
	   
	    std::point.x = 10;
	    std::point.y = 20;
	    std::display();
	
	    return 0;
	}
</details>

<details><summary>LESSON 20: STANDARD TEMPLATE LIBRARY </summary>
  <p>
  
 ## LESSON 20: STANDARD TEMPLATE LIBRARY
 - Standard Template Library ( STL) là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến. STL đã trở thành một phần quan trọng của ngôn ngữ C++ và làm cho việc lập trình trở nên mạnh mẽ, linh hoạt và hiệu quả.
- Một số thành phần chính của STL:
	- Container
	- Iterator
	- Algorithms
	- Functor
### Container
- Container là cách gọi chung cho các cấu trúc dữ liệu tổng quát dùng để lưu trữ và quản lý các đối tượng (hoặc dữ liệu) theo một cách thức nhất định.
- Các container được học:Vector,List, Map, Array
#### Vector
- Vector là một lớp trong thư viện chuẩn STL (Standard Template Library), được sử dụng để lưu trữ và quản lý một mảng động. Khác với mảng tĩnh, kích thước của vector có thể thay đổi linh hoạt trong quá trình thực thi chương trình.
- Một số đặc điểm chính của vector:
	- vector là một mảng động, tức là có khả năng thay đổi kích thước một cách linh hoạt.
	- Truy cập ngẫu nhiên: Việc truy cập các phần tử của vector có thể được thực hiện bằng cách sử dụng chỉ số (index)
	- Hiệu suất chèn và xóa: Chèn và xóa phần tử ở cuối vector có hiệu suất tốt. Tuy nhiên, chèn và xóa ở vị trí bất kỳ có thể đòi hỏi di chuyển một số phần tử.
	- Tích hợp nhiều hàm hữu ích: Bao gồm các hàm như thêm, xóa, duyệt, sắp xếp...
- Ví dụ về khai báo và khởi tạo một vector: Lưu ý: Đối tượng vec1 (biến vector) khai báo trong main được lưu trên stack, các phần tử thì cấp phát ở heap!
	```c
	#include <iostream>
	#include <vector>
	using namespace std;
	
	int main() {
	    // Khai báo một vector lưu trữ số nguyên
	    vector<int> vec1;           // Vector rỗng
	    vector<int> vec2(5);        // Vector chứa 5 phần tử, mỗi phần tử mặc định là 0
	    vector<int> vec3(5, 10);    // Vector chứa 5 phần tử, mỗi phần tử có giá trị là 10
	    vector<int> vec4 = {1, 2, 3, 4, 5}; // Khởi tạo với danh sách giá trị
	
	    return 0;
	}
- Một số method của vector
  	- at(): Truy cập vào phần tử của vector
	- size(): Trả về kích thước của vector
	- resize(): Thay đổi kích thước của vector
	- begin(): Địa chỉ của phần tử đầu tiên của vector
	- end(): Địa chỉ của phần tử cuối cùng của vector
	- push_back(): Thêm phần tử vào vị trí cuối của vector
- ví dụ sử dụng method:
	```c
	 #include <iostream>
	#include <vector>
	
	using namespace std;
	int main()
	{
	  
	    vector <int> arr1 = {2,5,7,4,9};
	
	    arr1.at(0) = 3;
	    arr1.resize(7);
	
	    for (int i = 0; i < arr1.size(); i++)
	    {
	        cout << "Value: " << arr1.at(i) << endl;
	    }
	    
	    arr1.push_back(10);
	
	    cout << "-----------" << endl;
	    for (int i = 0; i < arr1.size(); i++)
	    {
	        cout << "Value: " << arr1.at(i) << endl;
	    }
	    
	
	    return 0;
	}
#### List
- Trong C++, list là một container trong thư viện chuẩn STL (Standard Template Library) được sử dụng để lưu trữ các phần tử dưới dạng danh sách liên kết đôi (doubly linked list).
- Container này cho phép chèn, xóa, và duyệt các phần tử một cách hiệu quả tại bất kỳ vị trí nào, nhưng không hỗ trợ truy cập ngẫu nhiên như vector.
- Dưới đây là một số đặc điểm quan trọng của list:
	-Danh sách liên kết đôi: Mỗi phần tử của list chứa một con trỏ đến phần tử liền trước và liền sau nó.
	- Kích thước động: Có thể thêm hoặc xóa phần tử mà không cần quan tâm đến kích thước ban đầu.
	- Hiệu quả trong việc chèn/xóa: Chèn hoặc xóa phần tử tại bất kỳ vị trí nào có độ phức tạp O(1), miễn là đã có con trỏ đến vị trí đó.
	- Không hỗ trợ truy cập ngẫu nhiên: Phải duyệt tuần tự từ đầu hoặc cuối để tìm phần tử.
- Một số method của list:
	- Thêm phần tử
		```c

		lst.push_back(10);  // Thêm 10 vào cuối list
		lst.push_front(5);  // Thêm 5 vào đầu list
		lst.insert(++lst.begin(), 15); // Thêm 15 vào vị trí thứ 2
	- Xóa phần tử
		```c
		lst.pop_back();          // Xóa phần tử cuối
		lst.pop_front();         // Xóa phần tử đầu
		lst.erase(++lst.begin()); // Xóa phần tử tại vị trí thứ 2
		lst.clear();             // Xóa toàn bộ phần tử
	- Truy cập phần tử Với std::list, không hỗ trợ truy cập ngẫu nhiên bằng chỉ số như vector. Bạn cần duyệt qua các phần tử bằng iterator hoặc vòng lặp.
	- Duyệt các phần tử
		```c
		for (int x : lst) {
		    std::cout << x << " ";
		}
		
		// Hoặc sử dụng iterator
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		    std::cout << *it << " ";
		}
	- Sắp xếp
  		```c
	
		lst.sort(); // Sắp xếp tăng dần
		lst.sort(std::greater<int>()); // Sắp xếp giảm dần
	- Thông tin về list
	
		```c
		int size = lst.size();     // Số lượng phần tử
		bool empty = lst.empty();  // Kiểm tra list có rỗng không
	- Loại bỏ phần tử
	
		```c
		lst.remove(5);         // Loại bỏ tất cả các phần tử có giá trị là 5
		lst.unique();          // Loại bỏ các phần tử trùng lặp liên tiếp
- ví dụ sử dụng method của list:
	```c
	 #include <iostream>
	#include <list>
	using namespace std;
	int main()
	{
	    list <int> arr1 = {2,5,7,4,9};
	
	
	    list <int> :: iterator it;
	
	    int i = 0;
	    for (it = arr1.begin(); it != arr1.end(); ++it)
	    {
	        if (i == 2)
	        {
	            arr1.insert(it,10);
	            break;
	        }
	        i++;
	    }
	
	    i = 0;
	    for (it = arr1.begin(); it != arr1.end(); ++it)
	    {
	        if (i == 4)
	        {
	            arr1.erase(it);
	            break;
	        }
	        i++;
	    }
- Sử dụng vector khi:
	- Cần truy cập ngẫu nhiên đến các phần tử.
	- Thực hiện nhiều thao tác chèn/xóa ở cuối danh sách.
	- Dung lượng có thể biết trước hoặc thay đổi ít.
- Sử dụng list khi:
	- Thực hiện nhiều thao tác chèn/xóa ở bất kỳ vị trí nào trong danh sách.
	- Cần thực hiện nhiều thao tác chèn/xóa mà không làm ảnh hưởng đến các iterators hiện có.
	- Dung lượng không quan trọng hoặc thay đổi thường xuyên.
#### Map
- Map là một container trong STL của C++, cung cấp một cấu trúc dữ liệu ánh xạ key-value
- Đặc điểm
	- Sắp xếp tự động: Các phần tử được lưu trữ theo thứ tự tăng dần của khóa (dựa trên toán tử < mặc định hoặc một comparator do người dùng định nghĩa).
	- Map lưu trữ các phần tử dưới dạng cặp key-value, trong đó mỗi key phải là duy nhất trong map.
	- Ta có thể thêm phần tử mới vào map bằng cách sử dụng operator [] hoặc hàm insert(). Để xóa phần tử, bạn có thể sử dụng hàm erase().
	- Ta có thể sử dụng iterator để duyệt qua các phần tử của map
 - các thao tác thường dùng với map:
	- Thêm phần tử
		```c
		m[1] = "one";                 // Thêm cặp (1, "one")
		m.insert({2, "two"});         // Thêm cặp (2, "two")
		m.emplace(3, "three");        // Thêm cặp (3, "three") (hiệu quả hơn)
	- Truy cập phần tử
		```c
		std::string value = m[1];     // Lấy giá trị tại khóa 1
		m[4] = "four";               // Thêm cặp (4, "four") nếu khóa 4 chưa tồn tại
	- Tìm kiếm phần tử
		```c
		if (m.find(2) != m.end()) {
		    std::cout << "Key 2 exists\n";
		} else {
		    std::cout << "Key 2 not found\n";
		}
	- Xóa phần tử
		```c
		m.erase(1);                  // Xóa phần tử có khóa 1
		m.clear();                   // Xóa toàn bộ phần tử trong map
	- Duyệt qua các phần tử
		```c
		for (const auto& pair : m) {
		    std::cout << pair.first << ": " << pair.second << "\n";
		}
		
		// Hoặc sử dụng iterator
		for (std::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it) {
		    std::cout << it->first << ": " << it->second << "\n";
		}
	- Kiểm tra kích thước và trạng thái
		```c
		int size = m.size();         // Số lượng phần tử trong map
		bool empty = m.empty();      // Kiểm tra map có rỗng không
- ví dụ:
  	```c
	#include <map>
	#include <iostream>
	#include <string>
	
	using namespace std;
	
	int main() {
	    map<string, int> myMap;
	
	    map<string,int> ::iterator it;
	
	    // Thêm phần tử vào map
	    myMap["one"] = 1;
	    myMap["two"] = 2;
	    myMap["three"] = 3;
	    myMap.insert(make_pair("four", 4));
	    myMap.erase("one");
	
	    for (auto const var : myMap)
	    {
	        cout << "Key: " << var.first << " , " << "Value: " << var.second << endl;
	    }
	    
	   
	    for (it = myMap.begin(); it != myMap.end(); ++it)
	    {
	        cout << "Key: " << (*it).first << " , " << "Value: " << (*it).second << endl;
	    }
	    
	    
	
	    return 0;
	}
#### Array
- Array là một container có kích thước cố định và có sẵn trong thư viện STL (Standard Template Library)
- array có kích thước cố định được xác định tại thời điểm biên dịch và không thể thay đổi sau khi được khai báo.
- array hỗ trợ truy cập ngẫu nhiên vào các phần tử thông qua toán tử []
- Các hàm thường dùng
	- size(): Trả về kích thước mảng.
	- at(index): Truy cập phần tử với kiểm tra chỉ số.
	- front() và back(): Truy cập phần tử đầu tiên và cuối cùng.
	- fill(value): Gán toàn bộ phần tử bằng giá trị value.
 - ví dụ:
	```c
 	#include <iostream>
	#include <array>
	
	using namespace std;
	
	
	int main()
	{
	  
	    array <int, 5> arr = {2,3,1,7,6};
	
	    if (arr.empty())
	    {
	        cout << "Array is empty" << endl;
	    }
	    else
	    {
	        cout << "Array it not empty" << endl;
	    }
	    
	
	    for (int i = 0; i < arr.size(); i++)
	    {
	        cout << "Value: " << arr.at(i) << endl;
	    }
	    
	
	    return 0;
	}
 
 ### Iterator
- Iterator cung cấp một cách chung để duyệt qua các phần tử của một container mà không cần biết chi tiết về cách container được triển khai.
- Iterator là một đối tượng cho phép truy cập tuần tự qua các phần tử của một container.
- Nó giống như con trỏ, cho phép di chuyển qua các phần tử trong container.
### Algorithm
- Thư viện STL (Standard Template Library) cung cấp một số thuật toán tiêu biểu thông qua algorithm. Các thuật toán này hoạt động trên các phạm vi hoặc các loại dữ liệu khác nhau, giúp thực hiện các nhiệm vụ như sắp xếp, tìm kiếm, chuyển đổi dữ liệu, và nhiều thao tác khác.
- ví dụ
  	```c
   	#include <iostream>
	#include <vector>
	#include <algorithm>
	
	using namespace std;
	
	
	int main()
	{
	
	    vector <int> arr = {3,5,7,4,1};
	
	    for (auto const var : arr)
	    {
	        cout << "Vector: " << var << endl;
	    }
	
	    sort(arr.begin(), arr.end());
	    
	    cout << "vector after sort ascending: " << endl;
	
	    for (auto const var : arr)
	    {
	        cout << "Vector: " << var << endl;
	    }
	
	    sort(arr.begin(), arr.end(), greater<int>());
	    
	    cout << "vector after sort descending: " << endl;
	
	    for (auto const var : arr)
	    {
	        cout << "Vector: " << var << endl;
	    }
	
	    return 0;
	}




</details>

<details><summary>LESSON 23: SMART POINTER - LAMBDA </summary>
  <p>

## LESSON 23: SMART POINTER - LAMBDA
### LAMBDA
- Các hàm được tạo sẽ có một vùng nhớ riêng và sẽ giữ lại trong suốt quá trình thực thi. Nhưng với các hàm chỉ hoạt động một lần duy nhất thì việc này làm tiêu tốn bộ nhớ. Vì thể ta sẽ có cú pháp khai báo riêng cho chúng.
- Lambda trong C++ là một cách để định nghĩa hàm vô danh (không cần khai báo tên hàm) ngay trong mã nguồn, thường dùng khi bạn chỉ cần hàm để sử dụng một lần hoặc trong một ngữ cảnh cụ thể mà không cần phải định nghĩa hàm ngoài.
- Lambda cho phép định nghĩa hàm ngắn gọn (anonymous function) mà không cần phải viết một hàm riêng biệt. Cú pháp của lambda rất linh hoạt và có thể được sử dụng để viết mã ngắn gọn và dễ đọc.
- Là 1 hàm không có tên
- Được định nghĩa trực tiếp trong 1 hàm nào đó
- không cần khai báo kiểu trả về, tự động suy diễn ra được kiểu trả về
- Cú pháp:
	```cpp
	[capture](parameters) -> <return_type>
	{
	    // code block
	};
	```cpp
	[capture](parameters)
	{
	    // code block
	};

	- capture:  Cho phép bắt giữ biến từ môi trường xung quanh vào lambda.
		+ [<name_variable>]: chỉ định cụ thể biến sẽ sử dụng, read-only
		+ [=]: cho phép sử dụng tất cả các biến xung quanh, read-only
		+ [&<name_variable>]: truyền tham chiếu của biến cụ thể
		+ [&]: truyền tham chiếu của tất cả biến xung quanh
		+ phối hợp cả 2 kiểu
	- parameters: tham số truyền vào của lambda
	- <return_type>: kiểu trả về (không cần thiết)
	- Function body: Đặt trong dấu ngoặc nhọn {} và chứa mã nguồn thực thi của lambda.
 - ví dụ 1:
	```cpp
	#include <iostream>
	using namespace std;
	
	int main(int argc, char const *argv[])
	{
	    int x = 1; // 0x01
	    int y = 2; // 0x05
	    int z = 3; // 0xf4
	
	    int a = 9;
	    int b = 2;
	
	    // Không sử dụng biến
	    auto sum = [](int a, int b)
	    {
	        return a + b;
	    };
	    cout << "Tổng 2 số: " << sum(a, b) << endl;
	
	    // Sử dụng hai biến x,y READ-ONLY
	    auto sub = [x, y](int a, int b)
	    {
	        return (a + b) - (x + y);
	    };
	    cout << "Hiệu a+b - (x+y): " << sub(a, b) << endl;
	
	    // Sử dụng tất cả các biến READ-ONLY
	    auto sumAll = [=](int a, int b)
	    {
	        return a + b + x + y + z;
	    };
	    cout << "Tổng tất cả: " << sum(a, b) << endl;
	
	    // Sử dụng biến y và z, READ-WRITE
	    auto sumChange = [&y, &z](int a, int b)
	    {
	        y = 15; // read - write
	        z = 9;  // read - write
	        return a + b + y + z;
	    };
	    cout << "Tổng sau khi thay đổi a+b+y+z: " << sumChange(a, b) << endl;
	
	    // Tham chiếu được tất cả các biến xung quanh
	    auto sumAll1 = [&](int a, int b)
	    {
	        x = 5;  // read - write
	        y = 10; // read - write
	        z = 1;  // read - write
	        return a + b + x + y + z;
	    };
	    cout << "Tổng tất cả: " << sumAll1(a, b) << endl;
	
	    // Kết hợp.
	    auto sumCombine = [x, &y, &z](int a, int b)
	    {
	        // x = 5;   // read - write
	        y = 10; // read - write
	        z = 1;  // read - write
	        return a + b + x + y + z;
	    };
	    cout << "Tổng kết hợp: " << sumCombine(1, 2) << endl;
	
	    // Lambda không có tham sôs
	
	    auto display = []()
	    {
	        cout << "Hello, world\n";
	    };
	
	    display();
	
	    // Sử dụng trực tiếp lambda
	    //Có tham số
	    cout << [](int a, int b)
	    {
	        return a + b;
	    }(2, 3)
	         << endl;
	    // Không tham số
	    []()
	    {
	        cout << "Hello, world\n";
	    }();
	
	    return 0;
	}
- Kết quả:
	```cpp
	Tổng 2 số: 11
	Hiệu a+b - (x+y): 8
	Tổng tất cả: 11
	Tổng tất cả: 27
	Tổng kết hợp: 19
	Hello, world
	5
	Hello, world
- Ví dụ 2:
	```cpp
	#include <iostream>
	#include <vector>
	#include <algorithm>
	
	using namespace std;
	
	int main(int argc, char const *argv[])
	{
	    vector<int> vec = {2,15,4,6,5,3,8,1,9};
	
	    // sort(vec.begin(), vec.end(), greater<int>());
	
	    cout << "Vector ban đầu: ";
	
	    for (auto item : vec)
	    {
	        cout << item << " ";
	    }
	    cout << endl;
	
	    // sắp xếp tăng dần
	    sort(vec.begin(), vec.end(), [](int i, int j) -> bool
	    {
	        return i < j;
	    });
	
	    cout << "Vector sau khi sắp xếp: ";
	
	    for (auto item : vec)
	    {
	        cout << item << " ";
	    }
	    cout << endl;
	
	    cout << "Vector sau khi sắp xếp: ";
	
	    // sắp xếp giảm dần
	    sort(vec.begin(), vec.end(), [](int i, int j) -> bool
	    {
	        return i > j;
	    });
	
	    for (auto item : vec)
	    {
	        cout << item << " ";
	    }
	    cout << endl;
	
	
	    int count_even = 0;
	    int count_odd  = 0;
	
	    vector<int> evens, odds;
	
	
	    //vec.begin() và vec.end() xác định phạm vi của vector vec.
	    //count_if sẽ duyệt từng phần tử trong phạm vi này, truyền từng phần tử đó vào lambda [&](int x).
	    //x trong lambda là một tham số của hàm pred, được truyền vào từ count_if.
	    
	    count_if(vec.begin(), vec.end(), [&](int x)
	    {
	        if (x % 2 == 0)
	        {
	            count_even++;
	            evens.push_back(x);
	        } else {
	            count_odd++;
	            odds.push_back(x);
	        }
	
	        return false;
	    });
	
	
	    std::cout << "Số lượng số chẵn: " << count_even << endl;
	
	    for (auto i : evens)
	    {
	        cout << i << " ";
	    }
	
	    cout << endl;
	
	    cout << "Số lượng số lẻ: " << count_odd << endl;
	
	    for (auto i : odds)
	    {
	        cout << i << " ";
	    }
	
	    return 0;
	}
- Ví dụ trên sẽ ứng dụng trục tiếp Lambda vào việc sắp xếp thứ tự của một vector
	```cpp
	sort(vec.begin(), vec.end(), [](int i, int j) -> bool
	    {
	        return i < j;
	    });
- Hàm này có ba tham số truyền vào sort(first, last, compare);
	- First, last là con trỏ hoặc iterator trỏ đến phần tử đầu hoặc cuối trong phạm vi cần sắp xếp.
	- compare: Hàm so sánh, true không hoán đối vị trí, false hoán đổi vị trí.
	- Hàm Lambda trả về true nếu i nhỏ hơn j, tức là giữ thứ tự hiện tại của i và j. Nếu i > j, sort sẽ hoán đổi vị trí của chúng.
	- Tương tự với hàm sắp xếp giảm dần.

- Hàm tính số chẵn lẻ:
	```cpp
	count_if(vec.begin(), vec.end(), [&](int x)
	    {
	        if (x % 2 == 0)
	        {
	            count_even++;
	            evens.push_back(x);
	        } else {
	            count_odd++;
	            odds.push_back(x);
	        }
	
	        return false;
	    });
- vec.begin() và vec.end() xác định phạm vi của vector vec.
- count_if sẽ duyệt từng phần tử trong phạm vi này, truyền từng phần tử đó vào lambda [&](int x).
- x trong lambda là một tham số của hàm pred, được truyền vào từ count_if.
- Nếu x chia hết cho hai thì là số chẵn.
- Kết quả:
	```cpp
	Vector ban đầu: 2 15 4 6 5 3 8 1 9 
	Vector sau khi sắp xếp: 1 2 3 4 5 6 8 9 15
	Vector sau khi sắp xếp: 15 9 8 6 5 4 3 2 1
	Số lượng số chẵn: 4
	8 6 4 2
	Số lượng số lẻ: 5
	15 9 5 3 1
 
### SMART POINTER
#### Cấp phát động trong C++
- new và delete là hai toán tử quan trọng trong C++ được sử dụng để cấp phát và giải phóng bộ nhớ động, tương ứng. Các toán tử này thường được sử dụng khi làm việc với đối tượng được cấp phát động, như là đối tượng được tạo trong vùng nhớ heap.
	```cpp
 	int *ptr = new int; // cấp phát bộ nhớ cho một biến kiểu int
	int *arr = new int[5]; // cấp phát bộ nhớ cho một mảng kiểu int với 5 phần tử
	
	delete ptr; // giải phóng bộ nhớ của biến động
	delete[] arr; // giải phóng bộ nhớ của mảng động
#### Định nghĩa Smart pointer
- Trong C++, smart pointers là một cơ chế quản lý bộ nhớ tự động giúp giảm thiểu rủi ro của lỗi liên quan đến quản lý bộ nhớ và giúp người lập trình tránh được việc quên giải phóng bộ nhớ đã được cấp phát.
- là 1 class có 1 con trỏ và các thao tác làm việc với con trỏ
- gồm có unique pointer, shared pointer, weak pointer
#### Unique pointer
- unique_ptr là một loại smart pointer trong C++, giúp quản lý bộ nhớ động và tự động giải phóng bộ nhớ khi không còn cần thiết. 
- Đặc điểm chính của unique_ptr là một unique_ptr chỉ có thể sở hữu một đối tượng hoặc mảng và khi một unique_ptr bị hủy, bộ nhớ của đối tượng sẽ được tự động giải phóng.(chỉ chặn unique_ptr khác, không chặn đc như 1 con trỏ biến thông thường *ptr)
- cần gắn nullptr khi chưa khởi tạo đối tượng
- Thường để trong class private để k thể truy cập đc unique_ptr
- thư viện Unique pointer
  #include <iostream>
	```cpp
	using namespace std;
	
	/**
	 * @brief   Lớp UniquePointer quản lý một con trỏ duy nhất và tự động giải phóng vùng nhớ.
	 * @tparam  T   Kiểu dữ liệu của đối tượng được quản lý.
	 */
	template <typename T>
	class UniquePointer
	{
	    private:
	        T *ptr; /**< Con trỏ thô đến đối tượng được quản lý. */
	        
	
	    public:
	        /**
	         * @brief   Constructor khởi tạo con trỏ UniquePointer.
	         * @param   p   Con trỏ thô đến đối tượng. Giá trị mặc định là nullptr.
	         */
	        UniquePointer(T *p = nullptr) : ptr(p){}
	
	
	        /**
	         * @brief   Destructor giải phóng vùng nhớ của đối tượng được quản lý nếu không null.
	         */
	        ~UniquePointer()
	        {
	            if (ptr) delete ptr; // (ptr) = nếu như đối tượng tồn tại or ptr đang quản lí đối tượng nào đó -> delete địa chỉ ptr đang lưu
	        }
- Khi một Unique Pointer được khởi tạo, sẽ gán đối tượng cho nó hoặc gán mặc định giá trị NULL bằng Constructor (khi chưa tạo đối tượng)
- Và khi thu hồi sẽ thu hồi đối tượng được trỏ tới trước sau đó thu hồi con trỏ
- khởi tạo 1 unique pointer:
  	```cpp
   	UniquePointer <int> uptr1 = new int(10); // uptr1 quản lí 1 đối tượng kiểu int có giá trị là 10
   - cuối hàm main() sẽ thu hồi int(10) sau đó thu hồi uptr1
  	```cpp
	   /**
	         * @brief   Copy Constructor - Xóa bỏ khả năng sao chép đối tượng UniquePointer.
	         */
	        UniquePointer(const UniquePointer &other) = delete;
	
	        /**
	         * @brief   Copy Assignment Operator - Xóa bỏ khả năng gán bằng copy đối tượng UniquePointer.
	         * @return  Trả về tham chiếu đến đối tượng UniquePointer hiện tại.
	         */
	        UniquePointer& operator = (const UniquePointer &other) = delete;
- Khi một con trỏ uptr2 được khởi tạo để copy uptr1 UniquePointer<int> uptr2(uptr1) or  UniquePointer<int> uptr2 = uptr1; thì Constructor của uptr2 sẽ thực thi để sao chép giá trị của uptr1 việc này vi phạm quy định chỉ duy nhất một con trỏ quản lý vùng nhớ. Vì thế sẽ bị lỗi được gọi là Copy constructor.
- Tương tự với phép gán hai con trỏ
	```cpp
	UniquePointer<int> uptr2;
	    uptr2 = uptr1;
- Toán tử = k có sẳn mà sẽ được định nghĩa lại trong Class Unique Pointer để gán giá trị của hai con trỏ này. Nhưng việc này lại tiếp tục vi phạm quy định trên nhưng tại phép gán. Vì thế được gọi là Copy Assignment Operator
	```cpp
	  /**
	         * @brief   Toán tử dereference để truy cập đối tượng được quản lý.
	         * @return  Tham chiếu đến đối tượng được quản lý.
	         */
	        T& operator * () const
	        {
	            return *ptr; // trả về giá trị mà ptr đang quản lí
	        }
	
	
	        /**
	         * @brief   Toán tử để truy cập các thành phần của đối tượng.
	         * @return  Con trỏ đến đối tượng được quản lý.
	         */
	        T* operator -> () const
	        {
	            return ptr;
	        }
 - tham chiếu là truy cập vào giá trị đang đc quản lí bởi con trỏ unique, VD: *ptr = *0x01 = 10
 - toán tử truy cập đến các thành phần của đối tượng, return ptr : trả về địa chỉ ptr, chứ không trả về địa chỉ mà nó quản lí -> cho phép truy cập được những thành phần khác nhau trong đối tượng có trong Class hoặc Struct được trỏ tới.
   	```cpp
	    class Test 
	{
	    public:
	        int value;
	
	        Test(int val = 10) : value(val){}
	
	        void setValue(int newValue)
	        {
	            value = newValue;
	        }
	
	        int getValue() const
	        {
	            return value;
	        }
	
	        void display() const 
	        {
	            cout << "Test value: " << getValue() << endl;
	        }
	};
	
	int main(){
	    UniquePointer<int> uptr1 = new int(10);
	    cout << "new value of int: " << *uptr1 << endl;
	    
	    UniquePointer<Test> uptr = new Test(10);
	    uptr->display();
	    uptr->setValue(50);
	    uptr->display();
	
	    (*uptr).setValue(100);// dùng giải tham chiếu để truy cập 
	    (*uptr).display();
	}
- các method tương tác với unique pointer
 	```cpp
	  T* get() const
	        {
	            return ptr; // trả về địa chỉ có sẳn của con trỏ thô, k phải của đối tượng
	        }
	        
	        /**
	         * @brief   Chuyển quyền sở hữu đối tượng cho con trỏ thô bên ngoài.
	         * @return  Con trỏ thô đến đối tượng trước khi release.
	         */
	        T* release() // release ptr để cho con trỏ # quản lí đối tượng đã lưu trong temp
	        {
	            T* temp = ptr;  // lưu lại địa chỉ của đối tượng đang quản lý
	            ptr = nullptr;  // đặt con trỏ thô ptr thành con trỏ null
	            return temp;    // trả về địa chỉ của đối tượng
	        }
	
	        
	        /**
	         * @brief   Giải phóng đối tượng hiện tại và quản lý đối tượng mới.
	         * @param   p   Con trỏ thô đến đối tượng mới. Mặc định là nullptr.
	         */
	        void reset(T *newPtr = nullptr) // mặc định trước là nullptr 
	        {
	            if (this->ptr) delete ptr; // this truy cập đến ptr, kiểm tra ptr có phải null k, nếu k phải null( đang quản lí 1 project) thì thu hồi project đó
	
	            ptr = newPtr;
	        }
  	```cpp
	          /**
	         * @brief   Move constructor chuyển nhượng quyền sở hữu con trỏ.
	         * @param   other   Đối tượng 'UniquePointer' cần chuyển nhượng quyền sở hữu.
	         */
	        UniquePointer(UniquePointer &&other) : ptr(other.ptr)
	        {
	            other.ptr = nullptr; // đảm bảo 1 uniqueptr quản lí
	        }
	
	
	        /**
	         * @brief   move assignment operator - Toán tử gán chuyển nhượng quyền sở hữu.
	         * @param   other   Đối tượng 'UniquePointer' cần chuyển nhượng quyền sở hữu.
	         */
	        UniquePointer& operator = (UniquePointer &&other)
	        {
	            if (this != &other) // kiểm tra xem có giống địa chỉ nhau hay k
	            {
	                // giải phóng đối tượng hiện tại
	                if (this->ptr) delete ptr;
	
	                // chuyển quyền sở hữu
	                this->ptr = other.ptr;
	                other.ptr = nullptr;
	            }
	
	            return *this;
	        }
  - ví dụ unique ptr:
	 ```cpp
 
 	#include <iostream>
	#include <memory>   // Cần thiết để sử dụng smart pointer
	
	using namespace std;
	
	class SpeedSensor
	{
	    private:
	        int data;
	
	    public:
	        SpeedSensor(int value): data(value){
	            cout << "Constructor called, data = " << data << endl;
	        }
	
	        ~SpeedSensor(){
	            cout << "Destructor called\n";
	        }
	
	        void readData(){
	            cout << "Reading speed data...\n";
	        }
	
	        void setData(int value){
	            data = value;
	        }
	
	        void display(){
	            cout << "Data: " << data << endl;
	        }
	};
	
	int main() 
	{
	    unique_ptr<SpeedSensor> uptr = make_unique<SpeedSensor>(10);
	    // unique_ptr<SpeedSensor> uptr(new SpeedSensor(10));
	
	
	    uptr->display();
	    uptr->readData();
	    uptr->setData(20);
	    uptr->display();
	
	
	
	    (*uptr).display();
	    /***************************************************************
	     * sử dụng toán tử (*), ta sẽ lấy ra được đối tượng kiểu SpeedSensor,
	     * từ đó có thể sử dụng toán tử (.) để truy cấp các biến và hàm
	     * thành viên của đối tượng này
	     **************************************************************/    
	
	
	    /* sử dụng release() để tách quyền sở hữu và trả về con trỏ thô */
	    cout << "\nrelease()\n";
	    SpeedSensor *rawPtr = uptr.release();
	    if (!uptr){
	        cout << "ptr đã bị tách quyền sở hữu và trở thành nullptr\n";
	    }
	    rawPtr->display();  // truy cập đối tượng bằng con trỏ thô
	    delete rawPtr;      // phải giải phóng bộ nhớ thủ công khi dùng con trỏ thô
	
	    
	    /* sử dụng reset() để giải phóng đối tượng cũ và gán đối tượng mới */
	    cout << "\nreset()\n";
	    uptr.reset(new SpeedSensor(50)); // ptr quản lý đối tượng mới
	    uptr->display();                 // truy cập đối tượng mới
	
	
	    /* sử dụng get() để trả về con trỏ thô nhưng vẫn giữ nguyên quyền sở hữu */
	    cout << "\nget()\n";
	    uptr = make_unique<SpeedSensor>(30);
	    SpeedSensor *rawPtr2 = uptr.get();   // get() trả về con trỏ thô nhưng ptr vẫn sở hữu đối tượng
	    rawPtr2->display();
	    cout << "ptr vẫn sở hữu đối tượng\n";
	
	
	    /* sử dụng operator = với std::move() để chuyển quyền sở hữu */
	    cout << "\nmove()\n";
	    unique_ptr<SpeedSensor> newPtr = move(uptr); // chuyển quyền sở hữu từ ptr sang newPtr
	    if (!uptr){
	        cout << "ptr đã trở thành nullptr sau khi chuyển quyền sở hữu\n";
	    }
	    newPtr->display();  // newPtr giờ sở hữu đối tượng
	    return 0;
	}
#### Shared pointer
- shared_ptr là một smart pointer khác trong C++ và cũng giúp quản lý bộ nhớ động. Là nhiều pointer của quản lí cùng shared 1 dữ liệu bên trong 1 đối tượng. Điểm đặc biệt của shared_ptr là nó sử dụng một bộ đếm tham chiếu để theo dõi số lượng shared_ptr đang tham chiếu đến một đối tượng, và chỉ giải phóng bộ nhớ khi không còn shared_ptr nào tham chiếu đến nó.
- điều đặc biệt là có thêm độ đếm tham chiếu
- object sẽ bị thu hồi khi k còn pointer nào quản lí nó. thu hồi sptr3 -> sptr2 -> obj -> sptr1
	```cpp
	 	class SharedPointer
	{
	    private:
	        T *ptr;              /**< Con trỏ thô đến đối tượng được quản lý. */
	        size_t *ref_count;   /**< Bộ đếm tham chiếu. */
	
	
	        void release_in()
	        {
	            if (ref_count && --(*ref_count) == 0) // kiểm tra = null or ref_count có bằng 1(con trỏ quản lí)
	            {
	                delete ptr;
	                delete ref_count;
	            }
	  ~SharedPointer()
	{
	    release_in();
	}
	        }
- Bộ đếm này là một con trỏ vì nếu sử dụng biến thường thì mỗi khi khởi tạo một đối tượng sẽ cấp một vùng nhớ để lưu ref_count (tăng số lượng địa chỉ để lưu) gây tiêu hao bộ nhớ và đếm không chính xác. Vì thế sử dụng con trỏ để chỉ trỏ đến một vùng nhớ duy nhất và cộng dồn giá trị này với mỗi đối tượng được khởi tạo.
- hàm release chỉ loại bỏ bộ đếm, thu hồi đối tượng hiện tại, và để trong private vì sharep được gọi thông qua detructor
- hàm constructor:
  	```cpp
	/**
	* @brief Constructor khởi tạo SharedPointer.
	* @param p Con trỏ thô đến đối tượng. Giá trị mặc định là nullptr.
	*/
	SharedPointer(T *p = nullptr) : ptr(p), ref_count(p ? new size_t(1) : nullptr){}
- Giá trị mặc định của p là nullptr, tức là nếu không truyền tham số, SharedPointer sẽ không trỏ đến đối tượng nào.
- Nếu p khác nullptr, cấp phát một size_t có giá trị 1 để đếm số tham chiếu.
- Nếu p là nullptr, con trỏ ref_count cũng là nullptr.
	 /**
	* @brief Copy constructor tăng bộ đếm tham chiếu.
	* @param other Đối tượng SharedPointer cần sao chép.
	*/
	SharedPointer(const SharedPointer &other) : ptr(other.ptr), ref_count(other.ref_count)
	{
	    if (ref_count) (*ref_count)++;
 
 	}
 - Khi khởi tạo con trỏ mới bằng cách Copy con trỏ đã có để quản lý chung vùng nhớ, Với Unique Pointer thì sẽ xóa con trỏ hiện tại để con trỏ mới được quản lý. Nhưng với Shared Pointer, sẽ gán con trỏ mới bằng với giá trị con trỏ hiện có và chỉ định chung vùng nhớ của biến ref_count và cộng biến này lên 1.
	```cpp
 
	/**
	* @brief  Giải phóng tài nguyên và trả về con trỏ thô hiện tại.
	* @return Con trỏ thô đến đối tượng được quản lý trước khi giải phóng.
	*/
	T* release()
	{
	    T *temp = ptr;
	    ptr = nullptr;
	    if (ref_count && --(*ref_count) == 0)
	    {
	        delete ref_count;
	        ref_count = nullptr;
	    }
	    return temp;
	}
	
	/**
	* @brief  Toán tử gán bằng copy.
	* @param  other Đối tượng SharedPointer cần sao chép.
	* @return Tham chiếu đến đối tượng SharedPointer hiện tại.
	*/
	SharedPointer& operator = (const SharedPointer &other)
	{
	    if (this != &other)
	    {
	        release();
	        ptr = other.ptr;
	        ref_count = other.ref_count;
	        if (ref_count) (*ref_count)++;
	    }
	    return *this;
	}
 - kiểm tra địa chỉ của 2 ptr hiện tại có giống nhau hay k.
 - gọi release để xóa đối tượng của pointer muốn copy trước khi copy
 - Sau đó gán con trỏ hiện tại với con trỏ mới và tăng ref_count lên 1.
- ví dụ:
	```cpp
	#include <iostream>
	#include <memory>
	
	using namespace std;
	
	/***********************************************************************
	 * shared pointer (shared_ptr) là một smart pointer hỗ trợ chia sẻ quyền 
	 * sở hữu đối với một đối tượng.
	 * 
	 * Nhiều shared_ptr có thể cùng sở hữu một đối tượng. Đối tượng chỉ được
	 * giải phóng khi không còn shared_ptr nào sở hữu nó (đếm tham chiếu đạt 
	 * giá trị 0).
	 **********************************************************************/
	
	int main(int argc, char const *argv[])
	{
	    shared_ptr<int> sptr1 = make_shared<int>(20); // 0x01
	    shared_ptr<int> sptr2 = sptr1;
	    shared_ptr<int> sptr3 = sptr1;
	
	    {
	        shared_ptr<int> sptr4 = sptr1;
	        cout << "Count: " << sptr1.use_count() << endl;
	    }
	
	    cout << "Count: " << sptr1.use_count() << endl;
	    /***********************************************************************
	    * use_count(): trả về số lượng shared_ptr đang cùng quản lý đối tượng
	    * (kiểm tra số lượng tham chiếu)
	    ***********************************************************************/
	
	
	    cout << "sptr1 = " << *sptr1 << endl;
	    cout << "sptr2 = " << *sptr2 << endl;
	    cout << "sptr3 = " << *sptr3 << endl;
	
	    
	    int *sptr = sptr1.get();
	    cout << "sptr: " << *sptr << endl;
	    /***********************************************************************
	    * trả về con trỏ thô (int*) trỏ tới vùng nhớ mà ptr1 đang quản lý
	    ***********************************************************************/
	
	    *sptr = 50;
	    cout << "sptr: " << *sptr << endl;
	    /***********************************************************************
	    * thay đổi giá trị con trỏ thô (*ptr = 50) sẽ làm thay đổi giá trị của đối 
	    * tượng được shared_ptr quản lý
	    ***********************************************************************/
	
	    shared_ptr<int> a = make_shared<int>(40);   // 0xa1
	    shared_ptr<int> b = make_shared<int>(50);   // 0xb3
	    a.swap(b);
	    cout << "a = " << *a << endl;
	    cout << "b = " << *b << endl;
	    
	
	    a = move(b);
	    cout << "a = " << *a << endl;
	
	    if (sptr1.unique()){
	        cout << "true\n";
	    } else {
	        cout << "false\n";
	    }
	    
	    return 0;
	}
 #### Weak pointer
- weak_ptr là một cơ chế giữ tham chiếu yếu (weak reference) đến một đối tượng được quản lý bởi shared_ptr. Nó cung cấp một cách an toàn để theo dõi một đối tượng mà không tăng bộ đếm tham chiếu của shared_ptr. weak_ptr không trực tiếp truy cập đến đối tượng (object) mà nó theo dõi. 
- weak_ptr có một phương thức là lock(), mà trả về một shared_ptr. Nếu shared_ptr mà weak_ptr theo dõi vẫn tồn tại, lock() sẽ trả về một shared_ptr hợp lệ có thể sử dụng để truy cập đối tượng. Ngược lại, nếu shared_ptr đã bị giải phóng, lock() sẽ trả về một shared_ptr rỗng.
- Constructor:
  	```cpp
	/**
	* @brief Constructor khởi tạo WeakPointer từ SharedPointer.
	* @param shared Đối tượng SharedPointer.
	*/
	WeakPointer(const SharedPointer<T> &shared) : ptr(shared.get()), ref_count(nullptr)
	{
	    ref_count = shared.use_count() ? new size_t(shared.use_count()) : nullptr;
	}
- Khởi tạo đối tượng mới từ Shared Pointer nhưng sẽ tạo một đối tượng mới ở vùng nhớ khác để chứa ref_count bằng 0 nếu shared pointer không quản lý đối tượng nào hoặc bằng ref_count của shared pointer nếu nó lớn hơn 0.
Method expired
	```cpp
	/**
	* @brief  Kiểm tra xem WeakPointer có còn quản lý đối tượng không.
	* @return true nếu đối tượng không tồn tại, false ngược lại.
	*/
	bool expired() const
	{
	    return !ref_count || *ref_count == 0;
	}
- Trả về true khi ref_count bằng 0 hoặc NULL. tức Weakpointer không còn quản lý đổi tượng nào.

- Method Lock
	```cpp
	/**
	* @brief  Chuyển WeakPointer thành SharedPointer nếu đối tượng còn tồn tại.
	* @return SharedPointer đến đối tượng hoặc SharedPointer trống nếu đối tượng không còn tồn tại.
	*/
	SharedPointer<T> lock() const
	{
	    return expired() ? SharedPointer<T>(nullptr) : SharedPointer<T>(ptr);
	}
- Ép kiểu đối tượng hiện tại từ Weak Pointer thành Shared Pointed để có thể đọc giá trị.

- Tất cả các Class trên được tích hợp trong thư viện memory

- Một số phương thức mới:
- make_unique Tạo một đối tượng mới được quản lý bởi một Unique_Pointer Ví dụ:
  	```cpp
	unique_ptr<SpeedSensor> uptr = make_unique<SpeedSensor>(10);
	unique_ptr<SpeedSensor> uptr1(new SpeedSensor(10));
Cả hai dòng lệnh trên có chung ý nghĩa

- Tương tự ta sẽ có make_shared
- Ví dụ:
  	```cpp
	shared_ptr<int> sptr1 = make_shared<int>(20);
- Hoán đổi hai đối tượng
  	```cpp
	shared_ptr<int> a = make_shared<int>(40);   // 0xa1
	shared_ptr<int> b = make_shared<int>(50);   // 0xb3
	a.swap(b);
- Bây giờ b sẽ quản lý 40 và a sẽ quản lý 50
- a = move(b);: Chuyển đối tượng được b quản lý sang a và b không còn quản lý đối tượng nào.
</details>

