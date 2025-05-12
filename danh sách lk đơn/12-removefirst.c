Xóa phần tử ở đầu - removeFirst 
• Cập nhật lại con trỏ head
• Gọi lệnh giải phóng bộ nhớ

void removeFirst(struct Node** head_ref) {
    // 1. Nếu danh sách rỗng thì không làm gì cả
    if (*head_ref == NULL)
        return;

    // 2. Ghi lại địa chỉ của node đầu cũ
    struct Node* temp = *head_ref;

    // 3. Cập nhật head để trỏ sang node tiếp theo
    *head_ref = (*head_ref)->next;  //head_ref không đổi địa chỉ không hề thay đổi , nó chỉ thay đổi giá trị là trỏ sang giá trị bên cạnh

    // 4. Giải phóng vùng nhớ của node đầu cũ
    free(temp);
}
