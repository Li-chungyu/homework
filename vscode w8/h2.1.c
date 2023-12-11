#include <stdio.h>

#define MAX_SIZE 100

// 定义堆栈结构
typedef struct {
    int x;
    int y;
} StackItem;

// 函数声明
int canReachEnd(int maze[MAX_SIZE][MAX_SIZE], int n);

int main() {
    int n;
    scanf("%d", &n);

    // 读取迷宫
    int maze[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // 判断是否能从起点到终点
    if (canReachEnd(maze, n)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// 判断是否能从起点到终点的迭代函数
int canReachEnd(int maze[MAX_SIZE][MAX_SIZE], int n) {
    // 定义堆栈
    StackItem stack[MAX_SIZE * MAX_SIZE];
    int top = -1;  // 栈顶指针

    // 初始位置入栈
    stack[++top].x = 0;
    stack[top].y = 0;

    while (top >= 0) {
        int x = stack[top].x;
        int y = stack[top].y;
        top--;

        // 到达终点
        if (x == n - 1 && y == n - 1) {
            return 1;
        }

        // 标记当前位置已经访问过
        maze[x][y] = 1;

        // 尝试向上、向下、向左、向右移动，将可移动的位置入栈
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