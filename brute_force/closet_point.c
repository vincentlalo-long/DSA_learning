// Bài toán tìm cặp điểm gần nhau nhất 

#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct {
    double x;
    double y;
} Point;

double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void closest_pair(Point P[], int n, double *min_dist, Point *p1, Point *p2) {
    *min_dist = DBL_MAX;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double d = distance(P[i], P[j]);
            if (d < *min_dist) {
                *min_dist = d;
                *p1 = P[i];
                *p2 = P[j];
            }
        }
    }
}

int main() {
    int n;
    printf("Nhap so diem: ");
    scanf("%d", &n);
    Point P[100];

    printf("Nhap toa do cac diem (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &P[i].x, &P[i].y);
    }

    double min_dist;
    Point p1, p2;
    closest_pair(P, n, &min_dist, &p1, &p2);

    printf("Cap diem gan nhau nhat: (%.2lf, %.2lf) va (%.2lf, %.2lf)\n", p1.x, p1.y, p2.x, p2.y);
    printf("Khoang cach: %.6lf\n", min_dist);

    return 0;
}
