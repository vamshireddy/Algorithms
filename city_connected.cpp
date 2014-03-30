#include<iostream>
#define NODES 9
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
	int sp;
	struct node* list;
}graph_node;


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

void find_shortest_path(graph_node g[],int start,int end)
{
	g[start].sp = 0;
	g[start].parent = -1;
	g[start].visited = 1;
	int vertex_list[NODES];
	int vertex_list_counter=0;
	
	
	vertex_list[vertex_list_counter++] = start;
	
	
	while(vertex_list_counter<=NODES)
	{
		int min = 999999;
		int min_vertex = -1;
		int prev_vertex;
		for(int i=0;i<vertex_list_counter;i++)
		{
			node* temp = g[vertex_list[i]].list;
			while(temp)
			{
				if(g[temp->name].visited==0 && temp->weight + g[vertex_list[i]].sp < min)
				{
					min = temp->weight + g[vertex_list[i]].sp;
					min_vertex = temp->name;
					prev_vertex = vertex_list[i];
				}
				temp = temp->next;
			}
		}
		if(min_vertex==-1)
		{
			break;
		}
		g[min_vertex].sp = min;
		g[min_vertex].parent = prev_vertex;
		cout<<"Min is "<<min<<" "<<"Min vertex is : "<<min_vertex<<"\n";
		g[min_vertex].visited = 1;
		vertex_list[vertex_list_counter++] = min_vertex;
	}
	if(g[end].sp > 99999)
	{
		cout<<"There is no path between "<<start<<" and "<<end<<"\n";
	}
	else
	{
		cout<<"Shortest path between "<<start<<" and "<<end<<" is "<<g[end].sp<<"\n";
	}
}


int vertex_list[100];
int vertex_count = 0;
// Global hamstart variable for detecting the path from source to same source in DFS
int dest = 0;


void printList()
{
	for(int i=0;i<vertex_count;i++)
	{
		cout<<vertex_list[i]<<" -- ";
	}
	cout<<"\n";
}

void findPaths(graph_node g[],int start)
{
	vertex_list[vertex_count++] = start;
	g[start].visited = 1;
	node* temp = g[start].list;
	// Get the Adj list and iterate over all of the nodes and call the function of they are not the source
	while(temp)
	{
		if(temp->name==dest)
		{
			vertex_list[vertex_count++] = temp->name;
			printList();
			vertex_count--;
		}
		else if(g[temp->name].visited == 0)
		{
			findPaths(g,temp->name);
		}
		temp = temp->next;
	}
	g[start].visited = 0;
	vertex_count--;
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
		cout<<"Parent : "<<g[i].parent<<"\n"<<"visited : "<<g[i].visited<<"\n"<<"Shortest path : "<<g[i].sp<<"\n";
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
	graph_node graph[NODES];
	
	for(int i=0;i<NODES;i++)
	{
		graph[i].name = i;
		graph[i].list = NULL;
		graph[i].visited = 0;
		graph[i].sp = 999999;
	}
	initGraph(graph);
	find_shortest_path(graph,0,4);
	for(int i=0;i<NODES;i++)
	{
		graph[i].name = i;
		graph[i].list = NULL;
		graph[i].visited = 0;
		graph[i].sp = 999999;
	}
	initGraph(graph);
	dest = 1;
	cout<<"These are the following paths : \n";
	findPaths(graph,0);
}
