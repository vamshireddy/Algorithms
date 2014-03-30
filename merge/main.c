#include<stdio.h>
#include<assert.h>
#define NO_OF_ELE 1000000

int inversions(int a[],int size)
{
    long inv = 0;
    int i,j;
    for(i=0;i<=size;i++)
    {
        for(j=i+1;j<=size;j++)
        {
            if(a[i]>a[j])
            {
                inv++;
            }
        }
    }
    return inv;
}

int main()
{
    printf("Asf");
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
    printf("Started.......!");
    long n = inversions(nums,100000);
    printf("ld",n);
}
