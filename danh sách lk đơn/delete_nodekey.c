• Xóa phần tử có giá trị bằng khóa key
• Key có thể là đầu
• Có thể là giữa/ cuối 
• Luôn phải free bộ nhớ
// Hàm xóa node có giá trị 'key' trong danh sách liên kết đơn
void deleteNode(struct Node** head_ref, int key) {
    // 1. Lưu địa chỉ của phần tử đầu tiên trong danh sách (temp)
    struct Node *temp = *head_ref, *prev;

    // 2. Kiểm tra xem node đầu tiên có phải là phần tử cần xóa không
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;  // Cập nhật lại head để trỏ tới phần tử tiếp theo
        free(temp);              // Giải phóng bộ nhớ của phần tử đầu
        return;
    }

    // 3. Tìm phần tử có giá trị 'key', đồng thời lưu phần tử trước nó (prev)
    while (temp != NULL && temp->data != key) {
        prev = temp;            // Ghi nhận phần tử trước node cần xóa
        temp = temp->next;      // Di chuyển temp đến phần tử tiếp theo
    }

    // 4. Nếu không tìm thấy phần tử cần xóa (temp == NULL), kết thúc hàm
    if (temp == NULL)
        return;

    // 5. Xóa phần tử temp (node cần xóa)
    prev->next = temp->next;  // Liên kết lại phần tử trước với phần tử sau node cần xóa
    free(temp);               // Giải phóng bộ nhớ của node cần xóa
}
