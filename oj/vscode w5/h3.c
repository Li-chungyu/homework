#include<stdio.h>
#include<string.h>
#define N 1000

int main(){
    char text[N];
    while (scanf("%999[^\n]%*c",text)!=EOF){
        //定義一結構包含頻率與ASCII數字
        typedef struct{
            int frequency;
            int number;
        }ASCII;

        ASCII numbers[128];
        
        //初始化位置
        for(int i=0;i<128;i++){
            numbers[i].frequency=0;
        }
        //存0~127進ASCII值
        for(int i=0;i<128;i++){
            numbers[i].number=i;
        }
        //算出字串中每個字符轉換成ASCII的頻率
        for (int i=0;i<strlen(text);i++){
            if (text[i]!='\n' && text[i]!='\r'){
                numbers[(int)text[i]].frequency++;
            }
        }
        //泡沫排序頻率與ASCII
        for (int i=0;i<128-1;i++)
          for(int j=0;j<128-i-1;j++){
            if(numbers[j].frequency>numbers[j+1].frequency || 
              (numbers[j].frequency==numbers[j+1].frequency && numbers[j].number<numbers[j+1].number)){
                //換頻率
                int temp = numbers[j].frequency;
                numbers[j].frequency = numbers[j+1].frequency;
                numbers[j+1].frequency = temp;
                //換ASCII的值
                int temp_1 = numbers[j].number;
                numbers[j].number = numbers[j+1].number;
                numbers[j+1].number = temp_1;
            }
          }
       
        //輸出結果
        for (int i=0;i<128;i++){
            if (numbers[i].frequency>0)
            printf("%d %d\n",numbers[i].number,numbers[i].frequency);
        }

        printf("\n");
    }
    return 0;
}