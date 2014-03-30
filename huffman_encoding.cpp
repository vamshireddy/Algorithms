// huffman encoding to reduce the enciding size of a string
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node
{
	char character;
	int prob;
	node* next;
	node* prev;
	node* left;
	node* right;
}node;


node* add_node(node* head,node* temp)
{
	if(head==NULL)
	{
		return temp;
	}
	else
	{
		temp->next = head;
		temp->next->prev = temp;
		return temp;
	}
}

void printList(node* head)
{
	while(head)
	{
		cout<<head->character<<"  and "<<head->prob<<" \n";
		head = head->next;
	}
}

node* pick_min_node(node** head)
{
	node* cur = *head;
	node* min_node = NULL;
	int min = 99999;
	while(cur)
	{
		if(cur->prob <= min)
		{
			min = cur->prob;
			min_node = cur;
		}
		cur = cur->next;
	}
	if(min_node == NULL)
	{
		cout<<"No elements in list";
		return NULL;
	}
	else
	{
		if(min_node->next == NULL && min_node->prev!=NULL)
		{
			min_node->prev->next = NULL;
		}
		if(min_node->prev == NULL && min_node->next!=NULL)
		{
			min_node->next->prev = NULL;
			*head = min_node->next;
		}
		else if(min_node->prev != NULL && min_node->next != NULL)
		{
			min_node->prev->next = min_node->next;
			min_node->next->prev = min_node->prev;
		}
		min_node->prev = NULL;
		min_node->next = NULL;
		return min_node;
	}
}

node* make_huffman_tree(node** head)
{
	// atleast one node should be there in the tree
	node* n1 = pick_min_node(head);
	node* n2 = pick_min_node(head);
	if(!n1 || !n2)
	{
		return n1;
	}
	do
	{
		 node* temp = (node*)malloc(sizeof(node));
		 temp->left = n1;
		 temp->right = n2;
		 temp->next = NULL;
		 temp->prev = NULL;
		 temp->prob = n1->prob+n2->prob;
		 add_node(*head,temp);
		 printList(*head);
		 n1 = pick_min_node(head);
		 n2 = pick_min_node(head);
	}while(n1 && n2);	
	return n1;
}

int arr[100];
int arr_count = 0;

void print()
{
	for(int i=0;i<arr_count;i++)
	{
		cout<<arr[i];
	}
	cout<<"\n";
}
void printPaths(node* tree)
{
	if(tree->left == NULL && tree->right==NULL)
	{
		cout<<tree->character;
		print();
		return;
	}
	else
	{
		arr[arr_count++] = 0;
		printPaths(tree->left);
		arr_count--;
		arr[arr_count++] = 1;
		printPaths(tree->right);
		arr_count--;
	}
}
		
		
		

int main()
{
	cout<<"Enter Number of Characters\n";
	int no;
	cin>>no;
	char char_array[no];
	int probabilities[no];
	node* head = NULL;
	for(int i=0;i<no;i++)
	{
		cout<<"Enter the char and probability in % ";
		cin>>char_array[i];
		cin>>probabilities[i];
		node* temp = (node*)malloc(sizeof(node));
		temp->character = char_array[i];
		temp->prob = probabilities[i];
		temp->left = NULL;
		temp->right = NULL;
		temp->next = NULL;
		temp->prev = NULL;
		head = add_node(head,temp);
	}
	//printList(head);
	node* tree = make_huffman_tree(&head);
	//printPaths(tree);
}
	
