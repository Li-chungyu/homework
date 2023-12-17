#include<stdio.h>

int main(){
    int N;
    typedef struct{
        char StudentID[20];
        int programming, programmingLab, calculus,total;
    }Student;
    
    scanf("%d",&N);
    
    Student score[N];
    
    for(int i=0;i<N;i++){
        scanf("%s%d%d%d",&score[i].StudentID,&score[i].programming,&score[i].programmingLab,&score[i].calculus);
        score[i].total = score[i].programming+score[i].programmingLab+score[i].calculus;
    }
        
    for(int i=0;i<N-1;i++)
        for(int j=0;j<N-i-1;j++)
            if(score[j].total>score[j+1].total){
                Student temp=score[j];
                score[j]=score[j+1];
                score[j+1]=temp;
            }
    
    for(int i=N-1;i>=N-3;i--){
        printf("%s\n",score[i].StudentID);
    }

    return 0;
}