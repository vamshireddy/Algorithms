#include<iostream>
#include<stdlib.h>
#define NODES 4

using namespace std;

typedef struct node
{
	int name;
	node* next;
}node;


typedef struct graph_node
{
	int name;
	int visited;
	node* list;
}graph_node;

void printGraph(graph_node g[])
{
	for(int i=0;i<NODES;i++)
	{
		cout<<"\n"<<"visited : "<<g[i].visited<<"\n";
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


void add_edge(graph_node g[],int start,int end)
{
	node* temp = g[start].list;
	node* n = (node*)malloc(sizeof(node));
	n->name = end;
	n->next = NULL;
	
	if(temp==NULL)
	{
		g[start].list = n;
	}
	else
	{
		n->next = temp;
		g[start].list = n;
	}
}

void initGraph(graph_node g[])
{
	add_edge(g,0,1);
	add_edge(g,0,3);
	add_edge(g,0,2);
	
	add_edge(g,1,0);
	add_edge(g,1,3);
	add_edge(g,1,2);
	
	add_edge(g,2,1);
	add_edge(g,2,3);
	add_edge(g,2,0);
	
	add_edge(g,3,0);
	add_edge(g,3,1);
	add_edge(g,3,2);
}

int vertex_list[100];
int vertex_count = 0;
// Global hamstart variable for detecting the path from source to same source in DFS
int ham_start = 0;

void printList()
{
	if(vertex_count==NODES)
	{
		cout<<"Hamil path: ";
		for(int i=0;i<vertex_count;i++)
		{
			cout<<vertex_list[i]<<" -- ";
		}
	}
	cout<<"\n";
}

void findHam(graph_node g[],int start)
{
	g[start].visited = 1;
	node* temp = g[start].list;
	// Get the Adj list and iterate over all of the nodes and call the function of they are not the source
	while(temp)
	{
		if(temp->name==ham_start)
		{
			vertex_list[vertex_count++] = temp->name;
			printList();
			vertex_count--;
		}
		else if(g[temp->name].visited == 0)
		{
			vertex_list[vertex_count++] = temp->name;
			findHam(g,temp->name);
		}
		temp = temp->next;
	}
	g[start].visited = 0;
	vertex_count--;
}

int main()
{
	graph_node g[NODES];
	for(int i=0;i<NODES;i++)
	{
		g[i].name = i;
		g[i].list = NULL;
		g[i].visited = 0;
	}
	initGraph(g);
	printGraph(g);
	vertex_list[vertex_count++] =0;
	findHam(g,0);
}
