#include<iostream>
#include<stdlib.h>
#define NODES 4

using namespace std;

typedef struct node
{
	int name;
	int weight;
	node* next;
}node;

typedef struct graph_node
{
	int name;
	node* list;
}graph_node;

void add_edge(int a,int w,int b,graph_node g[])
{
	node* new_node = (node*) malloc(sizeof(node));
	new_node->name = b;
	new_node->weight = w;
	new_node->next = NULL;
	
	node* temp = g[a].list;
	if(!temp)
	{
		g[a].list = new_node;
		return;
	}
	else
	{
		new_node->next = g[a].list;
		g[a].list = new_node;
	}	
}

void initGraph(graph_node g[])
{
	add_edge(1,1,0,g);
	add_edge(2,1,1,g);
	add_edge(2,1,3,g);
	add_edge(2,4,0,g);
	add_edge(3,5,0,g);
}

int table[NODES];

int dynamic_sp_of_DAG(int start,graph_node g[])
{
	if(g[start].list == NULL)
	{
		table[start] = 0;
		return 0;
	}
	else
	{
		node* temp = g[start].list;
		int min = 99999;
		while(temp)
		{
			int a = temp->weight + dynamic_sp_of_DAG(temp->name,g);
			if(a<min)
			{
				min = a;
			}
			temp = temp->next;
		}
		table[start] = min;
		return min;
	}
}
void printGraph(graph_node g[])
{
	for(int i=0;i<NODES;i++)
	{
		//cout<<"\n"<<"visited : "<<g[i].visited<<"\n";
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
		g[i].list = 0;
	}
	initGraph(g);
	printGraph(g);
	int a;
	cout<<"Shortest Path for which vertex in DAG : ";
	cin>>a;
	cout<<"Shortest path of "<<a<<" is "<<dynamic_sp_of_DAG(a,g)<<endl;
}
