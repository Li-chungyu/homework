#include<stdio.h>

int MaxCycle(int n1,int n2){
    int Maxcount=0;
    for(int i=n1;i<=n2;i++){
        int count=1;
        int n=i;
        while(n!=1){
            if(n%2!=0){
                n=3*n+1;
                count++;
            }
            else{
                n=n/2;
                count++;
            }
        }
        if(count>Maxcount)
        Maxcount=count;
    }
    return Maxcount;
}

int main(){
    int N1,N2;
    while(scanf("%d%d",&N1,&N2)!=EOF){
        if(N1<0 || N2>10000) continue;
        if(N1<N2) printf("%d %d %d\n",N1,N2,MaxCycle(N1,N2));
        if(N1>=N2) printf("%d %d %d\n",N1,N2,MaxCycle(N2,N1));
    }
    return 0;
}