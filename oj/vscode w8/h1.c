#include<stdio.h>

int main(){
    int row,column,N;
    int k=0;
    scanf("%d%d%d",&row,&column,&N);
    int matrix[row][column];

    memset(matrix,0,sizeof(matrix));
    
    while(k<N){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        matrix[a][b]=c;
        k++;
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
        