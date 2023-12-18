//避免標頭檔被重複呼叫
#ifndef _SEARCH_H
#define _SEARCH_H


#define Max 11

#define EQU(p,q) (p.x==q.x && p.y==q.y)

typedef struct axis{
    int x;
    int y;
}axis_t;


typedef struct stack{
    int top;
    axis_t element[Max*Max];
}stack_t;

//傳指標代替傳整個值
int push(stack_t *StackPtr,axis_t element);

axis_t pop(stack_t *StackPtr);  

#endif


