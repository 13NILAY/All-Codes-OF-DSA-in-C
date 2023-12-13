#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1 && ptr->top!=-1)
    {
        return 1;
    }
    else{
        return 0;
    }   
}
void push(struct stack *ptr,int value){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top=ptr->top+1;
        ptr->arr[ptr->top]=value;
    }
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return val;
        
    }
}
int peek(struct stack *ptr,int i)
{
    int arrayInd=ptr->top-i+1;
    if(arrayInd<0)
    {
        printf("Not a valid position for stack");
        return -1;
    }
    else{
        return ptr->arr[arrayInd];
    }
}
int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}
int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}
int main()
{   //All operation in stack has O(1) time complexity
    struct stack *sp=(struct stack *)malloc(sizeof(struct  stack));

    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));

    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    push(sp,56);
    push(sp,2);
    push(sp,6);
    push(sp,9);
    push(sp,12);
    push(sp,15);
    push(sp,1);
    for(int i=1;i<=sp->top+1;i++)
    {
        printf("Element at Index %d is %d\n",i,peek(sp,i));
    }
    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    printf("StackTOP is %d\n",stackTop(sp));
    printf("StackBOTTOM is %d\n",stackBottom(sp));
    return 0;
}