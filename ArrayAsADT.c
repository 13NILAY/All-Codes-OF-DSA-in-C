#include<stdio.h>
#include<stdlib.h>

struct array{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct array *a,int tsize, int usize)
{
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int*)malloc(tsize*sizeof(int));
}

void show(struct array *a)
{
    
    for(int i=0;i<a->used_size;i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}

void setVal(struct array *a)
{
    int n;
    for(int i=0;i<a->used_size;i++)
    {
        printf("Enter Element %d",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}

int main()
{
    struct array marks;
    createArray(&marks,10,2);
    printf("WE are running setval \n");
    setVal(&marks);

    printf("We are running show\n");
    show(&marks);
    return 0;

}