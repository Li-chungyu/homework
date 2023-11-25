#include <stdio.h>
#include <stdlib.h>

int prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (prime(num1) && !prime(num2)) {
        return -1;
    } else if (!prime(num1) && prime(num2)) {
        return 1;
    } else if (prime(num1) && prime(num2)) {
        return (num2 - num1);
    } else {
        return (num1 - num2);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int numbers[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    qsort(numbers, N, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
