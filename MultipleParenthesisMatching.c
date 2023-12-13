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
int match(char a,char b)
{
    if(a=='{'&& b=='}'){
        return 1;
    }
    if(a=='('&& b==')'){
        return 1;
    }
    if(a=='['&& b==']'){
        return 1;
    }
    return 0;
}
int parenthesisMatch(char *exp){
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char popped_ch ;

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{'){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
            if(isEmpty(sp)){
                return 0;
            }
              popped_ch = pop(sp);
        
        if(!match(popped_ch,exp[i])){
            return 0;
        }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }

}
int main()
{

    char *exp="{45*30+{(56*3-[46*5])}}";
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is NOT matching");
    }
       return 0;
}