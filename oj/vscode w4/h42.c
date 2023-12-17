#include <stdio.h>
#include <string.h>
#define Array 1001

int main() {
    char str[Array];
    int sum_odd, sum_even, i;
    
    while (1) {
        scanf("%s", str);
        
        if (strcmp(str, "0") == 0) {
            break;  // End of input
        }

        sum_odd = 0;
        sum_even = 0;
        
        for (i = 0; i < strlen(str); i++) {
            if (i % 2 == 0) {
                sum_even += str[i] - '0';
            } else {
                sum_odd += str[i] - '0';
            }
        }
        
        int diff = sum_odd - sum_even;
        
        if (diff % 11 == 0) {
            printf("%s is a multiple of 11.\n", str);
        } else {
            printf("%s is not a multiple of 11.\n", str);
        }
    }

    return 0;
}