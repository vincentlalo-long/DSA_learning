// Hàm đảo ngược danh sách liên kết đôi
void reverse(struct Node **head_ref)
{
    struct Node *temp = NULL;
    struct Node *current = *head_ref;

    // Duyệt qua toàn bộ danh sách
    // Tại mỗi node, hoán đổi con trỏ prev và next
    while (current != NULL)
    {
        // Lưu lại prev trước khi đổi
        temp = current->prev;

        // Đảo chiều liên kết
        current->prev = current->next;
        current->next = temp;

        // Di chuyển sang node tiếp theo (về phía trước cũ)
        current = current->prev;
    }

    // Sau khi duyệt xong, temp sẽ trỏ đến node cũ cuối cùng
    // head mới chính là node trước của temp (do prev/next đã đảo)
    if (temp != NULL)
        *head_ref = temp->prev;
}
