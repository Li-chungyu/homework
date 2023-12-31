#include "search.h"

static int isEmpty(stack_t *StackPtr){
    if(StackPtr->top == -1) return 1;
    return 0;
}



//取
axis_t pop(stack_t *StackPtr){
    axis_t temp = {-1,-1};
    if(isEmpty(StackPtr)) return temp;
    return StackPtr->element[StackPtr->top--];
}

//存
void push(stack_t *StackPtr,axis_t element){
    StackPtr->top++;
    StackPtr->element[StackPtr->top] = element; 
}

