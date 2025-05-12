• Xóa phần tử ở cuối
• Nếu danh sách rỗng  không làm gì cả
• Danh sách có 1 phần tử ->Xóa đầu
• Ngược lại  phải tìm phần tử gần cuối – pre_last 
• Xóa phần tử cuối từ pre-last, và cập nhật lại phần tử cuối
//code C:
// Hàm xóa node cuối cùng khỏi danh sách liên kết đơn
void removeLast(struct Node** head_ref) { //cần ** head_ref là do khi danh sách chỉ có 1 phần tử , khi removelast thì head sẽ trỏ đến NULL
    // 1. Nếu danh sách rỗng, không làm gì cả
    if (*head_ref == NULL)
        return;

    // 2. Nếu danh sách chỉ có một phần tử
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    // 3. Tìm phần tử kế cuối (pre_last)
    struct Node* pre_last = *head_ref;
    while (pre_last->next->next != NULL) {
        pre_last = pre_last->next;
    }

    // 4. Giải phóng node cuối cùng
    free(pre_last->next);

    // 5. Cập nhật lại con trỏ của pre_last thành NULL
    pre_last->next = NULL;
}
