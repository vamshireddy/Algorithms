#include<stdio.h>
#define VERTICES 10
#define EDGES 10
typedef struct node
{
    int name;
    struct node* next;
}node;

int main()
{

    node graph[VERTICES];
    int i;
    for(i=0;i<VERTICES;i++)
    {
        graph[i].name = i+1;
        graph[i].next = NULL;
    }
}
