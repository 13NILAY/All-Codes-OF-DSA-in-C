#include<stdio.h>
#include<stdlib.h>

struct CircularQueue{
    int size;
    int f;
    int r;
    int *arr;
};
int isFULL(struct CircularQueue *q)
{
    if(((q->r+1)%q->size)==q->f)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct CircularQueue *q)
{
    if(q->f==q->r)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void Enqueue(struct CircularQueue *q,int value)
{
    if(isFULL(q))
    {
        printf("CircularQueue Is Full can't insert element\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=value;
        printf("EnquedElement is %d\n",value);
    }
}
int Dequeue(struct CircularQueue *q){
    int a=0;
    if(isEmpty(q))
    {
        printf("No element to Dequeue");
    }
    else{
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    }
    return a;
}

int main(){
    struct CircularQueue q;
    q.size=3;
    q.f=q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));

    // if(isEmpty(q)){
    //     printf("CircularQueue is Empty\n");
    // }

    Enqueue(&q,5);
    Enqueue(&q,4);
    Enqueue(&q,9);
    //EnCircularqueue(q,8);
    //EnCircularqueue(q,6);

    

    printf("The Dequeued Element is %d \n",Dequeue(&q));
    printf("The Dequeued Element is %d \n",Dequeue(&q));
    
    
    if(isFULL(&q)){
        printf("CircularQueue is Full\n");
    }
        if(isEmpty(&q)){
        printf("CircularQueue is Empty\n");
    }

    return 0;
}