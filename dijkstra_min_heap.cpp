#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define NODES 5

using namespace std;

int size = 0;

typedef struct node
{
	int name;
	int weight;
	struct node* next;
}node;

typedef struct graph_node
{
	int name;
	int visited;
	int sp;
	struct node* list;
}graph_node;


void add_edge(int start,int w,int end,graph_node g[])
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->name = end;
	new_node->weight = w;
	new_node->next = NULL;
	
	node* list = g[start].list;
	if(list==NULL)
	{
		g[start].list = new_node;
	}
	else
	{
		new_node->next = g[start].list;
		g[start].list = new_node;
	}
}

void initGraph(graph_node g[])
{
	add_edge(0,2,1,g);
	add_edge(0,1,3,g);
	add_edge(1,2,0,g);
	add_edge(1,2,3,g);
	add_edge(1,1,2,g);
	add_edge(2,1,1,g);
	add_edge(2,1,3,g);
	add_edge(2,7,4,g);
	add_edge(3,2,1,g);
	add_edge(3,1,2,g);
	add_edge(3,1,0,g);
	add_edge(3,1,4,g);
	add_edge(4,7,2,g);
	add_edge(4,1,3,g);
}

void printGraph(graph_node g[])
{
	for(int i=0;i<NODES;i++)
	{
		node* temp = g[i].list;
		cout<<g[i].name<<"( sp : "<<g[i].sp<<" ) "<<" --> ";
		while(temp)
		{
			cout<<temp->name<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}
}

//-----------------------------------------------------------------------------------------

graph_node array[20];


int get_left(int index)
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


int get_right(int index)
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

void swapy(int a,int b)
{
	graph_node temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

void bubble_down(int i)
{		int ind = i;
		while(1)
		{
			int left = get_left(ind);
			int right = get_right(ind);
			
			int min = ind;
			if(left>0 && array[left].sp < array[min].sp)
			{
				min = left;
			}
			if(right>0 && array[right].sp < array[min].sp)
			{
				min = right;
			}
			if(min==ind)
			{
				return;
			}
			else
			{
				swapy(ind,min);
				ind = min;
			}
		}
}


void heapify()
{
	for(int i=size/2;i>0;i--)
	{
		bubble_down(i);
	}
}

graph_node extract_min_without_heapify()
{
	swapy(1,size);
	graph_node ele = array[size];
	size--;
	bubble_down(1);
	return ele;
}

int search_in_heap(int name,int weight)
{
	for(int i=0;i<size;i++)
	{
		if(array[i].name == name)
		{
			if(array[i].sp>weight)
			{
				array[i].sp = weight;
				return 1;
			}
		}
	}
}
void printHeap()
{
	for(int i=1;i<=size;i++)
	{
		cout<<array[i].name<<"("<<array[i].sp<<")"<<"\t";
	}
}

void dijkstra(graph_node g[],int start)
{
	g[start].sp = 0;
	for(int i=0;i<NODES;i++)
	{
		array[size++] = g[i];
	}
	heapify();
	while(size>0)
	{
		printHeap();
		cout<<"\n";
		graph_node min_node = extract_min_without_heapify();
		cout<<"Min node is "<<min_node.name<<"\n";
		min_node.visited = 1;
		g[min_node.name].sp = min_node.sp;
		node* temp = min_node.list;
		while(temp)
		{
			if(g[temp->name].visited==0)
			{
				search_in_heap(temp->name,temp->weight+min_node.sp);
			}
			temp = temp -> next;
		}
		heapify();
	}
}


int main()
{
	size = 0;
	graph_node g[NODES];
	for(int i=0;i<NODES;i++)
	{
		g[i].name = i;
		g[i].visited = 0;
		g[i].list = NULL;
		g[i].sp = 9999999;
	}
	initGraph(g);
	printGraph(g);
	dijkstra(g,3);
	printGraph(g);

}
