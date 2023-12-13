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
struct  Node *searchInBST(struct Node * root,int key){
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return searchInBST(root->Left,key);
    }
    else{
        return searchInBST(root->Right,key);
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


    struct Node *n=searchInBST(p,4);
    if(n!=NULL)
    {
        printf("Found: %d",n->data);
    }
    else{
        printf("Not Found");
    }
}