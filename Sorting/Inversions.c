#include<stdio.h>
#include<assert.h>
#define NO_OF_ELE 1000000

int merge(int a[],int start,int middle,int end)
{
    int i,j,k;
    i = start;
    int left_end = middle;
    j = middle+1;
    int right_end = end;
    int temp_index = 0;
    int temp[NO_OF_ELE];
    int size = end-start+1;
    long count= 0;
    for(k=0;k<size;k++)
    while((i<=left_end)&&(j<=right_end))
    {
        if(a[i]<a[j])
        {
            temp[temp_index++] = a[i++];
        }
        else
        {
            temp[temp_index++] = a[j++];
            count = count + (left_end-i+1);
        }
    }
    while(i<=left_end)
    {
        temp[temp_index++] = a[i++];
    }
    while(j<=right_end)
    {
        temp[temp_index++] = a[j++];
    }
    for(k=0;k<temp_index;k++)
    {
        a[start+k] = temp[k];
    }
    return count;
}

long mergesort(int a[],int start,int end)
{
    if(start==end)
    {
        return 0;
    }
    int middle = (start+end)/2;
    long aa = mergesort(a,start,middle);
    long b = mergesort(a,middle+1,end);
    long c = merge(a,start,middle,end);
    return aa+b+c;
}


int main()
{
    FILE *fp;
    int nums[100000];
    int nums_index=0;
    fp = fopen("/home/vamshi/int.txt","r");

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
    temp_index = 0;
    printf("%ld",mergesort(nums,0,99999));
}
