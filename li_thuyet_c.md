===================================Static=========================================
*Static cục bộ: là một biến cục bộ được khai báo với từ khóa Static chỉ cần khai 
báo một lần, nó sẽ tồn tại trong thời gian chương trình chạy. Gía trị của nó không
bị mất đi ngay cả khi kết thúc chương trình. Chỉ được sử dụng nội bộ trong hàm mà nó
khai báo Static cục bộ thường được dùng khi không muốn người khác xem nội dung của 
hàm đấy.
*Static toàn cục: chỉ được sử dụng và truy cậy trong file mà nó khởi tạo,các file khác
không thể truy cập.


==============================Phân vùng nhớ=========================================
* Có 5 phân vùng nhớ: phân vùng nhớ Stack, heap,bss,data,text.
- Phân vùng nhớ text:
    + Chỉ để đọc.
    + Chứa khai báo hằng số.
- Phân vùng nhớ data:
    + Có quyền đọc và viết.
    + Được sử dụng để lưu khai báo biến toàn cục, biến static và giá trị khởi tạo khác 0.
    + Được giải phóng khi kết thúc chương trình.
- Phân vùng nhớ BSS:
    + Có quyền đọc và viết.
    + Được sử dụng để lưu khai báo biến toàn cục, biến Static và giá trị khởi tạo bằng 0
    hoặc chưa được khởi tạo.
    + Được giải phóng khi kết thúc chương trình.
- Phân vùng nhớ heap:
    + Có quyền truy cập đọc và viết.
    + Lưu trữ các biến động bao gồm: con trỏ, các mảng động, các đối tượng.
    + Được sử dụng để cấp phát các bộ nhớ như: malloc, calloc, realloc....
    + Sẽ được giải phóng khi gọi hàm Free
- Phân vùng nhớ stack:
    + Có quyền truy cập đọc và viết.
    + Được sử dụng để khai báo biến local, input paravector của hàm.
    + Được giải phóng khi ra khỏi block code của hàm.

* So sánh phân vùng nhớ bss và data
- Giống nhau: Đều được lưu trong RAM trong quá trình thực thi của chương trình, đều là
phân vùng nhớ tĩnh
- Khác nhau:
    + Phân vùng nhớ BSS sẽ lưu các biến toàn cục và static chưa được khởi tạo giá trị ban đầu,
    còn phân vùng nhớ data sẽ lưu các biến toàn cục và static đã được khởi tạo giá trị ban đầu.
    + Gía trị mặc định của các biến trong phân vùng nhớ BSS là 0, trong khi giá trị mặc định của
    các biến trong phân vùng nhớ Data phụ thuộc vào giá trị khởi tạo ban đầu.

* So sánh phân vùng nhớ heap và stack
- Giống nhau: Đều được lưu trong RAM khi chương trình được thực thi.

-Khác nhau:
    + Stack được quản lý bởi trình biên dịch, trong khi đó heap được quản lý bởi người lập trình.
    + Stack để lưu trữ các biến cục bộ, còn heap được dùng để lưu trữ các biến động.
    + Các biến được lưu dữ trên stack thì có thể truy cập nhanh hơn các biến lưu trên heap.
    + Heap được sử dụng để lưu các bộ nhớ động cho các đối tượng có kích thước lớn lớn
    hoặc kích thước không xác định, còn Stack được sử dụng bộ nhớ để cấp phát cho biến cục bộ 
    có kích thước đã xác định từ trước
    + Sử dụng heap có thể dẫn đến các lỗi bộ nhớ như: thừa một phần bộ nhớ, hoặc ghi đè lên bộ nhớ
    không được cấp phát.



==========================================Marco và function======================================
-Marco: 
    + Là đoạn mã được định nghĩa bằng #define.
    + Được xử lí bởi quá trình tiền xử lí.
    + Đơn giản là thay thế đoạn code được khai báo marco vào bất cứ chỗ nào được khai báo

-Function:
    + Được xử lý trong quá trình compiler
    + Cần phải được định nghĩa, khai báo và triển khai
    + Hàm bình thường phải gọi một function call,lưu địa chỉ của hàm vào stack pointer, sau đó Sẽ
    trỏ con trỏ PC đến hàm được gọi, sau khi thực hiện xong nó sẽ vào stack pointer để lấy địa
    chỉ đã lưu rồi thực hiện tiếp chương trình.

