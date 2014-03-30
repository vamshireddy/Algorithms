#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define ELE 10

using namespace std;

int size;

int get_left(int index,int a[])
{
	int l = index*2;
	if(l>size)
	{
		return -999999;
	}
	else
	{
		return l;
	}
}

int get_parent(int a[],int index)
{
	int l = index/2;
	if(l<1)
	{
		return -99999;
	}
	else
	{
		return l;
	}
}

int get_right(int index,int a[])
{
	int l = index*2+1;
	if(l>size)
	{
		return -999999;
	}
	else
	{
		return l;
	}
}

void swap(int a,int b,int arr[])
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void bubble_down(int array[],int i)
{		int ind = i;
		while(1)
		{
			int left = get_left(ind,array);
			int right = get_right(ind,array);
			
			int min = ind;
			if(left>0 && array[left]<array[min])
			{
				min = left;
			}
			if(right>0 && array[right]<array[min])
			{
				min = right;
			}
			if(min==ind)
			{
				return;
			}
			else
			{
				swap(ind,min,array);
				ind = min;
			}
		}
}


void heapify(int array[])
{
	for(int i=ELE/2;i>0;i--)
	{
		bubble_down(array,i);
	}
}

void bubble_up(int array[],int i)
{
	int ind = i;
	int parent = get_parent(array,ind);
	while(parent>=1)
	{
		if(array[parent]>array[ind])
		{
			swap(parent,ind,array);
			ind = parent;
			parent = get_parent(array,ind);
		}
		else
		{
			break;
		}
	}
}

void insert_by_heapify(int array[],int ele)
{
	size++;
	array[size] = ele;
	heapify(array);
}

void insert_without_heapify(int array[],int ele)
{
	size++;
	array[size] = ele;
	bubble_up(array,size);
}

int extract_min_with_heapify(int array[])
{
	swap(1,size,array);
	int ele = array[size];
	size--;
	heapify(array);
	return ele;
}

int extract_min_without_heapify(int array[])
{
	swap(1,size,array);
	int ele = array[size];
	size--;
	bubble_down(array,1);
	return ele;
}

int main()
{
	int array[20] = {-1,1,5,7,11,4,3,6,67,8,9};
	size = 10;
	heapify(array);
	for(int i=1;i<=size;i++)
	{
		cout<<array[i]<<"\t";
	}
	insert_without_heapify(array,0);
	insert_without_heapify(array,-1000);
	cout<<"\n\n";
	while(size>0)
	{
		cout<<extract_min_without_heapify(array)<<"\t";
	}
}
