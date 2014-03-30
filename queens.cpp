#include<iostream>
#include<stdlib.h>
#define ROW 30
#define COL 30


using namespace std;

int row_array[ROW];

int check_safe(int a,int b)
{
	if(a==0)
	{
		return 1;
	}
	for(int i=0;i<a;i++)
	{
		if((row_array[i] == b) || (abs(b-row_array[i])==abs(a-i)))
		{
			return 0;
		}
	}
	return 1;
}

void printQueens(int a[ROW][COL])
{
	cout<<"Solution : \n";
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n";
	exit(0);
}

void nQueens(int a,int b,int array[ROW][COL])
{
	if(a==ROW)
	{
		printQueens(array);
		return;
	}
	for(int i=0;i<b;i++)
	{
		if(check_safe(a,i))
		{
			array[a][i] = 1;
			row_array[a] = i;
			nQueens(a+1,b,array);
			row_array[a] = -1;
			array[a][i] = 0;
		}
	}
}

int main()
{
	int array[ROW][COL];
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			array[i][j]=0;
		}
	}
	nQueens(0,COL,array);
}
