//Bài toán phân chia công việc theo 2 tiêu chí : kịp deadline và tổng profit max 
//THuật toán 1 : greedy theo các profit max : khi ta xét ta sẽ nhét nó vào slot trống , tương tự thế
//T(n)=O(n^2)
#include <stdio.h>
#include<stdlib.h>

typedef struct {
    int profit;
    int deadline;
} Job;

// Hàm so sánh để sắp xếp theo lợi nhuận giảm dần
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit; // Sắp xếp theo profit giảm dần
}

void job_sequence(int *deadline,int *profits,int n){
    Job jobs[n];
    for(int i=0;i<n;i++){
        jobs[i].profit=profits[i];
        jobs[i].deadline=deadline[i];
    }
    qsort(jobs,n,sizeof(Job),compare); // sắp xếp profit giảm dần
    // Mảng để theo dõi slot (thời gian) đã được sử dụng
    int slot[n];
    for (int i = 0; i < n; i++) {
        slot[i] = 0;
    }

    int cnt = 0;        // Số công việc đã hoàn thành
    int totProfit = 0;  // Tổng lợi nhuận

    // Duyệt qua các công việc và gán chúng vào các slot trống
    for (int i = 0; i < n; i++) {
        int start = (jobs[i].deadline < n) ? jobs[i].deadline - 1 : n - 1;
        // Tìm slot trống từ deadline đến slot đầu tiên
        for (int j = start; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;    // Đánh dấu slot đã được sử dụng
                cnt++;           // Tăng số công việc hoàn thành
                totProfit += jobs[i].profit; // Cộng lợi nhuận
                break;
            }
        }
    }

    // In kết quả
    printf("%d %d\n", cnt, totProfit);
}

int main() {
    // Dữ liệu đầu vào
    int deadline[] = {2, 1, 2, 1, 1};
    int profit[] = {100, 19, 27, 25, 15};
    int n = sizeof(deadline) / sizeof(deadline[0]);

    // Gọi hàm jobSequencing
    job_sequence(deadline, profit, n);
    
    return 0;
}

// THuật toán 2 : sử dụng sort theo deadline tăng dần và sử dụng min heap để lưu trữ (min heap cho phép ta truy cập đến phần tử nhó nhất , lớn nhất dễ dàng ) 
//T(n)=O(nlogn) 
// Upcoming
