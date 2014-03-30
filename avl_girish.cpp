#include<iostream>
#include<stdlib.h>
#include<stdio.h>



using namespace std;


typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
	struct node* parent;
}node;

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int height(node* h)
{
	if(h==NULL)
	{
		return -1;
	}
	else
	{
		int a = (max(height(h->left),height(h->right))+1);
		return a;
	}
}

void insert(node** root,int ele,node** inserted_node)
{
	if(*root == NULL)
	{
		node* temp = (node*) malloc(sizeof(node));
		temp->value = ele;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
		*inserted_node = temp;
	}
	else if((*root)->value<ele)
	{
		insert(&(*root)->right,ele,inserted_node);
		(*root)->right->parent = (*root);
	}
	else
	{
		insert(&(*root)->left,ele,inserted_node);
		(*root)->left->parent = (*root);
	}
}

void inorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->value<<" \n";
	inorder(root->right);
}

node* check_violated_node(node* head)
{
	int h1 = height(head->left);
	int h2 = height(head->right);
	if((h1-h2)>1 || (h1-h2)<-1)
	{
		return head;
	}
	else
	{
		if(head->parent!=NULL)
		{
			return check_violated_node(head->parent);
		}
		else
		{
			return NULL;
		}
	}
}

/*
int check_rotation(node* n)
{
	if(n->diff==2)
	{
		if(n->left->diff==-1)
		{
			cout<<"Left right Rotation";
			return 1;
		}
		else if(n->left->diff==1)
		{
			cout<<"Right Rotation";
			return 2;
		}
	}
	else if(n->diff==-2)
	{
		if(n->left->diff==-1)
		{
			cout<<"Right left Rotation";
			return 3;
		}
		else if(n->left->diff==1)
		{
			cout<<"Left rotation";
			return 4;
		}
	}
}/*/

void AVL_insert(node** root,int ele)
{
	node* inserted_node;
	insert(root,ele,&inserted_node);
	node* v = check_violated_node(inserted_node);
	
}

int main()
{
	node* root = NULL;
	AVL_insert(&root,3);
	AVL_insert(&root,1);
	AVL_insert(&root,2);
	AVL_insert(&root,4);
	AVL_insert(&root,5);
	inorder(root);
}
