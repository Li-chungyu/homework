int main() {
  init();
  char *str = s1;
  char *key = s2;
  int count=0;
  int keyLength_1 = strlen(key);
  int keyLength_2 = strlen(str);
  while (keyLength_2>=keyLength_1) {
    if (strncmp(str, key, keyLength_1) == 0) {             
       	count++;
    }
    keyLength_2--;
    str++;
    }

  printf("%d", count);
  return 0;
}
