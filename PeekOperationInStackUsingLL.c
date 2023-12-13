#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next ;
    }
}
int isEmpty(struct Node* top){
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFULL(struct Node* top){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int pop(struct Node **top)
{
    if(isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        struct Node *n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
struct Node *push(struct Node *top, int x)
{
    if(isFULL(top)){
        printf("Stack OverFLow\n");
        //return -1;
    }
    else{
        struct Node *n=(struct Node*)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}

int peek(int pos,struct Node *ptr)
{
    for(int i=0;(i<pos-1&& ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }
}
int stackTop(struct Node *top)
{
    return top->data;
}
int main(){
    struct Node* top=NULL;
    top=push(top,78);
   // top=push(top,45);
    //top=push(top,63);
    //top=push(top,47);
    LinkedListTraversal(top);
    printf("The Popped Out Element is :%d\n",pop(&top));
    LinkedListTraversal(top);
    printf("Value at position 1 is %d:",peek(2,top));
    return 0;
}
//stackTop
// int stackTop(){
//     return top->data;
// }
// stack Bottom