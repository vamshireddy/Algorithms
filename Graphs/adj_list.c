#include<stdio.h>
#include<stdlib.h>
#define NO_OF_NODES 4
struct graph
{
	int node;
	struct node* list;
};

struct node
{
	int val;
	struct node* next;
};

typedef struct node* nptr;
typedef struct graph* gpt;

nptr insert(node* n,int ele)
{

	nptr temp = (node*)malloc(sizeof(node));
	temp->val = ele;
	temp->next = NULL;
	if(n==NULL)
	{
		return temp;
	}
	else
	{
		temp->next = n;
		return temp;
	}
}
	
nptr delete_node(node *g,int ele)
{
	nptr prev = NULL;
	nptr cur = g;
	if(cur->val==ele)
	{
		printf("node deleted\n");
		return cur->next;
	}
	while(cur!=NULL)
	{
		if(cur->val == ele)
		{
			prev->next = cur->next;
			free(cur);
			printf("Node deleted!\n");
			return g;	
		}	
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void populate_graph(graph *g,int len)
{

	g[0].list = insert(((g)+0)->list,2);
	g[0].list = insert(((g)+0)->list,3);
	g[0].list = insert(((g)+0)->list,4);
	g[0].list = insert(((g)+0)->list,2);
	g[0].list = insert(((g)+0)->list,2);
	g[1].list = insert(((g)+1)->list,3);
	g[3].list = insert(((g)+3)->list,1);
	g[3].list = insert(((g)+3)->list,2);
}
void print_graph(graph *g)
{
	int i,j;
	for(i=0;i<NO_OF_NODES;i++)
	{
		printf("Node is %d\n",g[i].node);
		nptr temp = g[i].list;
		while(temp->next!=NULL)
		{
			printf("Adj %d\n",temp->val);
			temp = temp->next;
		}
	}
}
int main()
{
	struct graph g[NO_OF_NODES];
	int i,j;
	for(i=0;i<NO_OF_NODES;i++)
	{
		g[i].node = i+1;
		g[i].list = (node*)malloc(sizeof(node));
		g[i].list->val = -1;
		g[i].list->next = NULL;
	}
	//populate_graph(g,4);
	print_graph(g);
}
