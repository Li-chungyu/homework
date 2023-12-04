#include<stdio.h>
#include<string.h>
#define Max 25

int Block_pos[Max][Max];
int Block_record[Max]={-1};

void move_load(int num,int pos_num){
    int i,j,k;
    //找出num在pos_num中的位置
    for(i=0 ; i<Max ; i++)
    if(Block_pos[pos_num][i] == num) break;
    //將num以上的積木移回原位置
    for(j=i+1 ; j<Max ; j++){
        //若遇到-1代表上面沒方塊了跳出迴圈
        if(Block_pos[pos_num][j] == -1) break;
        //將方塊移到原本位置上
        for(k=0 ; k<Max ; k++){
            //找到空位才移過去
            if(Block_pos[Block_pos[pos_num][j]][k] == -1){
                Block_pos[Block_pos[pos_num][j]][k] = Block_pos[pos_num][j];
                //更新被移積木的新位置
                Block_record[Block_pos[pos_num][j]] = Block_pos[pos_num][j];
                break;
            }
        }
        //把已經移走的位置變空位
        Block_pos[pos_num][j] = -1;
    }
    return;
}

void move(int num,int pos_des){
    int i,j,k;
    int pos_num = Block_record[num];
    //找出num在pos_num中的位置
    for(i=0 ; i<Max ; i++)
    if(Block_pos[pos_num][i] == num) break;
    //移動num及num以上的方塊
    for(j=i ; j<Max ;j++){
        if(Block_pos[pos_num][j] == -1) break; 
        for(k=0 ; k<Max ;k++){
            //遇到空位就移過去
            if(Block_pos[pos_des][k] == -1){
                Block_pos[pos_des][k] = Block_pos[pos_num][j];
                //更新被移積木的位置
                Block_record[Block_pos[pos_num][j]] = pos_des;
                break;
            }
        }
        //把已經移走的位置變空位
        Block_pos[pos_num][j] = -1;
    }
return;
}

void MOT(int a,int b){
    int pos_a = Block_record[a];
    int pos_b = Block_record[b];
    move_load(a,pos_a);
    move_load(b,pos_b);
    move(a,pos_b);
}

void MOV(int a,int b){
    int pos_a = Block_record[a];
    int pos_b = Block_record[b];
    move_load(a,pos_a);
    move(a,pos_b);
}

void POT(int a,int b){
    int pos_a = Block_record[a];
    int pos_b = Block_record[b];
    move_load(b,pos_b);
    move(a,pos_b);
}

void POV(int a,int b){
    int pos_a = Block_record[a];
    int pos_b = Block_record[b];
    move(a,pos_b);
}

int main(){
    int N,a,b;
    scanf("%d",&N);
    //初始化值
    for(int i=0;i<Max;i++)
        for(int j=0 ; j<Max ;j++){
            Block_pos[i][j] = -1;
        }
    for(int i=0;i<N;i++) Block_record[i] = i;
    for(int i=0;i<N;i++) Block_pos[i][0] = i;
    //執行指令
    char instruction[Max];
    char movement[Max];
    char position[Max];
    gets(instruction);//把佔存區的\n去掉
    
    while(gets(instruction)){
        //結束
        if(strcmp(instruction,"quit") == 0) break;
        //分解指令
        sscanf(instruction,"%s %d %s %d",movement,&a,position,&b);
        //錯誤指令
        if(a==b || Block_record[a]==Block_record[b]) continue;
        

        if(strcmp(movement,"move")==0 && strcmp(position,"onto")==0){
            MOT(a,b);
        }
        
        else if(strcmp(movement,"move")==0 && strcmp(position,"over")==0){
            MOV(a,b);
        }

        else if(strcmp(movement,"pile")==0 && strcmp(position,"onto")==0){
            POT(a,b);
        }

        else if(strcmp(movement,"pile")==0 && strcmp(position,"over")==0){
            POV(a,b);
        }
        else{
            return 1;
        }
    }
    //列印
    for(int i=0;i<N;i++){
        printf("%d:",i);
        for(int j=0;j<Max;j++){
            if(Block_pos[i][j]==-1){
                printf("\n");
                break;
            }
            printf(" %d",Block_pos[i][j]);
        }
    }
    return 0;
}










