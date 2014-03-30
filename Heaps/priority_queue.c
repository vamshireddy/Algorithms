#include<stdio.h>
#define MAX 20
#define NEGATIVE_MAX -99999

typedef struct heap
{
    int a[MAX+1];
    int index;
    int size;
}heap;

int left(struct heap* h,int count)
{
    if( 2*count > h->size )
    {
        return NEGATIVE_MAX;
    }
    else
    {
        return 2*count;
    }
}

int right(struct heap* h, int count)
{
    if( 2*count+1 > h->size )
    {
        return NEGATIVE_MAX;
    }
    else
    {
        return (2*count)+1;
    }
}

int max_heapify(struct heap* h,int index)
{

    int i = index;
    int max;
    int flag = 0;
    int temp,l,r;
    while(i<=h->size)
    {
        l = left(h,i);
        r = right(h,i);
        max = i;

        if( h->a[i] < ((l<0)?NEGATIVE_MAX:h->a[l]) )
        {
            max = l;
        }
        if( h->a[max] < ((r<0)?NEGATIVE_MAX:h->a[r]) )
        {
            max = r;
        }
        if(max==i)
        {
            break;
        }
        else
        {
            temp = h->a[max];
            h->a[max] = h->a[i];
            h->a[i] = temp;
            i = max;
            flag = 1;
        }
    }
    return flag;
}
int parent(struct heap* h,int no)
{
    if(no<1)
    {
        return NEGATIVE_MAX;
    }
    else
    {
        return no/2;
    }
}
void insert(struct heap* h,int ele)
{
    if(h->index > h->size)
    {
        printf("Full\n");
        return;
    }
    h->a[h->index] = ele;
    int iter_index = parent(h,h->index);
    h->index++;
    int temp;

    while(iter_index>0)
    {
        temp = max_heapify(h,iter_index);
        if(temp==0)
        {
            break;
        }
        iter_index = parent(h,iter_index);
    }
    printf("Inserted !!!\n");
}

int extract(struct heap* h)
{
    if(h->size<1)
    {
        printf("EMpty\n");
        return -1;
    }
    int ind = h->size-1;
    int temp = h->a[ind];
    h->a[ind] = h->a[1];
    h->a[1] = temp;
    h->size--;
    int ele = h->a[ind];
    max_heapify(h,1);
    return ele;
}

void print_elements(struct heap* h)
{
    int i;
    for(i=1;i<=h->size;i++)
    {
        printf("%d ",h->a[i]);
    }
    printf("\n");
}

int main()
{
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    h->index = 1;
    h->size = MAX;
    printf("Enter your Choice : \n1.Insert\n2.Extract\n");
    int choice,ele;
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter Element to Be insterted  >> \n");
                    scanf("%d",&ele);
                    insert(h,ele);
                    break;
            case 2: printf("\n %d \n",extract(h));
                    break;
        }
    }
}



