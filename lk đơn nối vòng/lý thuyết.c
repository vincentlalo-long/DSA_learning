• Danh sách liên kết đơn nối vòng: Con trỏ của phần tử cuối trỏ về đầu danh sách
• Tác dụng: • có thể quay lại từ đầu khi đã ở cuối dãy
• Kiểm tra ở cuối dãy : currentNode->next == head ?
• Kiểm tra đang ở đầu dãy: currentNode == head
void printList(Node* head) {
    Node* temp = head;
    if (head != NULL) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);  // dừng khi quay lại node đầu
    }
}
• Một số bài toán
• Thêm phần tử vào danh sách liên kết đơn nối vòng
• Xóa phần tử
• Tìm phần tử giữa danh sách
• Đếm số lượng phần tử trong danh sách
• Bài toán vòng tròn Josephus
• Chuyển danh sách liên kết đơn thường sang dạng nối vòng

