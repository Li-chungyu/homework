#include <stdio.h>

int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  float c=(float)a/b;
  double d=(double)a/b;
  printf("%.10f\n",c);
  printf("%.10f\n",d);
  return 0;
}