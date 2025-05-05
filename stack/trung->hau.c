chương trình minh họa chuyển biểu thức dạng trung tố sang
dạng hậu tố
• Biểu thức chỉ gồm: • Toán tử: +, −,∗,/, %, ^
• Toán hạng: 1 ký tự
vd. a, b, c, 3, 4, 6,… • Dấu ngoặc: ( , và )
• Ví dụ:
3 + ହ
ଷ + (1 − 𝑎/𝑏^2) hay 3 + 5/3 + (1 −𝑎/𝑏^2)
//Code C :
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Hàm kiểm tra một ký tự có phải là toán tử không
int isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '%' || op == '/' || op == '^');
}

// Hàm xác định độ ưu tiên của toán tử
int priority(char op) {
    if (op == '+' || op == '-') return 4;
    if (op == '*' || op == '%' || op == '/') return 5;
    if (op == '^') return 6;
    return 0; // Các ký tự khác không phải toán tử
}

// Cấu trúc node dùng cho stack (kiểu ký tự)
typedef struct node {
    char data;
    struct node *pNext;
} NODE;

// Hàm push: thêm phần tử vào stack
void push(NODE **top, char value) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = value;
    newNode->pNext = *top;
    *top = newNode;
}

// Hàm pop: lấy phần tử từ stack ra
char pop(NODE **top) {
    if (*top == NULL) return '\0'; // Stack rỗng
    NODE *temp = *top;
    char val = temp->data;
    *top = temp->pNext;
    free(temp);
    return val;
}

// Hàm lấy phần tử ở đỉnh stack nhưng không pop
char peek(NODE *top) {
    if (top == NULL) return '\0';
    return top->data;
}

// === Hàm chính: Chuyển biểu thức trung tố sang hậu tố ===
int main() {
    char eq[] = "(3+5*(7-6*5)+4)^5^6";  // Biểu thức trung tố cần chuyển
    char ch;
    
    // Bộ nhớ động để lưu biểu thức hậu tố
    char *retVal = (char *)calloc(strlen(eq) + 1, sizeof(char));

    NODE *top = NULL;  // Stack lưu toán tử
    int j = 0;         // Chỉ số cho retVal (biểu thức hậu tố)

    // Duyệt từng ký tự trong biểu thức trung tố
    for (int i = 0; i < strlen(eq); i++) {
        // Nếu là toán hạng (số hoặc biến), thêm trực tiếp vào hậu tố
        if (eq[i] != '(' && eq[i] != ')') {
            if (!isOperator(eq[i])) {
                retVal[j++] = eq[i];  // Ghi vào kết quả hậu tố
            } else {
                // Nếu là toán tử
                // Các điều kiện để push luôn lên stack:
                // - Stack rỗng
                // - Đỉnh stack là '('
                // - Toán tử là '^'
                // - Độ ưu tiên cao hơn đỉnh stack
                while (top != NULL &&
                       peek(top) != '(' &&
                       priority(eq[i]) <= priority(peek(top))) {
                    // Nếu ưu tiên nhỏ hơn hoặc bằng → pop từ stack ra hậu tố
                    retVal[j++] = pop(&top);
                }
                push(&top, eq[i]); // Push toán tử hiện tại vào stack
            }
        } else {
            // Nếu là dấu ngoặc
            if (eq[i] == '(') {
                push(&top, eq[i]); // Push '(' vào stack
            } else {
                // Nếu là ')': pop từ stack cho đến khi gặp '('
                ch = pop(&top);
                while (ch != '(' && ch != '\0') {
                    retVal[j++] = ch;
                    ch = pop(&top);
                }
                // '(' bị loại khỏi stack nhưng không ghi vào hậu tố
            }
        }
    }

    // Sau khi duyệt hết, lấy các toán tử còn lại trong stack ra
    while (top != NULL) {
        retVal[j++] = pop(&top);
    }

    retVal[j] = '\0'; // Kết thúc chuỗi hậu tố

    // In kết quả hậu tố
    printf("\n\nBiểu thức hậu tố là: %s\n", retVal);

    getch();
    return 0;
}
