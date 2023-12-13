#include<stdio.h>
#include<stdlib.h>

int linearSearch(int arr[],int element,int size)
{   int index,flag;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            flag=1;
            index=i;
            break;
        }
    }
    if(flag==1)
    {
        return index;
    }
    else 
    {
        return -1;
    }

}

int binarySearch(int arr[],int element,int size)
{
    int start=0,end=size-1,flag,index;
    while(start<=end)
    {       int mid=(start+end)/2;
        if(element==arr[mid])
        {   
            flag=1;
             index=mid;
             break;
        }
        else if(element>arr[mid])
        {
            start=mid+1;
        }
        else if(element<arr[mid])
        {
            end=mid-1;
        } 
    }
    if(flag==1)
    {
        return index;
    }
    else 
    {
        return -1;
    }
}
int main()
{
    int arr[100]={2,4,6,8,10,12};
    int size=6;
    int element=4;
    int n=linearSearch(arr,element,size);
    if(n!=-1)
        printf("Found the element %d at index %d",element,n);
    else
        printf("Not found");
}