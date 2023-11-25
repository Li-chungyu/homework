#include<stdio.h>
#include<stdlib.h>
//定義一結構包含數字與餘數
typedef struct{
    int number;
    int moduloM;
} NumberFile;

int main(){
    int N,M;

    while( scanf("%d%d",&N,&M)!=EOF && N+M>0){

    //宣告一階構矩陣
    NumberFile numbers[N];

    //將數字存入矩陣
    for (int i=0;i<N;i++){
        scanf("%d",&numbers[i].number);
        //算出個數字之餘數值
        numbers[i].moduloM = numbers[i].number%M;
        }
        
    //泡沫排序法
    for (int i=0;i<N-1;i++)
      for(int j=0;j<N-i-1;j++){
        if (numbers[j].moduloM > numbers[j+1].moduloM){
            NumberFile temp=numbers[j];
            numbers[j]=numbers[j+1];
            numbers[j+1]=temp;
           


        }else if(numbers[j].moduloM==numbers[j+1].moduloM){
            //偶數在奇數前面
            if((abs(numbers[j].number)%2==0)&&(abs(numbers[j+1].number)%2==1)){
                NumberFile temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }else if((abs(numbers[j].number)%2==1)&&(abs(numbers[j+1].number)%2==1)){
                //較小的奇數在前
                if(numbers[j].number<numbers[j+1].number){
                NumberFile temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
                }
               
            }else if((abs(numbers[j].number)%2==0)&&(abs(numbers[j+1].number)%2==0)){
                //較大的偶數在前
                if(numbers[j].number>numbers[j+1].number){
                NumberFile temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
                }

            }
        }
      }
      //輸出結果
      printf("%d %d\n",N,M);
      for (int i=0;i<N;i++){
        printf("%d\n",numbers[i].number);
      }
    }
      printf("0 0\n");
    
      return 0;
}