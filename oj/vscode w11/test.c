#include <stdio.h>
#include <string.h>

char *convertToDifferentBase(int dec, int base, char *result) {
    // Base case: when the decimal number is 0
    if (dec < base) {
        if(dec<10){
            result[0] = dec+'0';
        }else{
            result[0] = dec-10+'A';
        }
        result[1] = '\0';
        return result;
    }

    // Recursive case
    int remainder = dec % base;
    char remainderChar;

    // Convert the remainder to its corresponding character representation
    if (remainder < 10) {
        remainderChar = remainder + '0';
    } else {
        remainderChar = remainder - 10 + 'A';
    }

    // Recursively call the function for the quotient
    convertToDifferentBase(dec / base, base, result);

    // Append the current remainder character to the result
    int length = strlen(result);
    result[length] = remainderChar;
    result[length + 1] = '\0';

    return result;
}

int main() {
    int decimalNumber = 31; // Replace with your desired decimal number
    int targetBase = 2;    // Replace with your desired target base

    char result[100]; // Adjust the size of the result array as needed

    // Call the conversion function
    convertToDifferentBase(decimalNumber, targetBase, result);

    // Print the result
    printf("Decimal %d in base %d: %s\n", decimalNumber, targetBase, result);

    return 0;
}