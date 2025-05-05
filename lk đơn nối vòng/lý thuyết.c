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

• Biểu diễn playlist 
• Dùng danh sách liên kết đơn nối vòng thay vì danh sách liên kết đơn thông thường
• Repeat playlist dễ hơn
• Điều phối tiến trình trong HDH theo cơ chế Round-robin Scheduling
• Thông tin mỗi tiến trình sẽ được lưu trong 1 node (ID tiến trình, trạng thái, thời gianthực hiện còn lại, v.v)
• Mỗi tiến trình sẽ được cấp phát 1 chu kỳ time slice dùng CPU. Sau mỗi khoảngtime
slice, hệ điều hành sẽ thực hiện việc chuyển đổi (context switch) từ tiến trình hiện tại sang tiến trình tiếp theo trong danh sách. 
• Việc thêm/xóa tiến trình và xoay vòng dễ dàng hơn với danh sách liên kết đơn nối vòng
