// Bài toán sẽ là hoán đổi các cặp node gần nhau , tức là node1 đổi node2 , node3 đổi node4 , ..
// Code C : 

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
  };
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL || head->next==NULL) return head; // Nếu node head rỗng hoặc danh sách chỉ có 1 node là head thì trả ngay về head
    struct ListNode dummyNode; // tạo 1 note giả dummy node để lưu trữ 
    dummyNode.next=head; // Khởi tạo node giả dummy đứng trước node head ở ban đầu 
    struct ListNode* prev=&dummyNode; // tạo 1 con trỏ prev để trỏ đến node trước của dummyNode
    while(prev->next!=NULL && prev->next->next!=NULL){ // Kiểm tra điều kiện vòng lặp 
        struct ListNode* firstN=prev->next ;// Ta sẽ dùng phương pháp như kiểu quy hoạch động 
        struct ListNode* secondN=firstN->next;
        firstN->next=secondN->next; // ta sẽ gán first->next sang node đằng sau second để hoán đổi 
        secondN->next=firstN; // Gán lại second thành node first ban đầu = cách trỏ đến node first

        prev->next=secondN; // di chuyển con trỏ prev->next trỏ đến second ( tức là node đầu của danh sách mới )
        prev=firstN; // di chuyển prev đến node sau khi đã hoán đổi 

    }
    return dummyNode.next; // trả về danh sashc liên kết
}
// REcursion : 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // Ta sẽ giải bằng phương pháp đệ quy 
    // Đầu tiên ta giải các TH base case 
    if(head==NULL || head->next==NULL) return head; // nếu không có node nào hoặc chỉ có duy nhất 1 node thì trả về 
    // Khi có 2 node trở lên thì ta sẽ đệ quy để swap
    struct ListNode* first=head;
    struct ListNode* second=first->next;
    first->next=swapPairs(second->next);
    second->next=first;
    return second;
}
