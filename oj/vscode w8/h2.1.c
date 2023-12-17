#include <stdio.h>

#define MAX_SIZE 100

// 定義堆疊結構
typedef struct {
    int x;
    int y;
} StackItem;

// 函數聲明
int canReachEnd(int maze[MAX_SIZE][MAX_SIZE], int n);

int main() {
    int n;
    scanf("%d", &n);

    // 讀取迷宫
    int maze[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // 判斷是否能從起點到終點
    if (canReachEnd(maze, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// 判斷是否能從起點到终點的疊代函数
int canReachEnd(int maze[MAX_SIZE][MAX_SIZE], int n) {
    // 定義堆疊
    StackItem stack[MAX_SIZE * MAX_SIZE];
    int top = -1;  // 疊頂指针

    // 初始位置入疊
    stack[++top].x = 0;
    stack[top].y = 0;

    while (top >= 0) {
        int x = stack[top].x;
        int y = stack[top].y;
        top--;

        // 到達終點
        if (x == n - 1 && y == n - 1) {
            return 1;
        }

        // 標記當前位置已經訪問過
        maze[x][y] = 1;

        // 向上、向下、向左、向右移動，將可移動的位置入疊
        if (x - 1 >= 0 && maze[x - 1][y] == 0) {
            stack[++top].x = x - 1;
            stack[top].y = y;
        }
        if (x + 1 < n && maze[x + 1][y] == 0) {
            stack[++top].x = x + 1;
            stack[top].y = y;
        }
        if (y - 1 >= 0 && maze[x][y - 1] == 0) {
            stack[++top].x = x;
            stack[top].y = y - 1;
        }
        if (y + 1 < n && maze[x][y + 1] == 0) {
            stack[++top].x = x;
            stack[top].y = y + 1;
        }
    }

    return 0;
}