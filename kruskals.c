#include<stdio.h>

typedef struct union_find_node
{
    int name;
    int count;
    int leader;
}uf_node;

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
    struct node* list;
}graph_node;

int find()
{

}

int add_node(graph_node g[],int node_val,node* n)
{
        node* temp = g[node_val].list;
        g[node_val].list = n;
        n->next = temp;
}

int main()
{
        int nodes = 4;
        graph_node g[nodes];
        int i=0;
        for(i=0;i<nodes;i++)
        {
                g[i].name = i;
                g[i].list = NULL;
                printf("Enter How many nodes are adjacent to %d node: ",i);
                int no;
                scanf("%d",&no);
                while(no)
                {
                        node* t = (node*)malloc(sizeof(node));
                        printf("Enter the node name : ");
                        scanf("%d",&(t->name));
                        printf("Enter the weight \n");
                        scanf("%d",&(t->weight));
                        t->next = NULL;
                        add_node(g,i,t);
                        no--;
                }
        }
}
