#include<stdio.h>

int m,n;
typedef struct{
    int sid;
    int student_id;
    int course_id;
}Courses;
typedef struct{
    int sid;
    int score;
}Scores;

int main(){
    scanf("%d%d",&m,&n);
    Courses course[m];
    Scores score[n];

    for(int i=0;i<m;i++)
        scanf("%d%d%d",&course[i].sid,&course[i].student_id,&course[i].course_id);

    for(int i=0;i<n;i++)
        scanf("%d%d",&score[i].sid,&score[i].score);
    //紀錄平均不及格人數
    int w=0;
    int y;
    for(int i=0;i<n-1;i++){
        int k=0;
        int z=0;
        int avr=0;
        int number[100]={0};
        if(score[i].sid != score[i+1].sid){
            for(int j=k;j<=i;j++){
                number[j]=score[j].score;
                z+=number[j];
            } 
            avr=z/(i-k+1);
            if(z<60) w++;
            k=i+1;
            y=k;
        }
    }
    int number[100]={0};
    int z=0;
    int avr=0;
    for(int j=y;j<n;j++){
        number[j]=score[j].score;
        z+=number[j];
    }
    avr=z/(n-y);
    if(avr<60) w++;

    printf("%d %d",m,w);

    return 0;
}