/**
 * Định nghĩa cho một node trong danh sách liên kết đơn.
 * Mỗi node chứa giá trị (val) và con trỏ (next) trỏ đến node tiếp theo.
 */
/*struct ListNode {
    int val;            // Giá trị của node
    struct ListNode *next; // Con trỏ trỏ đến node tiếp theo
};

/**
 * Hàm gộp hai danh sách liên kết đã được sắp xếp thành một danh sách mới cũng sắp xếp.
 * @param list1: Danh sách liên kết thứ nhất.
 * @param list2: Danh sách liên kết thứ hai.
 * @return: Một danh sách liên kết đã sắp xếp, chứa các phần tử từ list1 và list2.
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Khởi tạo một node giả để tiện việc thao tác với đầu danh sách kết quả.
    struct ListNode fake_node;
    // Khai báo con trỏ current, trỏ tới node giả fake_node, sẽ giúp duyệt và nối các node vào danh sách kết quả.
    struct ListNode* current = &fake_node;
    
    // Gán next của node giả là NULL (chưa có phần tử nào được nối vào).
    fake_node.next = NULL;

    // Bắt đầu duyệt qua cả hai danh sách list1 và list2.
    while (list1 && list2) {  // Cứ tiếp tục cho đến khi một trong hai danh sách rỗng.
        // So sánh giá trị của phần tử đầu tiên của cả hai danh sách.
        if (list1->val < list2->val) {
            // Nếu giá trị của list1 nhỏ hơn list2, nối list1 vào danh sách kết quả.
            current->next = list1;
            // Di chuyển list1 tới node tiếp theo.
            list1 = list1->next;
        } else {
            // Nếu giá trị của list2 nhỏ hơn hoặc bằng list1, nối list2 vào danh sách kết quả.
            current->next = list2;
            // Di chuyển list2 tới node tiếp theo.
            list2 = list2->next;
        }
        
        // Di chuyển con trỏ current đến node vừa nối vào danh sách kết quả.
        current = current->next;
    }

    // Sau khi một trong hai danh sách đã hết phần tử, nối phần còn lại của danh sách còn lại vào kết quả.
    // Nếu list1 còn phần tử thì nối vào, nếu không thì nối list2.
    current->next = list1 ? list1 : list2;

    // Trả về node kế tiếp của node giả fake_node, tức là danh sách kết quả đã được nối.
    return fake_node.next;
}
