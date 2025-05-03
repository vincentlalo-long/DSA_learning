Bài toán phân số Ai Cập - Egyptian Fraction
• Đầu vào là 1 số dạng a/b (trong đó a<b)
• Tìm cách biểu diễn lại a/b dưới dạng 1/c + 1/d + 1/e +..+1/z với số lượng phân số này là
nhỏ nhất
• VD. 2/3 = 1/2 + 1/6, hoặc 12/13 = 1/2 + 1/3 + 1/12 + 1/156

  // code C ( greedy) : 
  
#include <stdio.h>

void egypt(int a, int b) {
    while (a != 0) {
        int x = (b + a - 1) / a;  // tương đương ceil(b/a) mà không dùng double
        printf("1/%d ", x);
        
        // cập nhật a/b = a/b - 1/x
        a = a * x - b;
        b = b * x;
        
        // rút gọn phân số
        int gcd = __gcd(a, b);
        a /= gcd;
        b /= gcd;
    }
}

// Cài đặt GCD nếu bạn dùng trình biên dịch không hỗ trợ __gcd
int __gcd(int a, int b) {
    if (b == 0) return a;
    return __gcd(b, a % b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    egypt(a, b);
    return 0;
}
