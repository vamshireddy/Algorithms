#include<iostream>
#include<stdio.h>
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

void add_edge(graph_node g[],int start,int w,int end)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->name = end;
	new_node->next = NULL;
	new_node->weight = w;
	
	node* list = g[start].list;
	if(list == NULL)
	{
		g[start].list = new_node;
	}
	else
	{
		new_node->next = g[start].list;
		g[start].list = new_node;
	}
}

int main()
{
	graph_node g[NODES];
	for(int i=0;i<NODES;i++)
	{
		g[i].name = i;
		g[i].list = NULL;
	}
}
