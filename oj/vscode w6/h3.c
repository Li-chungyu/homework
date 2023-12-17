#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>

int main(){
    char c;
    bool decide=true;
    //輸入文章
    while((c=getchar())!=EOF){
        if(decide && isalpha(c)){
            putchar(toupper(c));
            decide=false;
        }
        else{
            putchar(c);
        }

        if(c=='.' || c=='?'){
            decide=true;
        }
        else if(isdigit(c)){
            decide=false;
        }
    }
    return 0;
}