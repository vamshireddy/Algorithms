#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        int name;
        int weight;
        struct node* next;
}node;

typedef struct graph_node
{
        int sp;
        int name;
        int visited_flag;
        struct node* list;
}graph_node;

int add_node(graph_node g[],int node_val,node* n)
{
        node* temp = g[node_val].list;
        g[node_val].list = n;
        n->next = temp;
}

void dijkstras(graph_node g[],int length)
{
        graph_node v_visited[length];
        int v_ind = 0;
        int min_span = 0;
        v_visited[v_ind++] = g[0];
        g[0].visited_flag = 1;
        g[0].sp = 0;
        int i,j;
        while(v_ind<length)
        {
                int edge_start;
                int edge_end;
                int min = 999999;
                for(i=0;i<v_ind;i++)
                {
                        node* l = v_visited[i].list;
                        while(l)
                        {
                                
                                if(g[l->name].visited_flag==0)
                                {
                                        if(v_visited[i].sp+l->weight<min)
                                        {
                                                edge_start = v_visited[i].name;
                                                min = v_visited[i].sp+l->weight;
                                                edge_end = l->name;
                                        }
                                }
                                l = l->next;
                        }
                 }
                 v_visited[v_ind++] = g[edge_end];
                 g[edge_end].visited_flag = 1;
                 g[edge_end].sp = min;
                 printf("Spanning Edge : %d---%d\n and weight %d\n",edge_start,edge_end,min);
         }
         printf("Min span = %d\n",min_span);
}                                
                                
                                


int main()
{
        int nodes = 3;
        graph_node g[nodes];
        int i=0;
        for(i=0;i<nodes;i++)
        {
                g[i].name = i+1;
                g[i].list = NULL;
                g[i].visited_flag = 0;
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
        
        for(i=0;i<nodes;i++)
        {
                printf("%d  --> ",i+1);
                node* tt = g[i].list;
                while(tt)
                {
                        printf("%d(%d)   ",tt->name,tt->weight); 
                       tt = tt->next;
                }
                printf("\n");
        }
        dijkstras(g,nodes);
        for(i=0;i<nodes;i++)
        {
                printf("Shortest path of %d is : %d\n",i,g[i].sp);
        }
}

