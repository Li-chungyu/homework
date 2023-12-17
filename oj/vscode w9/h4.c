int main() {
    init();
    char *str = s;
    int sum=0;
    while (*str) {
        if (isdigit(*str)) {
            sum += atoi(str);
            while (isdigit(*str)) {
                str++;
            }
        } else {
            str++;
        }
    }
    printf("%d", sum);
    return 0;
}
