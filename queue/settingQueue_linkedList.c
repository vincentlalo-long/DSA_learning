#include <stdio.h>
#include <stdlib.h>
// Định nghĩa nút
typedef struct Node{
    int data;
    struct Node* next;
}Node;
// ĐỊnh nghĩa queue
typedef struct queue{
    Node* front;
    Node* rear;
}queue;
//Hàm khởi tạo queue
void init(queue* q){
    q->rear=NULL;
    q->front=NULL;
}
// Hàm kiểm tra queue rỗng 
int isEmpty(queue* q){
    return (q->front==NULL);
}
// Hàm In queue
void printQueue(queue* q) {
    Node* current = q->front;
    printf("Queue hien tai: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


// Hàm thêm phần tử vào queue :
void enqueue(queue* q,int value){
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(!newnode){
        printf("Khong du bo nho\n");
        return ;
    }
    newnode->data=value;
    newnode->next=NULL;
    if(q->rear==NULL){
        q->front=q->rear=newnode;
    }
    else{
        q->rear->next=newnode;
        q->rear=newnode;
    }
}
// Hàm xóa phần tử khỏi queue
int dequeue(queue* q){
    if(isEmpty(q)){
        printf("queue rong\n");
        return -1;
    }
    Node* temp=q->front;
    int value=temp->data;
    q->front=q->front->next;
    if (q->front == NULL) {
    // Nếu sau khi lấy ra mà queue
    // rỗng thì rear cũng phải NULL
        q->rear = NULL;
    }
    free(temp);
    return value;
}

int main() {
	// your code goes here
	queue q;
	init(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	enqueue(&q,5);
	printQueue(&q);
	printf("Lay ra %d\n",dequeue(&q));
	printQueue(&q);
	enqueue(&q,6);
	printQueue(&q);
}

// Output : 
Queue hien tai: 1 2 3 4 5 
Lay ra 1
Queue hien tai: 2 3 4 5 
Queue hien tai: 2 3 4 5 6 
