• Thêm vào đầu tiên – push
• Danh sách ban đầu đang có ABCD, chèn thêm phần tử E vào đầu để
được danh sách mới EABCD

Các bước cần làm gồm
• Cấp phát động lưu trữ phần tử mới • Gán giá trị phần tử mới • Cập nhật vị trí phần tử mới
Hàm push sẽ làm thay đổi giá trị con
trỏ đầu danh sách , vì vậy trong hàm
cần truyền vào là **head_ref 
//Code C:
void push(struct Node** head_ref, int new_data)
{
/* 1. cấp phát động nút mới */
  struct Node* new_node = (struct Node*) malloc(sizeof(structNode));/* 2. Cập nhật dữ liệu nút mới */
  new_node->data = new_data;
/* 3. Biến nút mới thành đầu của dãy hiện tại*/
  new_node->next = (*head_ref);
/* 4. Cập nhật lại giá trị của con trỏ đầu dãy */
  (*head_ref) = new_node;
}
