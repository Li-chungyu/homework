#include<stdio.h>

int main(){
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

    scanf("%d%d",&m,&n);
    Courses course[m];
    Scores score[n];

    for(int i=0;i<m;i++)
        scanf("%d%d%d",&course[i].sid,&course[i].student_id,&course[i].course_id);

    for(int i=0;i<n;i++)
        scanf("%d%d",&score[i].sid,&score[i].score);
    //排序
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++){
            if(score[j].sid>score[j+1].sid){
                Scores temp = score[j];
                score[j] = score[j+1];
                score[j+1] = temp;
            }
        }
    //紀錄至少一科不及格人數
    int w=0;
    int y;
    for(int i=0;i<n-1;i++){
        int k=0;
        int z=0;
        int number[100]={0};
        if(score[i].sid != score[i+1].sid){
            for(int j=k;j<=i;j++){
                number[j]=score[j].score;
                if(number[j]<60)
                    z++;
            } 
            if(z>=1) w++;
            k=i+1;
            y=k;
        }
    }
    for(int j=y;j<n;j++){
        int number[100]={0};
        int z=0;
        number[j]=score[j].score;
        if(number[j]<60)
            z++;
            if(z>=1) w++;
    }

    printf("%d %d",m,w);

    return 0;
}