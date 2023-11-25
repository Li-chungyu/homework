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
    
        //找出有幾個符合A(分N是奇是偶)
        if(N%2!=0){
            int same = 0;
            for (int i=0; i<N; i++) same += (Dev[i] == Dev[(N+1)/2-1]);
            printf("%d %d %d\n", Dev[(N+1)/2-1] , same, 1);
        }
        else{
            int same = 0;
            for (int i=0; i<N; i++) same += (Dev[i] == Dev[(N+1)/2-1]) || (Dev[i] == Dev[(N+1)/2-1+1]);
            printf("%d %d %d\n",Dev[(N+1)/2-1] , same, Dev[(N+1)/2-1+1]-Dev[(N+1)/2-1]+1);
        }
    }
    return 0;
}