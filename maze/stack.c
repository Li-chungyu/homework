#include "search.h"

static int isEmpty(stack_t *StackPtr){
    if(StackPtr->top == -1) return 1;
    return 0;
}

static int isFull(stack_t *StackPtr){
    if(StackPtr->top == Max-1) return 1;
    return 0;
}


//取
axis_t pop(stack_t *StackPtr){
    axis_t temp = {-1-1};
    if(isEmpty(StackPtr)) return temp;
    return StackPtr->element[StackPtr->top--];
}

//存
int push(stack_t *StackPtr,axis_t element){
    if(isFull) return 0;
    StackPtr++;
    StackPtr->element[StackPtr->top] = element; 
    return 1;
}

