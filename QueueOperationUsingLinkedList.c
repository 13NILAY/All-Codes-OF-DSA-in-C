#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *f=NULL;
struct Node *r=NULL;

void LinkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next ;
    }
}

void Enqueue(int value){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        printf("Queue is full\n");
    }
    else{
        n->data=value;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int Dequeue(){
    int val=-1;
    struct Node *ptr=f;
    if(f==NULL){
        printf("No elements to dequeue");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    LinkedListTraversal(f);
    Enqueue(56);
    Enqueue(45);
    Enqueue(34);
    Enqueue(78);
    LinkedListTraversal(f);
    printf("The Deque element is %d\n",Dequeue());
    printf("The Deque element is %d\n",Dequeue());
    printf("The Deque element is %d\n",Dequeue());
    printf("The Deque element is %d\n",Dequeue());
    printf("The Deque element is %d\n",Dequeue());
    LinkedListTraversal(f);
    
    return 0;
}
