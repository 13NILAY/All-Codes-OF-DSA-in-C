#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFULL(struct Queue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct Queue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void Enqueue(struct Queue *q,int value)
{
    if(isFULL(q))
    {
        printf("Queue Is Full can't insert element\n");
    }
    else{
        q->r=q->r+1;
        q->arr[q->r]=value;
        printf("EnquedElement is %d\n",value);
    }
}
int Dequeue(struct Queue *q){
    int a=-1;
    if(isEmpty(q))
    {
        printf("No element to Dequeue");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct Queue q;
    q.size=2;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    // if(isEmpty(q)){
    //     printf("Queue is Empty\n");
    // }

    Enqueue(&q,5);
    Enqueue(&q,4);
    //Enqueue(&q,9);
    //Enqueue(q,8);
    //Enqueue(q,6);

    

    printf("The Dequeued Element is %d \n",Dequeue(&q));
    printf("The Dequeued Element is %d \n",Dequeue(&q));
    
    
    if(isFULL(&q)){
        printf("Queue is Full\n");
    }
        if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }

    return 0;
}