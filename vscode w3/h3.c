#include<stdio.h>
#include<math.h>

int main(){
    int distance;
    float toll;
    scanf("%d",&distance);
    if(distance<=200){
        toll=distance*1.2;
        printf("%d",(int)round(toll));
    }
    if(distance>200){
        toll=200*1.2+(distance-200)*1.2*0.75;
        printf("%d",(int)round(toll));
    }
    return 0;
}