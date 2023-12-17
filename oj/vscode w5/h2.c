#include <stdio.h>

int main(){
    int N,number;
    int time=0;
    scanf("%d",&N);
    while (time<N){
        int count=0;
        scanf("%d",&number);
        int Car[number];
        for (int i=0;i<number;i++){
            scanf("%d",&Car[i]);
        }
        //泡沫排序
        for (int i=0;i<number-1;i++)
          for (int j=0;j<number-i-1;j++){
            if (Car[j]>Car[j+1]){
                int temp=Car[j];
                Car[j]=Car[j+1];
                Car[j+1]=temp;

                count++;    
            }
          }
        //輸出次數
        printf("Optimal train swapping takes %d swaps.\n",count);
        
        time++;
    }
    return 0;
}