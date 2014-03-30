#include <stdio.h>
#include <stdlib.h>

void partition(int a[],int l,int r)
{
    if(l==r)
    {
        return;
    }
    int pivot_pos = l;
    int i,temp;
    int front = l+1;
    int back = r;
    while(front<=back)
    {
        if(a[front]>a[pivot_pos])
        {
            temp = a[front];
            a[front] = a[back];
            a[back] = temp;
            back--;
        }
        else
        {
            temp = a[pivot_pos];
            a[pivot_pos] = a[front];
            a[front] = temp;
            pivot_pos++;
            front++;
        }
    }

}

int main()
{
    int a[] = {5,10,9,8,7,6,4,3,2,1};
    partition(a,0,9);
    int i;
    for(i=0;i<9;i++)
    {
        printf("%d ",a[i]);
    }
    printf("Hello world!\n");
    return 0;
}
