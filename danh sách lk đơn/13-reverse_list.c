/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* current=head;;
    struct ListNode* previous =NULL;
    struct ListNode* next=NULL;
    while(current !=NULL){ // ở vòng lặp lần đầu thì curren lúc này đang trỏ tới node A
    // với ta đang xét là A-B-C-D-E-NULL ( ví dụ)
        next=current->next ;// next lúc này đang trỏ tới next của node current , đoạn đầu thì nó là B
        current->next=previous; //lúc này tức là A->next =previous ( lúc đầu là NULL)
        previous=current;//cập nhật lại previous bằng current đang xét 
        current=next; // cập nhật current = node tiếp theo cần đảo ngược 

    }
    return previous; // trả về con trỏ trỏ tới node đầu của danh sách sau khi đảo ngược
}
