#include<stdio.h>

int main(){
    char a,b,c,d;
    scanf("%c%c%c%c",&a,&b,&c,&d);
    // printf("%d, %d, %d, %d\n", a, b, c, d);
    if(a=='4' || b=='4' || c=='4' || d=='4'){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}