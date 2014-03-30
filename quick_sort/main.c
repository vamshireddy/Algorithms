#include <stdio.h>
#include <stdlib.h>
#define NO_OF_ELE 10000

long int total = 0;
int median(int a[],int first,int middle,int last)
{
    int ind;
    if(a[middle]>a[first])
    {
        if(a[middle]<a[last])
        {
            ind = middle;
        }
        else if(a[middle]>a[last])
        {
            if(a[last]>a[first])
            {
                ind = last;
            }
            else
            {
                ind = first;
            }
        }
    }
    else
    {
        if(a[middle]>a[last])
        {
            ind = middle;
        }
        else
        {
            if(a[last]<a[first])
            {
                ind = last;
            }
            else
            {
                ind = first;
            }
        }
    }
    return ind;
}

int new_partition(int a[],int l,int r)
{
    int middle;
    if((r-l+1)%2!=0)
    {
        middle = l+((r-l+1)/2);
    }
    else
    {
        middle = l+((r-l+1)/2)-1;
    }
    int first = l;
    int last = r;
    int ind = median(a,first,middle,last);
    int temp = a[l];
    a[l] = a[ind];
    a[ind] = temp;
    int p = a[l];
    int j,i = l+1;
    for(j=l+1;j<=r;j++)
    {
        if(a[j]<p)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i++;
        }
        total = total + 1;
    }
    temp = a[l];
    a[l] = a[i-1];
    a[i-1] = temp;
    return i-1;
}

int partition(int a[],int l,int r)
{
    if(l==r)
    {
        return;
    }
    /*int ind;
    int middle = a[l+((r-l)/2)];
    int first = a[l];
    int last = a[r];
    ind = median(first,middle,last);*/
    int i,temp;
    temp = a[l];
    a[l] = a[r];
    a[r] = temp;
    int pivot_pos = l;
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
        total = total + 1;
    }
    return pivot_pos;
}


void quick_sort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int pivot_index_after_partition = new_partition(a,l,r);
    quick_sort(a,l,pivot_index_after_partition-1);
    quick_sort(a,pivot_index_after_partition+1,r);
}

int main()
{
    FILE *fp;
    int nums[NO_OF_ELE];
    int nums_index=0;
    fp = fopen("/home/vamshi/QuickSort.txt","r");

    int i;
    int temp_num[10];
    int temp_index=0;

    int a;
    while((a = (int)getc(fp))!=EOF)
    {
        if(a==13)
        {
            int num = 0;
            for(i=0;i<temp_index;i++)
            {
                num = num + (temp_num[i]* pow(10,temp_index-i-1));
            }
            nums[nums_index++] = num;
            temp_index = 0;
            a = (int)getc(fp);
        }
        else
        {
            temp_num[temp_index++] = a-48;
        }
    }
    int num = 0;
    for(i=0;i<temp_index;i++)
    {
        num = num + (temp_num[i]* pow(10,temp_index-i-1));
    }

    nums[nums_index++] = num;
    quick_sort(nums,0,9999);
    //printf("%d\n",partition(a,0,9,0));

    for(i=0;i<=9999;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\nTotal = %ld",total);

    return 0;
}
