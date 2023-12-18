#include<stdio.h>
#include"search.h"

char maze[10][10]={
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 0, 0, 0, 1, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
  { 1, 0, 1, 1, 1, 1, 1, 0, 0, 1 },
  { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

char mark[10][10] = {0};


axis_t Move(stack_t* StackPtr,axis_t position){
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    for(int i=0;i<4;i++){
        axis_t location;
        location.x = position.x + dx[i];
        location.y = position.y + dy[i];
        if(location.x<0 || location.x>9 || location.y<0 || location.y>9){
            continue;
        }
        if(maze[location.x][location.y] ==0 && mark[location.x][location.y] !='^'){
            mark[location.x][location.y] = '^';
            push(StackPtr,location);
        }
    }
    return pop(StackPtr);
}

int main()
{
    stack_t myStack;
    axis_t current;
    axis_t entry  = {1,0};
    axis_t exit   = {6,9};
    axis_t CanNot = {-1,-1};

    myStack.top = -1;
    current = entry;
    mark[current.x][current.y] = '^';

    while(!EQU(current,exit)){
        current = Move(&myStack,current);
        if(EQU(current,CanNot)){
            printf("Can not exit!\n");
            break;
        }
        printf("move to (%d,%d)\n",current.x,current.y);
    }

    return 0;
}




