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
    int updated_pivot_pos = partition(a,low,high);
    if(updated_pivot_pos == pos)
    {
        return a[updated_pivot_pos];
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
    int a[10] = {1,8,6,4,2};
    printf("%d",selection(a,0,4,4));
}
