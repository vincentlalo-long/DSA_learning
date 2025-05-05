• Xây dựng chương trình tính giá trị của một một biểu thức hậu tố được lưu trong một
xâu ký tự. • Toán hạng:
các số nguyên không âm
• Toán tử : (xét các toán hạng 2 ngôi đơn giản)
+, -, *, /, %, ^ (lũy thừa)
//code C:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Định nghĩa cấu trúc một node trong stack (liên kết đơn)
typedef struct Node {
    int data;               // Dữ liệu là số nguyên
    struct Node *next;      // Con trỏ trỏ đến node kế tiếp
} NODE;

// Hàm push: thêm một phần tử vào đỉnh stack
void push(NODE **top, int value) {
    // Cấp phát bộ nhớ cho node mới
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = value;      // Gán dữ liệu cho node
    newNode->next = *top;       // Liên kết node mới với node hiện tại ở đỉnh
    *top = newNode;             // Cập nhật con trỏ đỉnh stack
}

// Hàm pop: lấy phần tử ra khỏi đỉnh stack
// Trả về 1 nếu thành công, 0 nếu stack rỗng
int pop(NODE **top, int *value) {
    if (*top == NULL) return 0; // Nếu stack rỗng, trả về lỗi
    NODE *temp = *top;          // Tạm lưu node đỉnh
    *value = temp->data;        // Lấy giá trị của node đỉnh
    *top = temp->next;          // Di chuyển con trỏ đỉnh xuống node tiếp theo
    free(temp);                 // Giải phóng bộ nhớ node cũ
    return 1;                   // Thành công
}

// Hàm kiểm tra một ký tự có phải là toán tử không
int isOperator(char op) {
    // Nếu là một trong các ký hiệu toán tử hợp lệ thì trả về 1
    return (op == '+' || op == '-' || op == '*' || op == '%' || op == '/' || op == '^');
}

// Hàm thực hiện phép tính giữa 2 toán hạng và một toán tử
int compute(int left, int right, char op) {
    int value;
    switch (op) {
        case '+': value = left + right; break;           // Phép cộng
        case '-': value = left - right; break;           // Phép trừ
        case '*': value = left * right; break;           // Phép nhân
        case '%': value = left % right; break;           // Phép chia lấy dư
        case '/': value = left / right; break;           // Phép chia nguyên
        case '^': value = pow(left, right); break;       // Lũy thừa
    }
    return value;
}

// Hàm chính
int main() {
    char eq[] = "21*56*3/+7-";  // Biểu thức hậu tố (postfix), chỉ dùng số 1 chữ số
    int left, right, expValue; // Biến lưu toán hạng trái, phải và kết quả trung gian
    NODE *top = NULL;          // Khởi tạo stack rỗng (dùng con trỏ top)

    // Duyệt từng ký tự trong biểu thức hậu tố
    for (int i = 0; i < strlen(eq); i++) {
        char ch = eq[i];       // Lấy ký tự hiện tại

        if (!isOperator(ch)) {
            // Nếu ký tự là chữ số → chuyển sang số nguyên (dùng -'0') rồi push vào stack
            push(&top, ch - '0');
        } else {
            // Nếu ký tự là toán tử → thực hiện phép tính
            pop(&top, &right);                // Lấy toán hạng phải từ stack
            pop(&top, &left);                 // Lấy toán hạng trái từ stack
            expValue = compute(left, right, ch); // Tính toán kết quả
            printf("%d %c %d = %d\n", left, ch, right, expValue); // In bước tính
            push(&top, expValue);             // Push kết quả trung gian vào lại stack
        }
    }

    // Sau vòng lặp, kết quả cuối cùng nằm trên đỉnh stack
    pop(&top, &expValue);
    printf("Ket qua cuoi cung: %d\n", expValue); // In kết quả cuối

    return 0;
}
