• Xóa phần tử ở vị trí cho trước
• Phần tử trước vị trí cần xóa trỏ bởi con trỏ prev
• Không rơi vào trường hợp đầu hoặc cuối 
• Phần tử cần xóa trỏ bởi tmp
• Nếu phần tử cần xóa là 
• Đầu/Cuối thì xử lý thế nào?
• Xóa phần tử có giá trị bằng khóa K
• Xóa toàn bộ dãy

// Hàm xóa node sau node được chỉ định (prev) trong danh sách liên kết đơn
void deleteNode(struct Node* prev) {
    // 1. Kiểm tra nếu node sau prev là NULL (không có gì để xóa)
    if (prev == NULL || prev->next == NULL) {
        printf("Không thể xóa node, prev hoặc prev->next là NULL!\n");
        return;
    }

    // 2. Ghi nhận địa chỉ node cần xóa (temp sẽ trỏ tới node cần xóa)
    struct Node* temp = prev->next;

    // 3. Unlink node cần xóa (kết nối lại prev với node sau node cần xóa)
    prev->next = temp->next;

    // 4. Giải phóng bộ nhớ của node cần xóa
    free(temp);
}
