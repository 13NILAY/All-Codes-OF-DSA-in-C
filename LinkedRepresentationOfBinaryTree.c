#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *Left;
    struct Node *Right;
};

struct Node *createNode(int data){
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    n->data=data;
    n->Left=NULL;
    n->Right=NULL;
    return n;
}

int main()
{
    struct Node *p =createNode(2);
    struct Node *p1 =createNode(1);
    struct Node *p2 =createNode(4);

    p->Left = p1;
    p->Right = p2;

    return 0;
}