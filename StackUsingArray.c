#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
void isEmpty(struct stack *ptr){
    if(ptr->top=-1)
    {
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
}
void isFull(struct stack *ptr){
    if(ptr->top=ptr->size-1  && ptr->top!=-1)
    {
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }
}
int main()
{
    struct stack *s;
    s->size=80;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    isEmpty(s);
    isFull(s);
    return 0;
}