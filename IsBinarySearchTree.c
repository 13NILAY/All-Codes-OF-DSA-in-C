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

void InOrder(struct Node * root){
    if(root!=NULL)
    {
        InOrder(root->Left);
          printf(("%d "),root->data);
        InOrder(root->Right);
      
    }
}

int isBST(struct Node *root)
{
    static struct Node *prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->Left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->Right);
    }
    else{
        return 1;
    }

}

int main() 
{
    struct Node *p =createNode(5);
    struct Node *p1 =createNode(3);
    struct Node *p2 =createNode(6);
    struct Node *p3 =createNode(2);
    struct Node *p4 =createNode(4);

    p->Left = p1;
    p->Right = p2;
    p1->Left=p3;
    p1->Right=p4;
    InOrder(p);

    if(isBST(p))
    {
        printf("\nIt is a BST.");
    }
    else{
        printf("\nIt is not a BST.");
    }
    return 0;
}