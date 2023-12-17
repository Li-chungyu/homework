#include<stdio.h>
int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if((a<c&&c<b) || (a>c&&c>b) || (a<d&&d<b) || (a>d&&d>b) || (c<a&&a<d)  || (c>a&&a>d) || (c>b&&b>d) || (c<b&&b<d)){
        printf("overlay");
    }
    else{
        printf("no overlay");
    }
    return 0;
}