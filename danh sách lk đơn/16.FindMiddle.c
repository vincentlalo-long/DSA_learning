// struct Node{
//     int data;
//     struct Node * next;
// };

typedef struct Node NODE;
NODE *getMiddleElement(NODE *head){
    // Write your code here
    int n=0;
    struct Node* current=head;
    while(current!=NULL){
        n++;
        current=current->next;
    }
    current=head;
    int middle=(n/2);
    for(int i=0;i<middle;i++){
        current=current->next;
    }
    return current; // O(n) do phải duyệt list để đếm
}

// Cách khác : slow fast
// struct Node{
//     int data;
//     struct Node * next;
// };

typedef struct Node NODE;
NODE *getMiddleElement(NODE *head){
    // Write your code here
    struct Node* slow=head;
    struct Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow; // chỉ O(n/2)
}

