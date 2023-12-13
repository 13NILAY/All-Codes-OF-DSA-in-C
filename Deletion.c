#include<stdio.h>
#include<stdlib.h>

struct Node
{
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

struct Node *DeleteFirst(struct Node *head)
{
    struct Node *ptr=head;
    head=ptr->next;
    free(ptr); 
    return head;
};
struct Node *DeleteAtIndex(struct Node *head,int index)
{
    struct Node *p=head;
    struct Node *q=head->next;

    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct Node *DeleteLast(struct Node *head)
{
    struct Node *p=head;
    struct Node *q=head->next;

    while (q->next!=NULL)
    {
        p=p->next;
        q=q->next; 
    }
    
    p->next=q->next;
    free(q);
    return head;
}
struct Node *DeleteAGivenValue(struct Node *head,int value)
{
    struct Node *p=head;
    struct Node *q=head->next;

    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {p->next=q->next;
    free(q);}
    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL;

    head=DeleteAGivenValue(head,3);
    LinkedListTraversal(head);

}