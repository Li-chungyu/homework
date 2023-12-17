#include <stdio.h>
int main (){
    int N;
    while(scanf("%d",&N)!=EOF){
        int Dev[N];
        //輸入數字
        for(int i=0;i<N;i++)
        scanf("%d",&Dev[i]);
        //泡沫排序
        for(int i=0;i<N-1;i++)
          for(int j=0;j<N-i-1;j++){
            if(Dev[j]>Dev[j+1]){
                int temp = Dev[j];
                Dev[j] = Dev[j+1];
                Dev[j+1] = temp;
            }
          }
        //印出A之最小值
        printf("%d ",Dev[(N+1)/2-1]);
        //找出有幾個符合A(分N是奇是偶)
        if(N%2!=0){
            int count=0;
            for(int i=0;i<N;i++){
                if(Dev[i]==Dev[(N+1)/2-1])
                count++;
            }
            printf("%d ",count);
        }else{
            int count_1=0;
            for(int i=0;i<N;i++){
                if(Dev[i]==Dev[(N+1)/2-1] || Dev[i]==Dev[(N+1)/2-1+1])
                count_1++;
            }
            printf("%d ",count_1);
        }
        //印出A有幾個整數可能
        if(N%2!=0){
            printf("1\n");
        }else{
            printf("%d\n",(Dev[(N+1)/2-1+1])-(Dev[(N+1)/2-1])+1);
        }
    }
    return 0;
}