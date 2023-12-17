int main() {
  int *a, *b;
  init(&a, &b);
  int sum;
  while (a < b) {
  	sum += *a;
    a++;
  }
  printf("%d", sum);
  return 0;
}
