#include <stdio.h>
#include <stdlib.h>

// Định nghĩa node cho danh sách liên kết đơn
typedef struct Node {
    int data;              // Dữ liệu của node
    struct Node* next;     // Con trỏ đến node kế tiếp
} Node;

// Cấu trúc Queue với hai con trỏ: front (đầu) và rear (cuối)
typedef struct {
    Node* front;           // Trỏ đến phần tử đầu tiên
    Node* rear;            // Trỏ đến phần tử cuối cùng
} Queue;

// Hàm khởi tạo hàng đợi rỗng
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Hàm kiểm tra hàng đợi có rỗng không
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Hàm in toàn bộ phần tử trong queue từ front -> rear
void printQueue(Queue* q) {
    Node* current = q->front;
    printf("Queue hien tai: ");
    while (current != NULL) {
        printf("%d ", current->data); // In dữ liệu của từng node
        current = current->next;
    }
    printf("\n");
}

// Hàm thêm phần tử vào cuối queue (enqueue)
void enqueue(Queue* q, int value) {
    // Cấp phát bộ nhớ cho node mới
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Cap phat bo nho that bai!\n");
        return;
    }

    newNode->data = value;    // Gán giá trị cho node
    newNode->next = NULL;     // Node mới là cuối, nên next = NULL

    if (q->rear == NULL) {
        // Nếu queue đang rỗng, front và rear đều trỏ đến newNode
        q->front = q->rear = newNode;
    } else {
        // Nếu queue đã có phần tử, nối node mới vào cuối
        q->rear->next = newNode;
        q->rear = newNode; // Cập nhật lại rear
    }
}

// Hàm lấy phần tử khỏi đầu queue (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue rong!\n");
        return -1;
    }

    // Lưu node đầu để giải phóng sau
    Node* temp = q->front;
    int value = temp->data;

    // Di chuyển front sang phần tử kế tiếp
    q->front = q->front->next;

    // Nếu sau khi lấy ra mà queue rỗng thì cập nhật rear = NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp); // Giải phóng node cũ
    return value;
}

// Hàm chính: chạy thử các thao tác của hàng đợi
int main() {
    Queue q;
    initQueue(&q); // Khởi tạo queue rỗng

    enqueue(&q, 10);  // Queue: 10
    enqueue(&q, 20);  // Queue: 10 20
    enqueue(&q, 30);  // Queue: 10 20 30

    printQueue(&q);   // Output: Queue hien tai: 10 20 30

    printf("Lay ra: %d\n", dequeue(&q));  // Lấy phần tử 10 ra
    // Output: Lay ra: 10

    printQueue(&q);   // Output: Queue hien tai: 20 30

    enqueue(&q, 40);  // Queue: 20 30 40

    printQueue(&q);   // Output: Queue hien tai: 20 30 40

    return 0;
}
