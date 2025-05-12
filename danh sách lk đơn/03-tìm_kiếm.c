• Tìm kiếm
• Tìm xem khóa key có xuất hiện trong danh sách
• Đếm số lượng phần tử có giá trị bằng giá trị cho trước
//T(n)=O(n)
/* Checks whether the value x is present in linked list */
bool search(struct Node* head, int key){
  struct Node* current = head; // Initialize currentwhile (current != NULL)
  {
    if (current->key == key)
      return true;
    current = current->next;
  }
    return false;
  }
/* Checks whether the value x is present in linked list */
struct Node* search(struct Node* head, intkey){
  struct Node* current = head; // Initialize currentwhile (current != NULL)
  {
    if (current->key == key)
      return current;
    current = current->next;
  }
    return NULL;
  }
