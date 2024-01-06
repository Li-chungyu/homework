#include <stdio.h>

void calculate(int list[10000], int n, int *count, int *list_length) {
    (*count)++;
    if ((*count) != n) {
        int temp_list[(*list_length) + 1];
        
        // 將list複製到 temp_list 中
        for (int i = 0; i < (*list_length); i++) {
            temp_list[i] = list[i];
        }
        temp_list[(*list_length)] = -1;

        int temp_count = 1;
        int read_temp = 0;
        int length_count = 0;

        // 計算後輸出
        for (int i = 0; i < (*list_length); i++) {
            if (temp_list[i] == temp_list[i + 1]) {
                temp_count++;
            } 
            else if (temp_list[i] != temp_list[i + 1]) {
                printf("%d%d", temp_count, temp_list[i]);
                read_temp += 2;
                list[read_temp - 2] = temp_count;
                list[read_temp - 1] = temp_list[i];
                length_count += 2;
                temp_count = 1;
            }
        }
        printf("\n");

        (*list_length) = length_count;

        // 遞迴生成下一項
        calculate(list, n, count, list_length);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    int list[100000] = {1};
    int list_length = 1;

    printf("1\n");
    calculate(list, n, &count, &list_length);
}