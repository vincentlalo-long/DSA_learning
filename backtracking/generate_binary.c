//Bài toán : Nhập vào n và in ra tất cả các xâu nhị phân độ dài n :
//Code C/C++ :

#include <stdio.h>
void printsol(int n,int *x){ // hoặc là x[]
    for(int i=0;i<n;i++){
        printf("%d",x[i]); // in bit thứ i
    }
    printf("\n");
}
void generate(int *x,int k,int n){
    for(int i=0;i<=1;i++){
        x[k]=i ; // chia làm 2 vòng lặp để xét 2 TH x[k]=0 hoặc =1 
        if(k==n-1) printsol(n,x); // Nếu k=n-1 tức là đã xét đến cuối cùng và in ra dãy nhị phân
        else generate(x,k+1,n); // Quay lại để xử lí K+1
        }
        
    }

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int x[n];
	generate(x,0,n);

}

