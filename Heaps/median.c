#include<stdio.h>
#define MAX 20
#define NEGATIVE_MAX -99999
#define POSITIVE_MAX 21421551

typedef struct heap
{
    char ch;
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

int min_heapify(struct heap* h,int index)
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

        if( h->a[i] > ((l<0)?POSITIVE_MAX:h->a[l]) )
        {
            max = l;
        }
        if( h->a[max] > ((r<0)?POSITIVE_MAX:h->a[r]) )
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
        if(h->ch=='a')
        {
            temp = max_heapify(h,iter_index);
        }
        else
        {
            temp = min_heapify(h,iter_index);
        }
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

    if(h->ch=='a')
    {
        max_heapify(h,1);
    }
    else
    {
        min_heapify(h,1);
    }
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
    struct heap* h1;
    struct heap* h2;
    h1 = (struct heap*)malloc(sizeof(struct heap));
    h2 = (struct heap*)malloc(sizeof(struct heap));

    h1->index=1;
    h1->size = MAX;
    h1->ch = 'a';

    h2->index=1;
    h2->size = MAX;
    h2->ch = 'b';

    printf("Enter your Choice : \n1.Insert\n2.Median\n");
    int choice,ele;
    int flip = 0;
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {
                    printf("Enter Element to Be insterted  >> \n");
                    scanf("%d",&ele);
                    if(ele < h1->a[1])
                        insert(h1,ele);
                    else
                        insert(h2,ele);
                    int index1 = h1->index-1;
                    int index2 = h2->index-1;
                    int temp;
                    if(index1>index2)
                    {
                        while(index1>index2)
                        {
                            temp = extract(h1);
                            insert(h2,temp);
                            index1--;
                        }
                    }
                    else if(index2>index1)
                    {
                        while(index2>index1)
                        {
                            temp = extract(h2);
                            insert(h1,temp);
                            index2--;
                        }
                    }
                    break;}
            case 2: {int s = (h1->index-1)+(h2->index-1);
                    if(s%2==0)
                    {
                        printf("Medians are %d %d\n",h1->a[1],h2->a[1]);
                    }
                    else
                    {
                        if(h1->index>h2->index)
                        {
                            printf("Median is %d",h1->a[1]);
                        }
                        else
                        {
                            printf("Median is %d",h2->a[1]);
                        }
                    }
                    break;}
        }
        flip++;
    }
}




