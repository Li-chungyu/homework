#include<stdio.h>
int main(){
    typedef struct{
        int l;
        int h;
        int r;
    }Box;
    Box Number[5000];
    int k=0;  
    while(scanf("%d%d%d",&Number[k].l,&Number[k].h,&Number[k].r)!=EOF){
        k++;
    }
    //將建築輪廓訂好
    int height[10000]={0};
    for(int i=0;i<=k;i++)
        for(int j=Number[i].l;j<Number[i].r;j++){
            if(height[j]<Number[i].h)
            height[j]=Number[i].h;
        }
    //在高度改變時印出
    int current=0;
    for(int i=0;i<=9999;i++){
        if(height[i]!=current){
            current=height[i];
            printf("%d %d ",i,current);
        }
    }
    return 0;
}