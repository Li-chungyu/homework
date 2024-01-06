#include<stdio.h>
#include<string.h>

typedef struct{
        char integer[1000];
        char decimal[1000];
    }DeciVar;

void SplitFloat(double num1,double num2,DeciVar *a,DeciVar *b){
    char Float_1[2001],Float_2[2001];
    sprintf(Float_1,"%.10lf",num1);
    sprintf(Float_2,"%.10lf",num2);
    sscanf(Float_1,"%[^.].%s",a->integer,a->decimal);
    sscanf(Float_2,"%[^.].%s",b->integer,b->decimal);
}

void AddDecimals(DeciVar *a,DeciVar *b,DeciVar *result,int length_1,int length_2){
    int carry =0;
    int sum =0;
    for(int i=length_1-1;i>=0;i--){
        sum = (a->decimal[i]-'0') + (b->decimal[i]-'0') + carry;
        result->decimal[i] = sum % 10 + '0';
        carry = sum/10;
    }
    for(int i=length_2-1;i>=0;i--){
        sum = (a->integer[i]-'0') + (b->integer[i]-'0') + carry;
        result->integer[i] = sum % 10 + '0';
        carry = sum/10;   
    }
}

int main(){
    double num1=0,num2=0;
    DeciVar a,b,result;
    memset(a.integer,0,sizeof(a.integer));
    memset(a.decimal,0,sizeof(a.decimal));
    memset(b.integer,0,sizeof(b.integer));
    memset(b.decimal,0,sizeof(b.decimal));
    scanf("%lf %lf",&num1,&num2);
    SplitFloat(num1,num2,&a,&b);
    int length_1 = (strlen(a.decimal)>strlen(b.decimal))? strlen(a.decimal):strlen(b.decimal);
    int length_2 = (strlen(a.integer)>strlen(b.integer))? strlen(a.integer):strlen(b.integer);
    AddDecimals(&a,&b,&result,length_1,length_2);
    char D[1000]={0};
    for(int i=0;i<1000;i++){
        if(result.decimal[i] == '0'  || result.decimal[i] == '\0') break;
        D[i] = result.decimal[i];
    }
    if(D[1]=='\0'){
        printf("%s",result.integer);
    }else{
        printf("%s.%s",result.integer,D);
    }
   

    return 0;
}