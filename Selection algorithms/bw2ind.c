#include<assert.h>

int partition(int a[],int low,int high)
{
    int pivot_index = low;
    int i;
    int first = low+1;
    int last = high;
    int temp;
    while(first<=last)
    {
        if(a[first]>a[pivot_index])
        {
            temp = a[first];
            a[first] = a[last];
            a[last] = temp;
            last--;
        }
        else if(a[first]<a[pivot_index])
        {
            temp = a[first];
            a[first] = a[pivot_index];
            a[pivot_index] = temp;;
            pivot_index++;
            first++;
        }
    }
    return pivot_index;
}


int selection(int a[],int low,int high,int pos)
{
    if(low>high)
    {

    }
    int updated_pivot_pos = partition(a,low,high);
    if(updated_pivot_pos == pos)
    {
        return updated_pivot_pos;
    }
    else if(updated_pivot_pos < pos)
    {
        return selection(a,updated_pivot_pos+1,high,pos);
    }
    else
    {
        return selection(a,low,updated_pivot_pos-1,pos);
    }
}



int main()
{
    int i;
    int a[10] = {1,8,6,4,2,24,61,125,11124,33};
    int aa = selection(a,0,9,0);
    printf("%d\n\n",a[aa]);
    int bb = selection(a,aa+1,9,4);
    for(i=aa;i<=bb;i++)
    {
        printf("%d ",a[i]);
    }
}
