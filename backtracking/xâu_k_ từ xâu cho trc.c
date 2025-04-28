//• Bài 2. In ra các xâu độ dài k với các ký tự lấy ra từ xâu “ABCDEFGH”
// Bài này nếu mà chuỗi nhập vào là phân biệt thì code sẽ khá đơn giản : 
// COde C /C++: 


#include <stdio.h>
#include <string.h>

void generate_string(char *str, int k, int idx, char *temp) {
    // Nếu độ dài xâu đã đủ k thì in xâu ra
    if (idx == k) {
        temp[k] = '\0'; // Đảm bảo kết thúc xâu đúng cách
        printf("%s\n", temp);
        return;
    }
    int len=strlen(str);
    // Lặp qua các ký tự từ "đầu" đến "cuối" để xây dựng các xâu
    for (int i = 0; i < len; i++) {  
        temp[idx] = str[i];  // Chọn ký tự tại vị trí i
        generate_string(str, k, idx + 1, temp);  // Đệ quy với chỉ số tiếp theo
    }
}

int main() {
    // Nhập vào chuỗi
    char str[1000];
    scanf("%999s",str);
    int k;  // Độ dài xâu cần tìm
    scanf("%d", &k);

    char temp[k + 1];  // Mảng tạm để lưu xâu kết quả, cần +1 để chứa ký tự kết thúc '\0'

    // Gọi hàm để sinh các xâu độ dài k
    generate_string(str, k, 0, temp);

    return 0;
} 
