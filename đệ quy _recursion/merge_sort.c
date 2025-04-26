// Thuật toán sắp xếp trộn – MergeSort
// COde C : 
#include <stdio.h>
void merge(int *a,int start,int mid,int end){
    int n1=mid-start+1; // n1 là dãy mảng gồm nửa đầu đến mid
    int n2=end-mid; // n2 là mảng còn lại
     // 2 mảng để mình lưu ví dụ L=[2 , 5 , 8] R=[1,4,7]
    // thì ý tưởng là xert lần lượt là L[0]=2>R[0]=1 nên ta sẽ chọn a[0]=1;
    // tiếp là ta sẽ xét L[0]=2 <R[1]=4 -> chọn a[1]
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)  L[i] = a[start + i];
    for (int i = 0; i < n2; i++)  R[i] = a[mid + 1 + i];
    int i=0,j=0,k=start;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++]; // Trường hợp vòng lặp kia end
    while(i<n2) a[k++]=R[i++];
}
void merge_sort(int *a , int start , int end){
    int mid=start+(end-start)/2;
    if(start>=end) return ;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
}
int main() {
	// your code goes here
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

