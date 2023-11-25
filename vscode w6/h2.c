#include<stdio.h>

int main(){
    int decimal;
    scanf("%d",&decimal);

    if (decimal<2147483647){
        int binary[32];

        int i=0;
        while(decimal>0){
            binary[i]=decimal%2;
            decimal=decimal/2;
            i++;
        }

        for (int j=i-1;j>=0;j--){
            printf("%d",binary[j]);
        }
    }
    return 0;
}