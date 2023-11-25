#include<stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num >= 1 ) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char roman[][3] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; num > 0; i++) {
        while (num >= values[i]) {
            printf("%s", roman[i]);
            num -= values[i];
        }
    }
  }
  return 0;
}