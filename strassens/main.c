#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define ROWS 100
#define COL 100

void naive_mul(int a[ROWS][ROWS],int b[ROWS][ROWS],int c[ROWS][ROWS])
{
    int i,j,k,temp_sum;
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<ROWS;j++)
        {
            temp_sum = 0;
            for(k=0;k<ROWS;k++)
            {
                temp_sum = temp_sum + (a[i][k]*b[k][j]);
            }
            c[i][j] = temp_sum;
        }
    }
}

void strassens_mul(int a[ROWS][ROWS],int b[ROWS][ROWS],int c[ROWS][ROWS],int a_i,int a_j,int b_i,int b_j)
{

}

int main()
{
    // Program to multiply two matrices
    int a[ROWS][COL],b[ROWS][COL],c[ROWS][COL];
    int i,j,k;
    int temp_sum = 0;
    printf("ENter the 1st mat\n");
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<ROWS;j++)
        {
            a[i][j] = rand()%1000;
        }
    }
        printf("ENter the 2nd mat\n");
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<ROWS;j++)
        {
            b[i][j] = rand()%1000;
        }
    }
    naive_mul(a,b,c);
    for(i=0;i<ROWS;i++)
    {
        for(j=0;j<ROWS;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

}
