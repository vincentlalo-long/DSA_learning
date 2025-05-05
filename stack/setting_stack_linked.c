#include <stdio.h>
#include <stdlib.h>

// Định nghĩa nút của stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Định nghĩa kiểu stack
typedef struct {
    Node* top;
} Stack;

// Khởi tạo stack rỗng
void init(Stack* s) {
    s->top = NULL;
}

// Kiểm tra stack rỗng
int isEmpty(Stack* s) {
    return s->top == NULL;
}

// Push: thêm phần tử vào đầu stack
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho!\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop: lấy phần tử đầu stack
int pop(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        return 0;
    }
    Node* temp = s->top;
    *value = temp->data;
    s->top = temp->next;
    free(temp);
    return 1;
}

// Peek: xem phần tử trên cùng mà không xóa
int peek(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("Stack rong!\n");
        return 0;
    }
    *value = s->top->data;
    return 1;
}

// Hàm main để kiểm tra
int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    int x;
    peek(&s, &x);
    printf("Phan tu tren cung: %d\n", x);

    while (!isEmpty(&s)) {
        pop(&s, &x);
        printf("Lay ra: %d\n", x);
    }

    return 0;
}
