#include<iostream>
#include<stdlib.h>
#include<stdio.h>



using namespace std;


typedef struct node
{
	int value;
	int left_height;
	int right_height;
	int height;
	int diff;
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
		return 0;
	}
	else
	{
		int a =  (max(height(h->left),height(h->right))+1);
		//cout<<a;
		return a;
	}
}
void insert(node** root,int ele,node** inserted_node)
{
	if(*root == NULL)
	{
		node* temp = (node*) malloc(sizeof(node));
		temp->value = ele;
		temp->left_height = 0;
		temp->right_height = 0;
		temp->height = 0;
		temp->left = NULL;
		temp->right = NULL;
		temp->diff = 0;
		*root = temp;
		*inserted_node = temp;
	}
	else if((*root)->value<ele)
	{
		insert(&(*root)->right,ele,inserted_node);
		(*root)->right_height = height((*root)->right);
		//cout<<"  "<<(*root)->right_height<<"\n";
		(*root)->right->parent = (*root);
		(*root)->height = max((*root)->left_height,(*root)->right_height);
		(*root)->diff = (*root)->left_height-(*root)->right_height;
	}
	else
	{
		insert(&(*root)->left,ele,inserted_node);
		(*root)->left_height = height((*root)->left);
		(*root)->left->parent = (*root);
		(*root)->height = max((*root)->left_height,(*root)->right_height);
		(*root)->diff = (*root)->left_height-(*root)->right_height;
	}
}

void inorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->value<<" "<<"("<<root->left_height<<","<<root->height<<","<<root->right_height<<") \n";
	inorder(root->right);
}

node* check_violated_node(node* head)
{
	if(head->diff>1 || head->diff <-1)
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
}

void left_rotation(node* n,node** head)
{
	node* y = (n)->right;
	node* x = (n);
	
	x->right = y->left;
	y->left = x;
	x->right_height = y->left_height;
	x->height = max(x->left_height,x->right_height)+1;
	y->left_height = x->height;
	y->height = max(y->left_height,y->right_height)+1;
	y->parent = x->parent;
	x->parent = y;
	node* temp = y;
	while(y->parent!=NULL)
	{
		node* p = y->parent;
		p->left_height == p->left->height+1;
	}
	if(y->parent == NULL)
	{
		*head = y;
	}
}

void update_heights(node* violated_node)
{
	
}

void AVL_insert(node** root,int ele)
{
	int side;
	node* inserted_node;
	insert(root,ele,&inserted_node);
	node* violated_node = check_violated_node(inserted_node);
	if(violated_node)
	{
		int a = check_rotation(violated_node);
		if(a==4)
		{
			left_rotation(violated_node,root);
			update_heights(violated_node);
		}
	}
	else
	{
		cout<<"No violation";
	}
}

int main()
{
	node* root = NULL;
	AVL_insert(&root,3);
	AVL_insert(&root,1);
	AVL_insert(&root,2);
	AVL_insert(&root,4);
	AVL_insert(&root,5);
	//inorder(root);
}
