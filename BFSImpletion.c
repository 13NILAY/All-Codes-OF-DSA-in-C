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
       // printf("EnquedElement is %d\n",value);
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
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

int node;
int i=0;
int A[5][5]={
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {1,0,0,0,0},
    {0,1,0,0,0}
};
int visited[5]={0,0,0,0,0};
printf("%d ",i);
visited[i]=1;
Enqueue(&q,i);
while(!isEmpty(&q)){
     node=Dequeue(&q);
    for(int j=0;j<5;j++)
    {
        if(A[node][j]==1 && visited[j]==0){
            printf("%d",j);
            visited[j]=1;
            Enqueue(&q,j);
        }
    }
}

    return 0;
}