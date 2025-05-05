// Hàm chia danh sách liên kết đơn vòng thành hai danh sách vòng
void splitList(struct Node* head, struct Node** head1_ref, struct Node** head2_ref) {
    // Nếu danh sách rỗng thì không làm gì cả
    if (head == NULL)
        return;

    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    // Tìm midpoint bằng kỹ thuật slow - fast pointer
    while (fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    // Nếu số phần tử chẵn, di chuyển fast_ptr thêm 1 bước nữa
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    // head1 là danh sách từ head đến slow_ptr
    *head1_ref = head;

    // head2 là danh sách từ node kế tiếp của slow_ptr đến fast_ptr
    *head2_ref = slow_ptr->next;

    // Làm tròn danh sách thứ nhất
    slow_ptr->next = *head1_ref;

    // Làm tròn danh sách thứ hai
    fast_ptr->next = *head2_ref;
}
