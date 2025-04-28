// SInh ra nhị phân mà 2 số 1 ko cạnh nhau
#include <stdio.h>
void printsol(int n,int *x){ // hoặc là x[]
    for(int i=0;i<n;i++){
        printf("%d",x[i]); // in bit thứ i
    }
    printf("\n");
}
void generate(int *x,int k,int n){
    for(int i=0;i<=1;i++){
        if(k>0 && i+x[k-1]==2) continue; // thêm điều kiện ktra 
        x[k]=i;
        if(k==n-1) printsol(n,x);
        else generate(x,k+1,n);
        }
        
    }

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int x[n];
	generate(x,0,n);

}



