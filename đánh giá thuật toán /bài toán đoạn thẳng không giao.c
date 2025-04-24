"""Bài toán các đoạn thẳng không giao nhau
Đưa ra phương án chọn lịch xem phim
• Đầu vào: Một tập L gồm thời gian chiếu trong ngày của n bộ phim
• Đầu ra: Tập con của L chứa số bộ phim lớn nhất có thể xem (không được
chồng nhau về thời gian)
Thuật toán 4. Thuật toán tối ưu:
• sắp xếp các lịch chiếu phim theo thứ tự không giảm thời gian kết thúc.
• Lần lượt xem xét các phim trong danh sách đã sắp xếp, bổ sung vào danh sách
xem bộ phim đang xét nếu nó không trùng với các bộ phim đã có trong danh
sách xem."""
//Code C/C++:
#include <stdio.h>
#include<stdlib.h>
typedef struct{ //tạo hàm struct để định nghĩa ra cặp start-end
    double start;
    double end;
}Movie;
int compare(const void *a,const void *b){
    Movie *movieA = (Movie*)a;  // Ép kiểu a từ void* thành Movie*
    Movie *movieB = (Movie*)b;  // Ép kiểu b từ void* thành Movie*

    return movieA->end - movieB->end;
}
int main() {
	// your code goes here
	int n;
	int res=1;
	scanf("%d",&n);
	if(n==0) return 0;
	Movie movies[n];
	for(int i=0;i<n;i++){
	    scanf("%lf %lf",&movies[i].start,&movies[i].end);
	}
	qsort(movies,n,sizeof(Movie),compare);
	double last_end=movies[0].end;
	for(int i=1;i<n;i++){
	    if(movies[i].start>=last_end){
	        res++;
	        last_end=movies[i].end;
	    }
	}
	printf("%d",res);
	

}

