// Bài toán selection sort : 
//COde C:

#include <stdio.h>
#define MIN(a,b) (a<b)?a:b
void swap(int *a,int*b){ // Hàm hoán đổi 2 phần tử 
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int arr_size,int*a){ 
    for(int i=0;i<arr_size-1;i++){ // ta xét vòng lặp từ 0 đến arr_size-1
        int min=i; // tức là ta sẽ cài cái số chưa xét gặp sớm nhất là a[i] ( chưa xét ) 
        for(int j=i+1;j<arr_size;j++){ // xét các số còn lại để gán min
            if(a[j]<a[min]) min=j;
            swap(&a[i],&a[min]); // đổi số chưa xét với số min
        }
    }
}
int main() {
	// your code goes here'
	int n;
	scanf("%d",&n);
	int a[100];
	for(int  i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	selection_sort(n,a);
	for(int i=0;i<n;i++){
	    printf("%d ",a[i]);
	}

}

