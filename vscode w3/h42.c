#include <stdio.h>

int main() {
    int number;
    scanf("%d", &number);


    int thousands = (number / 1000) % 10;
    int hundreds = (number / 100) % 10;
    int tens = (number / 10) % 10;
    int ones = number % 10;

  
    if (thousands == 4 || hundreds == 4 || tens == 4 || ones == 4) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}