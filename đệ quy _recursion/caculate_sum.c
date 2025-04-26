// Dùng đệ quy để giải bài taosn tính tổng của dãy số 
//Sẽ có 2 cách đệ quy : cách 1 là vòng lặp và cách 2 là dùng đệ quy
//Cách 1 : vòng lặp
#include <stdio.h>
#include <stdlib.h>
// Ta sẽ xét 1 bài toán tổng quát là số thực 
void caculate(int n, double a[],double *sum){// ta phải gọi con trỏ sum vì ta muốn thay đổi giá trị của sum 
    for(int i=0;i<n;i++){
        *sum+=a[i];
    }
}
int main(){
    int n;
    scanf("%d",&n);
    double a[n];
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    double res=0;
    caculate(n,a,&res); // tương tự ta phải gọi đến địa chỉ của res mà sum đang trỏ vào
    printf("%.1f",res);
    return 0;
}
// Cách 2 : gọi đệ quy 
#include <stdio.h>
#include <stdlib.h>
// Đây là đệ quy mà sử dụng hàm void , còn nếu mà là hàm int thì sẽ được đề cập bên dưới
void caculate(int n, double a[], double *sum) {
    if (n == 0) return; // hết mảng thì dừng
    *sum += a[n-1]; // cộng phần tử cuối
    caculate(n-1, a, sum); // đệ quy với phần còn lại
}

int main() {
    int n;
    scanf("%d", &n);
    double a[n];
    for(int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    double res = 0;
    caculate(n, a, &res); // truyền địa chỉ res vào
    printf("%.1f", res);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int caculate(int n,int a[]){ // hoặc là int *a đều giống nhau đều trỏ đến phần tử đầu tiên của mảng
    if(n<=0) return 0;
    return *(a+n-1)+caculate(n-1,a); // có thể ghi là a[n-1] vì nó tương tự nhau : cộng địa chỉ a với n-1, rồi trỏ tới và lấy giá trị.
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int res=caculate(n,a);
    printf("%d",res);
}

    
