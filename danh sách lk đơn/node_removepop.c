Xóa phần tử
• Lấy phần tử ở đầu - pop
• Cập nhật lại con trỏ head
• Trả về phần tử

//code C :
// Hàm lấy node đầu ra khỏi danh sách và trả về node đó
struct Node* pop(struct Node** head_ref) {
    // 1. Nếu danh sách rỗng, không làm gì và trả về NULL
    if (*head_ref == NULL)
        return NULL;

    // 2. Ghi lại địa chỉ của node đầu
    struct Node* temp = *head_ref;

    // 3. Cập nhật head để trỏ sang node tiếp theo
    *head_ref = (*head_ref)->next;

    // 4. Ngắt liên kết node ra khỏi danh sách
    temp->next = NULL;

    // 5. Trả về node đầu (đã tách ra khỏi danh sách)
    return temp;
}
