#include <stdio.h>
#include <math.h>

int main()
{
    float a,b;
    scanf("%f",&a);
    printf("%.2f\n",round(a*100)/100);
    b=(int)(a*100)/100.0;
    printf("%.2f",b);
    return 0;
}