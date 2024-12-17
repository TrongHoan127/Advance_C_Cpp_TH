# Advance---C
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
