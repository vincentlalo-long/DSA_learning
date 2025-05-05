Thêm vào cuối dãy – append
• Dãy đang là ABCD, chèn
thêm E vào cuối dãy để được
dãy mới ABCDE
• Nếu dãy rỗng  thêm vào đầu
= cuối
• Ngược lại, phải duyệt tuần tự
tìm cuối dãy
• Nếu dãy rỗng ta sẽ phải cập nhật lại con trỏ đầu dãy  cần truyền vào **
𝑇(𝑛) = ?

void append(struct Node** head_ref, int new_data){
  struct Node* new_node = (struct Node*) malloc(sizeof(structNode));
  struct Node *last = *head_ref;
  new_node->data = new_data;
  /* Nút mới là cuối dãy nên next sẽ trỏ vào NULL*/
  new_node->next = NULL;
  /* Nếu danh sách đang rỗng cập nhật lại đầu */
  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }
  /* Ngược lại, tìm cuối dãy*/
  while (last->next != NULL)
    last = last->next;
  /* Gắn nút mới là cuối dãy*/
    last->next = new_node;
  return;
}
