//Đề bài : Bài toán tìm đường đi trong mê cung
//Mê cung có thể biểu diễn thành ma trận nhị phân
//Tường sẽ là bit 0, điểm bắt đầu [0,0], kết thúc [N-1,M-1]
//COde C:
//Thử bổ sung : In L,R,D,U : 

#include <stdio.h>
#include <stdbool.h> // thêm vào vì dùng bool

void printSolution(int N, int sol[][N]) { // Hàm trả về mê cung đi ( tức là đường đi của ta đi ) 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n"); // in xong 1 dòng thì xuống dòng
    }
    printf("\n");
}

bool isSafe(int N,int maze[][N], int x, int y) { 
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
        return true;
    else 
        return false;
}

bool solveMazeUtil(int N, int maze[][N], int x, int y, int sol[][N]) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(N,maze, x, y) == true) {
        if (sol[x][y] == 1) return false;

        sol[x][y] = 1; // mark x, y as part of solution path

        if (solveMazeUtil(N, maze, x + 1, y, sol) == true) return true; // xuống
        if (solveMazeUtil(N, maze, x, y + 1, sol) == true) return true; // phải
        if (solveMazeUtil(N, maze, x - 1, y, sol) == true) return true; // lên
        if (solveMazeUtil(N, maze, x, y - 1, sol) == true) return true; // trái

        sol[x][y] = 0; // backtracking
        return false;
    }
    return false;
}

int main() {
    int N;
    scanf("%d", &N);

    int maze[N][N];
    int sol[N][N];

    // nhập maze
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
            sol[i][j] = 0; // khởi tạo sol toàn 0
        }
    }

    if (solveMazeUtil(N, maze, 0, 0, sol) == true) {
        printSolution(N, sol); // Sẽ trả về bảng đường đi
    } else {
        printf("No solution exists\n");
    }

    return 0;
}

//Code 2 : thêm phần in ra các hướng đi : 
#include <stdio.h>
#include <stdbool.h>

void printSolution(int N, int sol[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int N, int maze[][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(int N, int maze[][N], int x, int y, int sol[][N], char path[], int step) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        printSolution(N, sol);

        // In ra đường đi D R L U
        for (int i = 0; i < step; i++) {
            printf("%c", path[i]);
        }
        printf("\n");

        return true;
    }

    if (isSafe(N, maze, x, y)) {
        if (sol[x][y] == 1)
            return false; // ô này đã đi qua

        sol[x][y] = 1; // đánh dấu đã đi

        // đi xuống (D)
        path[step] = 'D';
        if (solveMazeUtil(N, maze, x + 1, y, sol, path, step + 1))
            return true; // thành công -> return ngay -> không chạy tiếp


        // đi phải (R)
        path[step] = 'R'; // Dòng này sẽ không tới được nữa nếu ở trên return true
        if (solveMazeUtil(N, maze, x, y + 1, sol, path, step + 1))
            return true;

        // đi lên (U)
        path[step] = 'U';
        if (solveMazeUtil(N, maze, x - 1, y, sol, path, step + 1))
            return true;

        // đi trái (L)
        path[step] = 'L';
        if (solveMazeUtil(N, maze, x, y - 1, sol, path, step + 1))
            return true;

        sol[x][y] = 0; // backtrack
        return false;
    }

    return false;
}

int main() {
    int N;
    scanf("%d", &N);

    int maze[N][N];
    int sol[N][N];
    char path[1000]; // lưu các bước đi (D, R, U, L)

    // nhập maze
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &maze[i][j]);
            sol[i][j] = 0;
        }
    }

    if (solveMazeUtil(N, maze, 0, 0, sol, path, 0)) {
        // đã in trong solveMazeUtil
    } else {
        printf("No solution exists\n");
    }

    return 0;
}

