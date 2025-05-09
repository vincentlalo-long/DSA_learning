void printList(struct Node* head)
{
  while (head != NULL) {
    printf(" %d ", head ->data);
    head = head ->next;
}
}
int size(Node* head)
{
  int count=0;
  while (head != NULL) {
    count++;
    head = head->next;
}
  return count;
}
