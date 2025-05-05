
• Thêm vào sau 1 nút cho trước –
insertAfter
• Danh sách ban đầu
ABCD, Chèn E vào sau
phần tử B để được
ABECD
• Cần thêm con trỏ trỏ vào vị trí
trước chèn prev_node
• Trong hàm KHÔNG làm thay
đổi giá trị của con trỏ
prev_node nên không cần **
// Hàm chèn một node mới sau node prev_node
void insertAfter(struct Node* prev_node, int new_data) {
    // 1. Kiểm tra nếu prev_node là NULL thì không chèn được
    if (prev_node == NULL) {
        printf("Node trước không tồn tại.\n");
        return;
    }

    // 2. Cấp phát bộ nhớ cho node mới
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        return;
    }

    // 3. Gán dữ liệu cho node mới
    new_node->data = new_data;

    // 4. Trỏ next của node mới đến node sau prev_node
    new_node->next = prev_node->next;

    // 5. Nối prev_node với node mới
    prev_node->next = new_node;
}
