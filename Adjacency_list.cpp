#include<iostream>
#define NODES 5
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


typedef struct queue
{
	int array[100];
	int count;
	int front;
	int rear;
	int max;
}queue;

int Queue_full(queue* q)
{
	if(q->count == q->max)
	{
		return 1;
	}
	return 0;
}

int Queue_empty(queue* q)
{
	if(q->count==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(queue* q,int n)
{
	if(!Queue_full(q))
	{
		q->array[q->rear++] = n;
		q->count++;
	}
	else
	{
		cout<<"Error\n";
	}
}

int dequeue(queue* q)
{
	if(!Queue_empty(q))
	{
		int t = q->array[q->front];
		q->front++;
		q->count--;
		return t;
	}
	else
	{
		cout<<"Error full\n";
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

void bfs_visit(graph_node g[],int n)
{
	queue q;
	q.front = 0;
	q.rear = 0;
	q.count = 0;
	q.max = QUEUE_MAX;
	int visit_count = 1;
	enqueue(&q,n);
	while(!Queue_empty(&q))
	{
		int n = dequeue(&q);
		node* temp = g[n].list;
		while(temp)
		{
			if(g[temp->name].visited==0)
			{
				g[temp->name].visited = visit_count++;
				g[temp->name].parent = n;
				enqueue(&q,temp->name);
			}
			temp = temp->next;
		}
	}
}

int visit_i = 2;

void dfs_visit(graph_node g[],int start)
{
	node* t = g[start].list;
	while(t)
	{
		if(g[t->name].visited==0)
		{
			g[t->name].visited = visit_i++;
			g[t->name].parent = start;
			dfs_visit(g,t->name);
		}
		t = t->next;
	}
}

void dfs(graph_node g[])
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

void bfs(graph_node g[])
{
	for(int i=0;i<NODES;i++)
	{
		if(g[i].visited==0)
		{
			g[i].visited = 1;
			bfs_visit(g,i);
		}
	}
}


void initGraph(graph_node g[])
{
	add_edge(0,0,4,g);
	add_edge(1,0,4,g);
	add_edge(1,0,3,g);
	add_edge(1,0,2,g);
	add_edge(4,0,0,g);
	add_edge(4,0,1,g);
	add_edge(4,0,3,g);
	add_edge(3,0,4,g);
	add_edge(3,0,1,g);
	add_edge(3,0,2,g);
	add_edge(2,0,1,g);
	add_edge(2,0,3,g);
}

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


int find_connected_components(graph_node g[])
{
	int comp = 0;
	for(int i=0;i<NODES;i++)
	{
		if(g[i].visited==0)
		{
			g[i].visited = 1;
			bfs_visit(g,i);
			comp++;
		}
	}
	return comp;
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
	cout<<"\n Connected components "<<find_connected_components(graph)<<"\n";
	printGraph(graph);
}
