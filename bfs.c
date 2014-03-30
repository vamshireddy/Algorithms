#include<stdio.h>
#define VERTICES 6
#define EDGES 10

typedef struct node
{
    int name;
    int visited;
    struct node* next;
}node;

void add_edge(int vertex1,int vertex2,node g[])
{
    node* temp = (node*)malloc(sizeof(node));
    temp->visited = 0;
    temp->name = vertex2;
    node *np = g[vertex1-1].next;
    g[vertex1-1].next = temp;
    temp->next = np;
}

void print(node g[])
{
    printf("GRAPH\n");
    node* temp;
    int i,j;
    for(i=0;i<VERTICES;i++)
    {
        printf("%d (%d) --> ",g[i].name,g[i].visited);
        temp = g[i].next;
        while(temp!=0)
        {
            printf("%d ",temp->name,temp->visited);
            temp = temp->next;
        }
        printf("\n");
    }
}

int count = 0;

void DFS_visit(node graph[],int start_vertex)
{
    int i,j;
    node* temp = graph[start_vertex].next;
    while(temp!=0)
    {
        if(graph[temp->name-1].visited==0)
        {
            graph[temp->name-1].visited = count++;
            DFS_visit(graph,temp->name-1);
        }
        temp = temp->next;
    }
}

void DFS(node graph[])
{
    int i;
    for(i=0;i<VERTICES;i++)
    {
        if(graph[i].visited == 0)
        {
            DFS_visit(graph,i);
        }

    }
}


void BFS(node graph[])
{
    int i
}

int main()
{

    node graph[VERTICES];
    int i;
    for(i=0;i<VERTICES;i++)
    {
        graph[i].name = i+1;
        graph[i].next = NULL;
        graph[i].visited = 0;
    }
    add_edge(1,3,graph);
    add_edge(3,1,graph);
    add_edge(4,3,graph);
    add_edge(3,4,graph);
    add_edge(1,4,graph);
    add_edge(4,1,graph);
    add_edge(3,6,graph);
    add_edge(6,3,graph);
    add_edge(6,5,graph);
    add_edge(5,6,graph);
    add_edge(6,2,graph);
    add_edge(2,6,graph);
    add_edge(5,2,graph);
    add_edge(2,5,graph);
        print(graph);
    DFS(graph);
    print(graph);
}



