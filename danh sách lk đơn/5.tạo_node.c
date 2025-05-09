structNode{
  intdata;
  structNode *next;
};

// Hàm tạo một nút mới
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  
  if (!newNode) {
   printf("Lỗi cấp phát bộ nhớ!\n");
   return NULL;
 }
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}
