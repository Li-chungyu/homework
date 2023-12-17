#include <stdio.h>
#include <math.h>

int main(){
    int N,i;
    scanf("%d",&N);
    int number[N];
    for (i=0 ; i<N ; i++){
        scanf("%d",&number[i]);
    }
    int sum=0;
    for (i=0 ; i<N ; i++){
        sum+=number[i];
    }
    float average=(float)sum/N;
    float a=0;
    for (i=0 ; i<N ; i++){
        a+=(number[i]-average)*(number[i]-average);
    }
    float deviation_2 = a/N;
    float deviation = sqrt(deviation_2);
    printf("%.2f",deviation);
    return 0;
}