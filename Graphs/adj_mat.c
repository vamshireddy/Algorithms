#include<stdio.h>




int main()
{
	int mat[4][4];
	printf("Creating a Matrix!!! \n");
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			mat[i][j] = 0;
		}
	}
	mat[0][1] = 1;
	mat[1][2] = 1;
	mat[2][3] = 1;
	mat[3][0] = 1;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}
