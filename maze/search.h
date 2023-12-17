#ifndef _SEARCH__H
#define _SEARCH__H


#define Max 10

//巨集(後面的括弧為等值的程式)
#define EQU(p,q) (p.x==q.x && p.y==q.y)

typedef struct axis_1{
    int x;
    int y;
}axis;

//固定大小
typedef struct stack_1{
    int top;
    int element[Max*Max];
}stack;

//可以動態分配(要再加一個stackinit來malloc)
typedef struct stack_2{
    int top;
    int *element;
}



#endif


