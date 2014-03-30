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
    int a[] = {21,214,7437,12,75,656,21,3443,5665,55,2,9};
    partition(a,0,11);
    int i;
    for(i=0;i<12;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
