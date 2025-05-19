//• VD2. Thuật toán tìm kiếm nhị phân
//Cho dãy n phần tử là khóa đã được sắp theo thứ tự tăng dần, và 1 giá trị khóa k.
//Hãy tìm xem k có xuất hiện trong dãy ban đầu hay không
// Cách 1 : vòng lặp 
#include <stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int binary_search(int*a,int n,int key){
    int start=0,end=n-1,mid;
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]==key) return mid;
        else if(a[mid]<key) start=mid+1;
        else end=mid-1;
        
    }
    return -1;
}
int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	int key;
	scanf("%d",&key);
	qsort(a,n,sizeof(int),compare);
    int res=binary_search(a,n,key);
    printf("%d",res);
}


#include <stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int binary_search(int *a,int key,int start,int end){
    if(start>end) return -1;
    int mid=(start+end)/2; // int mid = start + (end - start) / 2;   phòng tránh tràn số
    if(a[mid]==key) return mid;
    if(a[mid]>key) return binary_search(a,key,start,mid-1);
    else return binary_search(a,key,mid+1,end);
}
int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	int key;
	scanf("%d",&key);
	qsort(a,n,sizeof(int),compare);
    int res=binary_search(a,key,0,n-1);
    printf("%d",res);
}

