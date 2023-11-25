#include<stdio.h>
#include<stdbool.h>

int main(){
    int N;
    scanf("%d",&N);
    typedef struct{
      int number;
      bool prime;
    }Nummberfile;

    Nummberfile numbers[N];

    for(int i=0;i<N;i++){
        scanf("%d",&numbers[i].number);
        numbers[i].prime = true;
        if(numbers[i].number==0 || numbers[i].number==1)
        numbers[i].prime = false;
    }
    //確定質數
    for(int j=0;j<N;j++)
      for(int i=2;(i*i)<=numbers[j].number;i++){
        if((numbers[j].number%i)==0)
        numbers[j].prime=false;
      }
    //排序
    for(int i=0;i<N-1;i++)
      for(int j=0;j<N-i-1;j++){
        if(numbers[j].prime==false && numbers[j+1].prime==false){
            if(numbers[j].number>numbers[j+1].number){
                Nummberfile temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }
        }
        else if(numbers[j].prime==true && numbers[j+1].prime==true){
            if(numbers[j].number<numbers[j+1].number){
                Nummberfile temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }
        }
        else if(numbers[j].prime!=numbers[j+1].prime){
            if(numbers[j].prime<numbers[j+1].prime){
                Nummberfile temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }
        }
      }
    //輸出
    for(int i=0;i<N;i++)
    printf("%d ",numbers[i].number);

    return 0;
}