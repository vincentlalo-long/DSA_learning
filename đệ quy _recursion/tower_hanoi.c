//Bài toán di chuyển các ô từ cột A sang cột B với cột C làm trung gian 
void move(int n, char A, char B, char C)
{
 if (n == 1) {
 printf("Move 1 disk from %c to %c", A, B);
 }
 else {
 move(n - 1, A, C, B);
 move(1, A, B, C);
 move(n - 1, C, B, A);
 }
}
int main() {
 int n = 3;
 move(n, 'A', 'B', 'C’);
 return 0;
}
