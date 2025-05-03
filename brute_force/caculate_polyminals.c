// Bài toán tính giá trị đa thức của P(x) theo 2 thuật toán 
// Thuật toán O(n^2)
#include <stdio.h>
#define MIN(a,b) (a<b)?a:b
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int cacupoly(int poly_size,int *a,int x){ // có thể dùng void thì thêm biến Poly vào 
    int P=0;
    for(int i=poly_size-1;i>=0;i--){
        int power=1;
        for(int j=0;j<i;j++){
            power=power*x;
        }
        P+=a[i]*power;
    }
    return P;
}
int main() {
	// your code goes here'
	int n;
	scanf("%d",&n);
	int a[100];
	for(int  i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	int x;
	scanf("%d",&x);
	int P=cacupoly(n,a,x);
	printf("%d",P);

}

//Thuật toán O(n)
int cacupoly(int poly_size,int *a,int x){ // có thể dùng void thì thêm biến Poly vào 
    int P=a[poly_size-1];
    for(int i=poly_size-2;i>=0;i--){
        P=P*x+a[i];
    }
    return P;
