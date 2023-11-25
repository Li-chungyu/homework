#include <stdio.h>
#include <string.h>

void printLongestSubstring(char s[], int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%c", s[i]);
    }
}

void lengthOfLongestSubstring(char s[]) {
    int n = strlen(s);
    int maxLength = 0;
    int start = 0;
    int resultStart = 0;  // 保存最长子串的起始位置
    int resultEnd = 0;    // 保存最长子串的结束位置
    int charIndex[128];

    memset(charIndex, -1, sizeof(charIndex));

    for (int end = 0; end < n; end++) {
        if (charIndex[s[end]] >= start) {
            start = charIndex[s[end]] + 1;
        }

        charIndex[s[end]] = end;
        int currentLength = end - start + 1;

        if (currentLength > maxLength) {
            maxLength = currentLength;
            resultStart = start;   // 更新最长子串的起始位置
            resultEnd = end;       // 更新最长子串的结束位置
        }
    }

    printLongestSubstring(s, resultStart, resultEnd); // 打印最长子串

    return ;
}

int main() {
    char input[1000];
    scanf("%s",input);
    lengthOfLongestSubstring(input);
    return 0;
}