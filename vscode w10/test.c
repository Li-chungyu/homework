#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char integer[MAX_LENGTH];
    char decimal[MAX_LENGTH];
} DeciVar;

void addDecimals(const DeciVar *num1, const DeciVar *num2, DeciVar *result) {
    int carry = 0;

    // Add decimal parts
    for (int i = MAX_LENGTH - 1; i >= 0; i--) {
        int digitSum = (num1->decimal[i] - '0') + (num2->decimal[i] - '0') + carry;
        result->decimal[i] = (digitSum % 10) + '0';
        carry = digitSum / 10;
    }

    // Add integer parts
    for (int i = MAX_LENGTH - 1; i >= 0; i--) {
        int digitSum = (num1->integer[i] - '0') + (num2->integer[i] - '0') + carry;
        result->integer[i] = (digitSum % 10) + '0';
        carry = digitSum / 10;
    }
}

int main() {
    DeciVar num1, num2, result;

    // Input
    printf("Enter the first decimal value: ");
    scanf("%s", num1.integer);
    scanf("%s", num1.decimal);

    printf("Enter the second decimal value: ");
    scanf("%s", num2.integer);
    scanf("%s", num2.decimal);

    // Add decimals
    addDecimals(&num1, &num2, &result);

    // Output
    printf("Sum: %s.%s\n", result.integer, result.decimal);

    return 0;
}