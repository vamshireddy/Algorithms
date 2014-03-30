#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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
	int visited;
	int parent;
	struct node* list;
}graph_node;

void add_edge(int start,int weight,int end,graph_node g[])
{
	node* temp = (node*) malloc(sizeof(node));
	temp->name = end;
	temp->weight = weight;
	temp->next = NULL;
	node* list = g[start].list;
	if(list==NULL)
	{
		g[start].list = temp;
	}
	else
	{
		temp->next = g[start].list;
		g[start].list = temp;
	}
}

int visited_list[NODES];
int visited_count = 0;

void max_spanning_tree(graph_node g[],int start)
{
	int count = 1;
	g[start].visited = count++;
	g[start].parent = 0;
	visited_list[visited_count++] = start;
	while(visited_count<NODES)
	{
		int max = -999999;
		int max_vertex,parent_vertex;
		for(int i=0;i<visited_count;i++)
		{
			node* temp = g[visited_list[i]].list;
			while(temp)
			{
				if(g[temp->name].visited == 0 && temp->weight > max)
				{
					max = temp->weight;
					max_vertex = temp->name;
					parent_vertex = visited_list[i];
				}
				temp = temp->next;
			}
		}
		if(max==-999999)
		{
			return;
		}
		visited_list[visited_count++] = max_vertex;
		g[max_vertex].visited = count++;
		g[max_vertex].parent = parent_vertex;
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

void printGraph(graph_node g[])
{
	for(int i=0;i<NODES;i++)
	{
		cout<<"\n"<<"visited : "<<g[i].visited<<" Parent : "<<g[i].parent<<"\n";
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
		g[i].name = i;
		g[i].parent = 0;
		g[i].list = NULL;
		g[i].visited = 0;
	}
	initGraph(g);
	int start = 1;
	max_spanning_tree(g,start);
	printGraph(g);
}
