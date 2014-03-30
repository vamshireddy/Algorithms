// Implementing Heaps
#include<stdio.h>
#define MAX 20
#define NEGATIVE_MAX -999999

typedef struct heap
{
    int a[MAX+1];
    // We dont use the index '0' So, We declare an array of MAX+1
    int size;
    int index;
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

void max_heapify(struct heap* h,int index)
{

    int i = index;
    int max;
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
        }
    }
}

void insert(struct heap* h,int ele)
{
    if(h->index<=0)
    {
        printf("Full\n");
        return;
    }
    if(h->index > h->size/2)
    {
        h->a[h->index] = ele;
        h->index--;
    }
    else
    {
        h->a[h->index] = ele;
        max_heapify(h,h->index);
        h->index--;
    }
}

int extract(struct heap* h)
{
    int temp;
    int ind = h->index+1;

    temp = h->a[ind];
    h->a[ind] = h->a[h->size];
    h->a[h->size] = temp;

    int element = h->a[h->size];
    h->size--;
    max_heapify(h,ind);
    return element;
}

int main()
{
    int i;
    int array[MAX+1] = {0,9,2,8,3,6,5,57,12,654,346,3,67,11,45,80,4,7,1,0,55};
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    h->size = MAX;
    h->index = MAX;
    for(i=1;i<=MAX;i++)
    {
        insert(h,array[i]);
    }
    int count = 0;
    for(i=1;i<=MAX;i++)
    {
        printf("%d ",extract(h));
        count+=1;
    }
    printf("\nCount = %d\n",count);
}

