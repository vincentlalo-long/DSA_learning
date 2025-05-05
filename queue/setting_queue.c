Cần có 2 chỉ số
• Chỉ số phần tử đầu Queue hiện tại 
• Chỉ số phần tử cuối Queue hiện tại
Khởi tạo: chỉ số là -1
Queue rỗng -> front = rear
//Code C :
#include <stdio.h>
#include <conio.h>

#define MAX 10  // Kích thước tối đa của queue

// Hàm kiểm tra queue có rỗng không
int isEmpty(int queue[], int front, int rear) {
    if (rear == front)
        return 1;  // Rỗng
    else
        return 0;  // Không rỗng
}

// Hàm thêm phần tử vào cuối queue
int enQueue(int queue[], int *rear, int value) {
    if (*rear < MAX - 1) {
        *rear = *rear + 1;          // Tăng rear
        queue[*rear] = value;       // Gán giá trị mới
        return 0;                   // Thành công
    } else {
        printf("Queue đã đầy!\n");  // Quá giới hạn mảng
        return -1;
    }
}

// Hàm lấy phần tử đầu tiên ra khỏi queue
int deQueue(int queue[], int *front, int rear, int *value) {
    if (*front == rear) {
        printf("Queue rỗng!\n");
        return -1;  // Không có phần tử nào để lấy
    }
    *front = *front + 1;     // Tăng front để trỏ đến phần tử kế
    *value = queue[*front];  // Lấy giá trị ra
    return 0;
}

// Hàm trả về phần tử đầu hàng đợi mà không xóa
int Front(int queue[], int front, int rear, int *value) {
    if (front == rear) {
        printf("Queue rỗng!\n");
        return -1;
    }
    *value = queue[front + 1];  // Giá trị ở đầu hàng đợi là ở front + 1
    return 0;
}

// === Hàm main: kiểm tra các thao tác queue ===
int main() {
    int queue[MAX];     // Mảng dùng làm hàng đợi
    int front, rear;    // Con trỏ chỉ vị trí đầu và cuối
    int value;          // Biến trung gian để lấy giá trị

    front = rear = -1;  // Khởi tạo hàng đợi rỗng

    // Thêm phần tử 10 vào queue
    enQueue(queue, &rear, 10);

    // Kiểm tra queue có rỗng không
    if (isEmpty(queue, front, rear) == 1) {
        printf("Queue đang rỗng!\n");
    } else {
        // Lấy phần tử đầu mà không xóa
        if (Front(queue, front, rear, &value) == 0) {
            printf("Phần tử đầu queue: %d\n", value);
        }
    }

    getch();  // Chờ người dùng nhấn phím
    return 0;
}
