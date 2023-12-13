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

void preOrder(struct Node * root){
    if(root!=NULL)
    {
        printf(("%d "),root->data);
        preOrder(root->Left);
        preOrder(root->Right);
    }
}
int main() 
{
    struct Node *p =createNode(4);
    struct Node *p1 =createNode(1);
    struct Node *p2 =createNode(6);
    struct Node *p3 =createNode(5);
    struct Node *p4 =createNode(2);

    p->Left = p1;
    p->Right = p2;
    p1->Left=p3;
    p1->Right=p4;

    preOrder(p);
    return 0;
}