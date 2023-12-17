#include <stdio.h>

int main(){
    int N,i;
    scanf("%d",&N);
    int score[N];
    for(i=0 ; i<N ; i++){
        scanf("%d",&score[i]);
    }
    int sum=0;
    for(i=0 ; i<N ; i++){
        sum+=score[i];
    }
    float average = (float)sum/N;
    int fail_count=0;
    for(i=0 ; i<N ; i++){
        if(score[i]<average){
            fail_count++;
        }
    }
    printf("%d",fail_count);
    return 0;
}