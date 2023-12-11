#include <stdio.h>

// 函數用於判斷遊戲結果
char checkWinner(char board[19][20]) {
    // 檢查水平、垂直和對角線是否有五子連線

    // 檢查水平
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j <= 14; ++j) {
            if (board[i][j] != '_' &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3] &&
                board[i][j] == board[i][j + 4]) {
                return board[i][j];
            }
        }
    }

    // 檢查垂直
    for (int i = 0; i <= 14; ++i) {
        for (int j = 0; j < 19; ++j) {
            if (board[i][j] != '_' &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j] &&
                board[i][j] == board[i + 4][j]) {
                return board[i][j];
            }
        }
    }

    // 檢查主對角線
    for (int i = 0; i <= 14; ++i) {
        for (int j = 0; j <= 14; ++j) {
            if (board[i][j] != '_' &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3] &&
                board[i][j] == board[i + 4][j + 4]) {
                return board[i][j];
            }
        }
    }

    // 檢查次對角線
    for (int i = 4; i < 19; ++i) {
        for (int j = 0; j <= 14; ++j) {
            if (board[i][j] != '_' &&
                board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] &&
                board[i][j] == board[i - 3][j + 3] &&
                board[i][j] == board[i - 4][j + 4]) {
                return board[i][j];
            }
        }
    }

    // 如果沒有玩家獲勝，返回 'N'
    return 'N';
}

int main() {
    char board[19][20]; // 棋盤，包含19行每行20個字符（包括換行符）

    // 讀取棋盤
    for (int i = 0; i < 19; ++i) {
        scanf("%s", board[i]);
    }

    // 判斷遊戲結果
    char winner = checkWinner(board);

    // 輸出結果
    if (winner == 'O') {
        printf("White\n");
    } else if (winner == 'X') {
        printf("Black\n");
    } else {
        printf("No winner\n");
    }

    return 0;
}