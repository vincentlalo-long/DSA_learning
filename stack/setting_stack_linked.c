#include <stdio.h>
#include<stdlib.h>
//Khởi tạo node của dslk
typedef struct Node{
    int data;
    struct Node* next;
}Node;
// Khởi tạo stack : 
typedef struct stack{
    Node* top;
}stack;
// Khởi tạo 1 staack rỗng : 
void init(stack*s){
    s->top=NULL;
}
// Hàm kiểm tra xem stack có rỗng :
int isEmpty(stack* s){
    return s->top==NULL;
}
//Push thêm phần tử vào đầu stack
void push(stack* s,int value){
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(!newnode){
        printf("Khong the cap phat\n");
        return;
    }
    newnode->data=value;
    newnode->next=s->top;
    s->top=newnode;
}
// Hàm pop : lấy ra phần tử đầu danh sách : 
void pop(stack* s,int* value){
    if(isEmpty(s)){
        printf("stack rong\n");
        return;
    }
    Node* temp=s->top;
    *value=temp->data;
    s->top=temp->next;
    free(temp);
    return 1;
}
//Hàm peek : lấy ra phần tử đầu mà không xóa
void peek(stack* s, int* value){
    if(isEmpty(s)){
        printf("stack rong\n");
        return;
    }
    *value=s->top->data;
    return 1;
}
void printStack(stack* s) {
    if (isEmpty(s)) {
        printf("Stack rong\n");
        return;
    }
    Node* current = s->top;
    printf("Stack (top -> bottom): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
	// your code goes here
    stack s;
    init(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    printStack(&s);
    int x;
    peek(&s,&x);
    printf("Phan tu tren cung la %d\n",x);
    while(!isEmpty(&s)){
        pop(&s,&x);
        printf("Lay ra phan tu x %d\n",x);
    }
    return 0;
    
}

// Output : 
Stack (top -> bottom): 5 4 3 2 1 
Phan tu tren cung la 5
Lay ra phan tu x 5
Lay ra phan tu x 4
Lay ra phan tu x 3
Lay ra phan tu x 2
Lay ra phan tu x 1
