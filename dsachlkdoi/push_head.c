void push(Node** head_ref, int new_data)
{
    // 1. Cấp phát bộ nhớ cho node mới
    Node* new_node = new Node();

    // 2. Gán dữ liệu vào node mới
    new_node->data = new_data;

    // 3. Gán con trỏ next của node mới trỏ đến node đầu danh sách hiện tại
    // và prev trỏ NULL vì nó sẽ trở thành node đầu
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    // 4. Nếu danh sách không rỗng, cập nhật con trỏ prev của node đầu cũ
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // 5. Cập nhật lại head để trỏ đến node mới
    (*head_ref) = new_node;
}
