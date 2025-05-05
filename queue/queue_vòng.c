Làm thế nào để phân biệt được hàng đợi đầy và hàng đợi rỗng?
• Chỉ số front = rear trong cả 2 trường hợp • Dùng 1 phần tử làm chốt • Mảng MAX phần tử, chỉ dùng đến MAX-1
• 1 phần tử làm chốt để tránh rơi vào trường hợp front=rear khi đầy
• Tiện dùng, tuy nhiên lãng phí bộ nhớ cho 1 phần tử
• Cải tiến đơn giản hơn?
• Dùng 1 biến đếm số lượng phần tử hiện có trong Hàng đợi • Chỉ tốn 4 Byte cho biến int
#include <stdio.h>
#define MAX 5

// Định nghĩa cấu trúc hàng đợi vòng
typedef struct {
    int data[MAX];    // Mảng lưu trữ các phần tử của queue
    int front, rear;  // Chỉ số phần tử đầu và cuối của hàng đợi
} CircularQueue;

// Hàm khởi tạo hàng đợi
void init(CircularQueue* q) {
    q->front = q->rear = -1; // Ban đầu hàng đợi rỗng
}

// Kiểm tra hàng đợi có rỗng không
int isEmpty(CircularQueue* q) {
    return q->front == -1; // Khi front = -1 thì queue rỗng
}

// Kiểm tra hàng đợi có đầy không
int isFull(CircularQueue* q) {
    // Nếu rear tiến một bước sẽ trùng với front thì hàng đợi đầy
    return (q->rear + 1) % MAX == q->front;
}

// Hàm thêm phần tử vào queue
void enqueue(CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue đầy, không thể thêm!\n");
        return;
    }

    if (isEmpty(q)) {
        // Nếu queue rỗng, gán front và rear đều là 0
        q->front = q->rear = 0;
    } else {
        // Nếu không rỗng, tăng rear (vòng nếu cần)
        q->rear = (q->rear + 1) % MAX;
    }

    // Gán giá trị vào vị trí rear
    q->data[q->rear] = value;
}

// Hàm lấy phần tử khỏi queue
int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue rỗng, không thể lấy phần tử!\n");
        return -1;
    }

    // Lưu lại giá trị cần lấy
    int value = q->data[q->front];

    if (q->front == q->rear) {
        // Nếu chỉ còn một phần tử, sau khi lấy ra thì queue rỗng
        q->front = q->rear = -1;
    } else {
        // Tăng front theo kiểu vòng
        q->front = (q->front + 1) % MAX;
    }

    return value;
}

// Hàm in toàn bộ queue
void printQueue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue rỗng!\n");
        return;
    }

    printf("Queue hiện tại: ");
    int i = q->front;

    // In từ front đến rear theo vòng
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;  // Dừng khi đã in đến phần tử cuối
        i = (i + 1) % MAX;        // Tăng chỉ số theo vòng
    }
    printf("\n");
}

// Chương trình chính
int main() {
    CircularQueue q;
    init(&q);  // Khởi tạo hàng đợi

    // Thêm phần tử vào hàng đợi
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printQueue(&q);  // In queue sau khi thêm 4 phần tử

    // Lấy 2 phần tử ra khỏi hàng đợi
    printf("Lấy ra: %d\n", dequeue(&q));
    printf("Lấy ra: %d\n", dequeue(&q));

    printQueue(&q);  // In queue sau khi lấy ra

    // Thêm thêm phần tử
    enqueue(&q, 5);
    enqueue(&q, 6);

    printQueue(&q);  // In queue sau khi thêm

    // Thử thêm phần tử khi đầy
    enqueue(&q, 7);  // Sẽ báo đầy

    return 0;
}