-So sánh marco và function:
    + Marco thường được sử dụng với các tác vụ đơn giản, trong khi đó function được sử dụng với các
    tác vụ dài và phức tạp hơn.
    + Marco không có kiểu trả về, trong khi function có kiểu tra về.
    + Marco được định nghĩa qua #define và không cần khai báo trước, trong khi function phải khai báo
    định nghĩa và định nghĩa trước khi sử dụng
    + Về tốc độ và kích thước thì thông thường marco sẽ nhanh hơn và nhỏ hơn function
    + Tuy vây, marco cũng có hạn chế về việc không được kiểm tra lỗi, không được phân biệt kiểu dữ liệu
    sẽ dẫn đến cách lỗi không mong muốn khi sử dụng sai cách.

=========================================Struct và Union==============================================

- Đều là kiểu dữ liệu do người dùng tự định nghĩa

- Union:
    + Dữ liệu các thành viên sẽ được lưu chung một vùng nhớ
    + Kích thước của Union là kích thước của thành viên lớn nhất
    + Khi thay đổi một thành viên trong Union sẽ dẫn đến sự thay đổi của các thành viên khác.
    +VD:
    uint8_t Arr1[5];           // 5*1=5   5 bit 
    uint16_t Arr2[2];          // 2*2=4   4 bit 
    uint32_t Arr3[4];          // 4*4=16  16 bit
==> Kich thước của Union này là  16bit
==> lúc này gọi size của Arr1 thì sẽ ra 16 bit

- Struct:
    + Dữ liệu các thành viên sẽ được lưu tại các vùng nhớ khác nhau.
    + Kích thước của Struct được tính là kích thước của các thành viên cộng lại tại vì còn phụ thuộc vào
    bộ nhớ đệm(padding)
    + VD:
    uint8_t Arr1[5];           // 5*1=5   5 bit + 3 bit đệm => 5 bit 
    uint16_t Arr2[2];          // 2*2=4   4 bit + 3 bit đệm => 9 bít +3 bit đệm => 12 bit
    uint32_t Arr3[4];          // 4*4=16    =>16+12=28  
==> Kich thước của Struct này là  28


============================================Con trỏ=======================================================

-Khái niệm:
    + Là một biến, bình thường một biến dùng để lưu giá trị nhưng biến con trỏ dùng để lưu địa chỉ của giá trị
    + VD: int *ptr // đây là khai báo biến con trỏ: Là con trỏ có tên là ptr, có thể lưu các địa chỉ mà giá trị
                      của địa chỉ là kiểu int

-Con trỏ void:
    + Có thể lưu mọi địa Chỉ
    + Chỉ có thể lưu địa chỉ, muốn lấy giá trị của địa chỉ thì phải ép kiểu cho nó.
    + VD:   char c='b';
            void *ptr1;
            ptr1 = &c;
            printf("giá trị của c %c", *(char *)ptr1 )// ép kiểu char để lấy giá trị cho biến c.
           
-Con trỏ NULL:
    + Bản chất của con trỏ NULL là là con trỏ void với giá trị bằng 0 và địa chỉ bằng 0.
    + Khi khai báo con trỏ thì phải khai báo địa chỉ cho nó, nếu chưa khai báo thì phải gán cho nó bằng con trỏ NULL
    + Khi khai báo con trỏ, các hàm đã xử lý xong, nếu khổng cần sử dụng nữa thì gán nó về con trỏ NULL.
    +VD: int *ptr2=NULL;
-Con trỏ hàm:
    + VD :
    void tong( int a, int b){
        printf("tong: %d",a+b);
    }
    int main(){
        void(*tinhtoan)(int , int)//đây là khai báo con trỏ hàm: con trỏ này có tên là tinhtoan, nó có thể truy cập đến
                                    tất cả các hàm có input paravector là int và int và kiểu tra về là void
        tinhtoan=&tong;// gán địa chỉ của tổng cho con trỏ hàm
        tinhtoan(1,2);
    }
    + Con trỏ hàm trong hàm: sử dụng con trỏ hàm làm input paravector
    +VD: void toanhoc( (*tinhtoan)(int,int), int a, int b){
        tinhtoan(a,b);
    }
        toanhoc(tong,a,b);



-pointer to pointer( con trỏ cấp 2):
    + Dùng để lưu địa chỉ của con trỏ
    + VD: int a =10;
          int *ptr1=&a;
          int **ptr2=&ptr1;//địa chỉ của con trỏ ptr1 được lưu vào con trỏ ptr2
