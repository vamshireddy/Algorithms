#include<iostream>
#define NODES 4
#include<stdlib.h>
#define QUEUE_MAX 100;

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

void printGraph(graph_node g[])
{
	for(int i=0;i<NODES;i++)
	{
		cout<<"Parent : "<<g[i].parent<<"\n"<<"visited : "<<g[i].visited<<"\n";
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

void add_edge(int i,int w,int j,graph_node g[])
{
	node* temp = g[i].list;
	
	node* new_node = (node*) malloc(sizeof(node));
	new_node->name = j;
	new_node->weight = w;
	new_node->next=NULL;
	if( temp==NULL)
	{
		g[i].list = new_node;
		return;
	}
	else
	{
		g[i].list = new_node;
		new_node->next = temp;
		return;
	}
}

void initGraph(graph_node g[])
{
	add_edge(0,0,1,g);
	add_edge(1,0,2,g);
	add_edge(0,0,2,g);
	add_edge(1,0,3,g);
	add_edge(2,0,3,g);
	add_edge(3,0,0,g);
}

void dfs_visit(graph_node g[],int start)
{
	node* t = g[start].list;
	while(t)
	{
		if(g[t->name].visited>0)
		{
			cout<<"Cycle detected!! \n";
		}
		else if(g[t->name].visited==0)
		{
			g[t->name].visited = 1;
			g[t->name].parent = start;
			dfs_visit(g,t->name);
		}
		t = t->next;
	}
	g[start].visited = 0;
}

int detect_cycle(graph_node g[])
{
	for(int i=0;i<NODES;i++)
	{
		if(g[i].visited==0)
		{
			g[i].visited = 1;
			dfs_visit(g,i);
		}
	}
}

int main()
{
	graph_node graph[NODES];
	
	for(int i=0;i<NODES;i++)
	{
		graph[i].name = i;
		graph[i].list = NULL;
		graph[i].visited = 0;
	}
	initGraph(graph);
	detect_cycle(graph);
	printGraph(graph);
}
