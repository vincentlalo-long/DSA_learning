Danh sách liên kết đôi nối vòng
• Các con trỏ thừa ở cuối trỏ về đầu và con trỏ thừa ở đầu sẽ trỏ xuống cuối 
• Có thể dùng thêm nút giả để phân biệt đầu và cuối 
• Con trỏ pNext của nút cuối trỏ vào nút đầu và con trỏ pPrev của nút đầu trỏ vào nút cuối. 
• Nút đầu danh sách là nút giả

#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Hàm tạo nút mới (nút thật)
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Hàm khởi tạo danh sách với nút giả
struct Node* createDummyList() {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->data = -1; // Dữ liệu vô nghĩa (nút giả)
    dummy->next = dummy;
    dummy->prev = dummy;
    return dummy;
}

// Hàm chèn vào cuối danh sách
void insertTail(struct Node* dummy, int data) {
    struct Node* newNode = createNode(data);

    struct Node* last = dummy->prev;

    last->next = newNode;
    newNode->prev = last;
    newNode->next = dummy;
    dummy->prev = newNode;
}

// Duyệt và in danh sách
void printList(struct Node* dummy) {
    struct Node* curr = dummy->next;
    printf("Danh sách: ");
    while (curr != dummy) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Giải phóng bộ nhớ
void freeList(struct Node* dummy) {
    struct Node* curr = dummy->next;
    while (curr != dummy) {
        struct Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(dummy);
}

// Hàm main
int main() {
    struct Node* dummy = createDummyList();

    insertTail(dummy, 10);
    insertTail(dummy, 20);
    insertTail(dummy, 30);

    printList(dummy);

    freeList(dummy);
    return 0;
}
