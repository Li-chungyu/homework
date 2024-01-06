#include<stdio.h>
#include<string.h>

int main(){
  char num[1000];
  int count=1;
   typedef struct data{
    int a;
    int b;
  }data_t;
  data_t haha[1000];
  memset(haha,'\0',sizeof(haha));
  memset(num,'\0',sizeof(num));
  scanf("%s",num);
  for(int i=0;i<999;i++)
    for(int j=0;j<999-i;j++){
    	if(num[j]>num[j-1]){
        	int temp = num[j];
          	num[j]=num[j+1];
          	num[j+1]=temp;
        }
    }
  int k=0;
  for(int i=999;i>=0;i--){
  	if(num[i]=='0'){
    	continue;
    }
    if(num[i]==num[i-1]){
    	count++;
    }else if(num[i]!=num[i-1]){
      haha[k].a=num[i];
      haha[k].b=count;
    	count=1;
      k++;
    }  
  }
  for(int i=0;i<999;i++)
    for(int j=0;j<999-i;j++){
      if(haha[j].b>haha[j+1].b){
        data_t temp=haha[j];
        haha[j]=haha[j+1];
        haha[j+1]=temp;
      }
    }
  for(int i=0;i<1000;i++){
    if(haha[i].a!='\0'){
      printf("%d %d\n",haha[i].a,haha[i].b);
    }
  }

  return 0;
}