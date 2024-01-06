#include <stdio.h>

typedef struct {
    float value;
} DeciVar;

void addDeciVars(const DeciVar *num1, const DeciVar *num2, DeciVar *result) {
    result->value = num1->value + num2->value;
}

int main() {
    DeciVar num1, num2, result;

    // Read input
    printf("Enter the first decimal value: ");
    scanf("%f", &num1.value);

    printf("Enter the second decimal value: ");
    scanf("%f", &num2.value);

    // Add the decimal values
    addDeciVars(&num1, &num2, &result);

    // Display the result
    printf("Result of the sum: %.10f\n", result.value);

    return 0;
}