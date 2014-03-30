#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define NODES 9

using namespace std;

typedef struct node
{
	int name;
	int weight;
	struct node* next;
}node;

typedef struct graph_node
{
	int name;
	int shortest_path;
	int visited;
	int parent;
	struct node* list;
}graph_node;

void add_edge(int start,int w,int end,graph_node g[])
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->name = end;
	new_node->weight = w;
	new_node->next = NULL;
	node* temp = g[start].list;
	if(temp==NULL)
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
	add_edge(0,1,1,g);
	add_edge(0,5,3,g);
	add_edge(1,1,0,g);
	add_edge(1,2,3,g);
	add_edge(1,1,2,g);
	add_edge(2,1,1,g);
	add_edge(2,1,3,g);
	add_edge(2,7,4,g);
	add_edge(3,2,1,g);
	add_edge(3,1,2,g);
	add_edge(3,5,0,g);
	add_edge(3,1,4,g);
	add_edge(4,7,2,g);
	add_edge(4,1,3,g);
	// seond graph
	add_edge(5,4,6,g);
	add_edge(5,1,7,g);
	add_edge(6,4,5,g);
	add_edge(6,2,7,g);
	add_edge(6,1,8,g);
	add_edge(8,1,7,g);
	add_edge(8,1,6,g);
	add_edge(7,1,5,g);
	add_edge(7,2,6,g);
	add_edge(7,1,8,g);
}

int vertex_list[NODES];
int vertex_count=0;

void dijkstra(graph_node g[],int start)
{
	int count = 1;
	g[start].visited = count++;
	g[start].shortest_path = 0;
	vertex_list[vertex_count++] = start;
	g[start].parent = -1;
	while(vertex_count<NODES)
	{
		int min = 99999;
		int parent_vertex,min_vertex;
		for(int i=0;i<vertex_count;i++)
		{
			node* temp = g[vertex_list[i]].list;
			while(temp)
			{
				int a = g[vertex_list[i]].shortest_path + temp->weight;
				if(g[temp->name].visited==0 && a<min)
				{
					min = a;
					min_vertex = temp->name;
					parent_vertex = vertex_list[i];
				}
				temp = temp->next;
			}
		}
		if(min==99999)
		{
			return;
		}
		g[min_vertex].shortest_path = min;
		g[min_vertex].parent = parent_vertex;
		g[min_vertex].visited = count++;
		vertex_list[vertex_count++] = min_vertex;
	}
}

void printGraph(graph_node g[])
{
	for(int i=0;i<NODES;i++)
	{
		cout<<"\n"<<"visited : "<<g[i].visited<<" sp : "<<g[i].shortest_path<<"\n";
		cout<<"\t\t"<<g[i].name<<" ----> ";
		node* temp = g[i].list;
		while(temp)
		{
			cout<<temp->name<<" "<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}
}

int main()
{
	graph_node g[NODES];
	for(int i=0;i<NODES;i++)
	{
		g[i].list = NULL;
		g[i].name = i;
		g[i].shortest_path = -1;
		g[i].visited = 0;
		g[i].parent = 0;
	}
	initGraph(g);
	//printGraph(g);
	int start = 2;
	dijkstra(g,start);
	printGraph(g);
}
