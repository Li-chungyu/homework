#include <stdio.h>
#include <assert.h>

int main(){
    int N,i,j;
    scanf("%d",&N);
    assert(N>6);
    int number[N],temp;
    for (i=0 ; i<N ; i++){
        scanf("%d",&number[i]);
    }
    for (i=0 ; i<N-1 ; i++){
        for (j=0 ; j<N-i-1 ; j++){
            if (number[j]>number[j+1]){
                temp=number[j];
                number[j]=number[j+1];
                number[j+1]=temp;
            }
        }
    }
    int sum,loop;
    sum = 0;
    for (loop=0 ; loop<N ; loop++){
        sum+=number[loop];
    }
    float average = (float)(sum-number[0]-number[1]-number[2]-number[N-1]-number[N-2]-number[N-3])/(N-6);
    printf("%.2f",average);
    return 0;
}