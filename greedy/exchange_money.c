Ví dụ 1. Bài toán đổi tiền
• Giả sử bạn có các tờ tiền mệnh giá 1, 2, 5 và 10 đơn vị, và
• Cần đổi cho số tiền là 18
• Hãy đưa ra cách đổi tiền sao cho phải sử dùng ít tờ tiền nhất có thể
Thuật toán tham lam: dùng các tờ tiền có mệnh giá cao nhất trước
18 = 10 + 5 + 2 + 1 (tổng 4 tờ)
Nhưng nếu các tờ tiền chỉ có mệnh giá 10, 7 và 1
16 = 10 + 1 + 1 + 1 + 1 + 1 + 1 = 7 tờ
Trong khi phương án tối ưu là 7 + 7 + 1 + 1 = 4 tờ

// Ta chỉ có thể tham lam ở các bài toán mà mệnh giá tiền là hệ chuẩn : 
 - ví dụ hệ chuẩn ở việt nam : 500,200,100,50,20,10,5,2,1 
 - Ở MỸ : 1,5,10,25,50,100 
  // khi đó ta sẽ greedy theo kiểu lấy tờ tiền to nhất trước 
  // COde C :
  void greedy_coin_change(int coins[], int n, int amount) {
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            printf("%d ", coins[i]);
        }
    }
}
