#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int value; // dữ liệu của node
  struct node* next; // con trỏ tới node tiếp theo
} node;
node* createNode (int value)
{   node* ptr = (node*)malloc(sizeof(node)); // khởi tạo địa chỉ cho Node
    ptr->value = value;
    ptr->next = NULL; // chưa liên kết Node với nhau thì phải null trước
    return ptr; // trả về lại vị trí của ptr
}
void push_back(node** head, int value) // thêm node vào cuối danh sách
{
    node* newNode = createNode(value) ;  // khoi tao node
                            
    if (*head == NULL)   // nếu danh sách rỗng, gán 1 node mới là đầu
    {
        *head = newNode;
    }
    else                // if head có node 
    {
        node* last = *head;          // use last instead of head because we are using pointer, use head will change the structure of linkedlist
        while (last->next != NULL) // which mean the current node is not the last node
        {
            last = last ->next;    // check next node until it a last node

        }

        last->next = newNode;     // change it next member point to address of new node have just create
    }
}
void push_front(node **head, int value) // them 1 node vao phia truoc
{ 
    node* newNode = createNode(value) ; 
    newNode -> next = *head; // gan con tro newnode vao node dau tien
    *head = newNode; // head tro den node moi
}
void pop_back(node **head) // xoa node cuoi
{
 if(*head == NULL)
    {
        printf("danh sach rong, khong co node de xoa\n");
        return;
    }
 if((*head)->next == NULL) // 1 node duy nhat
    {
        free(*head); // giaiphong
    }
 node* temp = *head;
 while (temp -> next != NULL && temp -> next -> next != NULL)
    {
    temp = temp -> next;
    }
 free(temp->next);  // Giải phóng bộ nhớ của node cuối cùng
 temp->next = NULL;
}
void pop_front(node **head)  // xoa node dau tien
{ 
 if (*head == NULL) {
        printf("Danh sách rỗng, không có node để xóa.\n");
        return;
    }
node* temp = *head;
// Cập nhật head để trỏ đến node tiếp theo
    *head = (*head)->next;

    // Giải phóng bộ nhớ của node đầu tiên
    free(temp);
}
int front(node *head) // lay gia tri cua node dau tien
{
        if ( head == NULL) {
        printf("Danh sách liên kết rỗng!\n");
        return -1;
    } else { return head->value;
}
}
int back(node *head) // lay gia tri cua node cuoi cung
{ 
        if ( head == NULL) {
        printf("Danh sách liên kết rỗng!\n");
        return -1;
    }     
    node* temp = head;
    // Duyệt qua danh sách cho đến khi gặp nút cuối cùng
    while (temp->next != NULL) {
        temp = temp->next;
    }

    return temp->value;
}

void insert(node **head, int value, int position) // them 1 node vao mot vi tri bat ky
{
    // Nếu vị trí không hợp lệ (vị trí nhỏ hơn 0)
     if (position < 0) {
         printf("Vị trí không hợp lệ.\n");
         return;
     }
 
     // Tạo node mới với dữ liệu cần thêm
     node* newNode = createNode(value);
 
     // Nếu thêm ở đầu (vị trí 0)
     if (position == 0) {
         newNode->next = *head;  // Con trỏ next của node mới trỏ đến node đầu tiên
         *head = newNode;        // Cập nhật head trỏ đến node mới
         return;
     }
 
     // Duyệt đến node trước vị trí cần chèn (node ở vị trí position - 1)
      node* temp = *head;
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
void delete_list(node **head, int position) // xoa 1 node tai mot vi tri bat ky
{
    if (*head == NULL){
        printf("danh sach rong.\n");
        return;}

    node *temp = *head;
    if (position == 0) {
        *head = temp->next;  // Thay đổi head
        free(temp);          // Giải phóng bộ nhớ
        return;
    }

    // Duyệt qua danh sách để tìm nút cần xóa
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // Nếu vị trí không hợp lệ (vượt quá số nút trong danh sách)
    if (temp == NULL || temp->next == NULL) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }

    // Lấy nút cần xóa và cập nhật liên kết của nút trước nó
    struct node* next = temp->next->next;
    // Giải phóng bộ nhớ của nút cần xóa
    free(temp->next);

    // Cập nhật liên kết của nút trước nó
    temp->next = next;

}
int size( node *head)  {// lay kich thuoc cua list 
    int size = 0;
    node* temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp -> next;
    }
    return size;
}

int get(node* head, int pos)
{
    int i = 0;
 
    while (head->next != NULL && pos != i)
    {
        head = head->next;
        i++;
    }

    if (pos != i)
    {
        printf("Error: List has less element\n");
        return 0;
    }

    int value = head->value;
    return value;
}





int main()
{
    node* arr = NULL;
    push_back(&arr, 7);
    push_back(&arr, 4);
    push_back(&arr, 5);
    push_back(&arr, 3);
    push_back(&arr, 10);
    delete_list(&arr,3);
    printf("Value test: %d\n", get(arr, 2));
    printf("Value test: %d\n", get(arr, 0));
    printf("Value test: %d\n", get(arr, 5));
    printf("Value test: %d\n", size(arr));
    printf("Value test: %d\n", back(arr));
    printf("Value test: %d\n", front(arr));
    


	return 0;
}