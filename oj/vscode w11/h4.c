#include <stdio.h>

int eval(int *i, char *exp)
{
  while(exp[*i] == ' ' || exp[*i] == '(' || exp[*i] == ',' || exp[*i] == ')')
    (*i) ++;
  if(exp[*i] == 'F')
  {
    (*i) ++;
    return eval(i, exp) * 3 + 1;
  }
  else if(exp[*i] == 'G')
  {
    (*i) ++;
    return eval(i, exp) * eval(i, exp) - 3;
  }
  else
  {
    int num = 0;
    while(exp[*i] >= '0' && exp[*i] <= '9')
    {
      num = num * 10 + exp[*i] - '0';
      (*i) ++;
    }
    return num;
  }
}

int main()
{
  int i = 0;
  char exp[1024];
  fgets(exp,sizeof(exp),stdin);
  printf("%d", eval(&i, exp));
}