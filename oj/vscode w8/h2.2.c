#include <stdio.h>

// 遞迴函數
int CanReachEnd(int n , int maze[n][n] , int x, int y) {
    // 超出邊界或遇到牆壁
    if (x < 0 || x>= n || y < 0 || y >= n || maze[x][y] == 1) {
        return 0;
    }

    // 抵達終點
    if (x == n - 1 && y == n - 1) {
        return 1; 
    }

    // 標記此位置已走過
    maze[x][y] = 1;

    // 向上、向下、向左、向右
    if (CanReachEnd(n, maze, x - 1, y) || CanReachEnd(n, maze, x + 1, y) ||
        CanReachEnd(n, maze, x, y - 1) || CanReachEnd(n, maze, x, y + 1)) {
        return 1;
    }

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int maze[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    if (CanReachEnd(n, maze, 0, 0)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

