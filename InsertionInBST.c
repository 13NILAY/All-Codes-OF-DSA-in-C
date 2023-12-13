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
void insert(struct Node * root,int key){
    struct Node *prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            printf("Duplicate Value");
            return ;
        }
        else if(key<root->data){
            root=root->Left;
        }
        else{
            root=root->Right;
        }
    }
    struct Node * New=createNode(key);
    if(key<prev->data)
    {
        prev->Left=New;
    }
    else{
        prev->Right=New;
    }
    //return NULL;
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
    insert(p,4);
    printf("%d",p->Right->Right->data);
    // struct Node *n=searchInBST(p,4);
    // if(n!=NULL)
    // {
    //     printf("Found: %d",n->data);
    // }
    // else{
    //     printf("Not Found");
    // }
    if(isBST(p))
    {
        printf("\nIt is a BST.");
    }
    else{
        printf("\nIt is not a BST.");
    }
    InOrder(p);
    return 0;
    
}