## run - time (đa hình tại thời điểm chạy)
- runtime : thay đổi đột ngột trong quá trình chạy
- hàm ảo
    + hàm đc khai báo ở lớp cơ sở (là class đc các class khác kế thừa chung) thêm từ khóa "virtual"
    + nó cho phép các lớp con kế thừa ghi đè (override), gom 2 phiên bản method lại thành 1 và chọn phiên bản mới nhất (tính đa hình) -> khi biên dịch sẽ chỉ ra đc 1 method chung (ghi đè lên nhau)
    + còn overload vẫn giữ 2 phiên bản (tại thời điểm compiler, của tính kế thừa) -> ẩn 1 method để compiler
    + Nếu lớp con không ghi đè, thì sẽ dùng method mặc định trong cơ sở
- đa hình run time: 
    + là khả năng chọn phương thức (method)(đa hình) nào đc gọi ra tại thời điểm chạy (runtime) dựa trên loại thực sự của object, không phải kiểu của con trỏ đang trỏ tới
    + mỗi thời điểm cho trỏ tới 1 object khác nhau, căn cứ vào object thuộc class sẽ cho ra mối method khác nhau(phụ thuộc class), chạy trong quá trình runtime
    --> có lệnh chuyển object, chuyển đc method theo object --> đa hình trong thời điểm chạy
- hàm thuần ảo(Pure virtual Function) không có giá trị, những class con kế thừa phải bắt buộc có nội dung ghi đè override lên hàm thuần ảo, k sẽ bị lỗi chương trình
- không thể tạo ra đối tượng từ class có chứ hàm thuần ảo( nhưng có thể tạo con trỏ đc)
- đa kế thừa: kế thừa từ nhiều class khác nhau, use chức năng của những class đó
## compile - time (đa hình tại thời điểm phiên dịch)
- kế thừa ảo: khi kế thừa nhìu phiên bản thì sẽ gộp lại thành 1 phiên bản duy nhất (ở quá trình biên dịch--> tạo ra 1 phiên bản để kế thừa)
    + cũng là kế thừa nhưng thêm từ khóa 'virtual'
    + giải quyết đc vấn đề kim cương (diamond problem:1 method có nhiều phiên bản khi use đa kế thừa) -> có 2 cách để giải quyết
    + đảm bảo chỉ có một bản sao duy nhất của lớp cơ sờ chung được kế thừa
- Function overloading (nạp chồng hàm): có ví dụ
    + nhiều hàm(method) có thể giống tên, khác nhau về số lượng và kiểu dữ liệu input parameters(đa hình)
    + xác định hàm cần gọi(method): dựa trên đặc điểm tham số truyền vào
- Operation overloading (nạp chồng toán tử)
    + cho phép định nghĩa lại các toán tử(+,-,*,/,==,>=,<=,>,<)
    + sử dụng cho các biến thuộc kdl mà mình tự định nghĩa (class, struct : object), thành viên của union dùng chung vùng nhớ nên sẽ k dùng đc nạp chồng toán tử
    + cú pháp: 
    <return_type> operator symbol (argument)
    {
        //logic của toán tử
    }
    + chỉ truyền vào 1 tham số duy nhất
    + 1 số toán tử k thể định nghĩa lại:
        + toán tử truy cập(.)
        + toán tử phạm vi(::)
        + toán tử điều kiện(?:) if(a>b) ?1:0
        + toán tử sizeof 
- Tham chiếu, tham trị
    + tham trị: (truyền tham số vào hàm)
        + tạo ra bản sao của giá trị biến được truyền vào hàm
        + bất kỳ thay đổi nào đối với tham số truyền vào sẽ không ảnh hưởng tới giá trị của biến gốc
    + tham chiếu: 
        + truyền trực tiếp địa chỉ của biến gốc
        + mọi sự thay đổi với tham số sẽ ảnh hưởng tới giá trị của biến gốc
- phân biệt con trỏ và tham chiếu
    + con trỏ tốn địa chỉ vùng nhớ trên ram để cấp phát cho con trỏ
    + tham chiếu không tốn vùng nhớ trên ram để cấp phát (chỉ có C++ đc dùng thay cho con trỏ)
- con trỏ this (this pointer)
    + không cần khai báo, tự động sinh ra khi khai báo class
    + là 1 biến chứa địa chỉ biến khác (trỏ tới đối tượng hiện tại)
    + hằng con trỏ (constant ppinter): chỉ trỏ đc duy nhất 1 đối tượng, k trỏ đc đối tượng khác. Có thể thay đổi giá trị
    + khi tạo nhiều object từ 1 class, mỗi object sẽ có 1 con trỏ this riêng của nó