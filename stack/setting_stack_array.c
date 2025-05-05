#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX]; // nơi lưu trữ dữ liệu 
    int top; // phần tử cuối cùng của stack 
} Stack;

// Khởi tạo stack
void init(Stack* s) {
    s->top = -1;
}

// Kiểm tra stack rỗng
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Kiểm tra stack đầy
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Thêm phần tử vào stack (push)
int push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack đầy! Không thể thêm phần tử.\n");
        return 0; // Push thất bại
    }
    s->arr[++(s->top)] = value;
    return 1; // Push thành công
}

// Lấy phần tử ra khỏi stack (pop)
int pop(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("Stack rỗng! Không thể lấy phần tử.\n");
        return 0; // Pop thất bại
    }
    *value = s->arr[(s->top)--];
    return 1; // Pop thành công
}

// Lấy phần tử đầu stack mà không xóa (peek)
int peek(Stack* s, int* value) {
    if (isEmpty(s)) {
        printf("Stack rỗng!\n");
        return 0;
    }
    *value = s->arr[s->top];
    return 1;
}

// Chương trình chính
int main() {
    Stack s;
    int x;

    init(&s); // Khởi tạo stack

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    if (peek(&s, &x))
        printf("Phần tử trên cùng: %d\n", x);

    while (!isEmpty(&s)) {
        if (pop(&s, &x))
            printf("Lấy ra: %d\n", x);
    }

    return 0;
}
