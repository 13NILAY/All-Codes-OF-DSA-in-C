#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};
int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}
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
void push(struct stack *ptr,char value){
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
        char val=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return val;
        
    }
}
char *infixToPostfix(char *infix){
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;//Infix traversal
    int j=0;//postfix traversal
    while(infix[i]!='\0')
    {
        if(!isoperator(infix[i]))
        {
            postfix[j]=infix[i];
            j++;i++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;

            }
        }
    }
    while(!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{

       return 0;
}