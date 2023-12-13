#include<stdio.h>
#include<stdlib.h>

void display(int a[],int n){
    //code for traversal
    for(int i=0;i<n;i++)
    {
        printf("  %d",a[i]);
    }
    printf("\n");
}
indInsertion(int arr[],int size,int element,int capacity,int index)
{
    if(size>=capacity)
    {
        return -1;
    }
    for(int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
}
indDeletion(int arr[],int size,int index)
{   //Code for deletion
    for(int i=index;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
}
int main()
{
    int arr[100]={7,8,20,4,1,9};
    int size=6,element=5,index=2;
    display(arr,size);
    indInsertion(arr,size,element,100,index);
    size+=1;
    display(arr,size);
    indDeletion(arr,size,3);
    size-=1;
    display(arr,size);
    return 0;

}

