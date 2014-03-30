#include<stdio.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

typedef struct node* nptr;

typedef struct queue
{
	int front;
	int rear;
	nptr a[40];
}que;

que q;

void insertque(nptr ele)
{
	if(q.rear!=39)
	{
		q.a[++(q.front)] = ele;
	}
}

nptr deleteque()
{
	if(q.front<q.rear)
	{
		return q.a[++(q.front)];
	}
}

void levelorder(nptr root)
{
	if(root==NULL)
	return;
	insertque(root);
	while(!(q.front>q.rear))
	{
		nptr cur = deleteque();
		printf("%d",cur->data);
		if(cur->left)
		insertque(cur->left);
		if(cur->right)
		insertque(cur->right);
	}
}

int leaves(nptr root)
{
	if(root==NULL)
	return 0;
	else if(root->left==NULL && root->right==NULL)
	{
		printf("leaf : %d\n",root->data);
		return 1;
	}
	else
	{
		return (leaves(root->left) + leaves(root->right));
	}
}

int nodes(nptr root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		return (nodes(root->left) + 1 + nodes(root->right));
	}
}

nptr insert(nptr root, int ele)
{
	if(root==NULL)
	{
		root = (nptr) malloc(sizeof(node));
		root->data=ele;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		if(ele < root->data)
		{
			root->left = insert(root->left,ele);
		}
		else if (ele>root->data)
		{
			root->right = insert(root->right,ele);
		}
	}
	return root;
}

void display(nptr root)
{
	if(root==NULL)
	{
		return;
	}
	display(root->left);
	printf("%d ",root->data);
	display(root->right);
}

int max(nptr root)
{
	if(root->right==NULL)
	{
		return root->data;
	}
	else
	{
		return max(root->right);
	}
}


nptr deletenode(nptr root,int ele)
{
	if(root == NULL)
	{
		printf("Element not  in the tree \n");
	}
	else if(ele < root->data)
	{
			root->left = deletenode(root->left,ele);
	}
	else if( ele> root->data)
	{
			root->right = deletenode(root->right,ele);
	}
	else
	{
		nptr temp=root;
		if(root->left && root->right)
		{
			int temp = max(root->left);
			root->data = temp;
			root->left = deletenode(root->left,temp);
		}
		else
		{
			if(root->left ==NULL)
			{
				root = root->right;
				free(temp);
			}
			else if (root->right == NULL)
			{
				root= root->left;
				free(temp);
			}
		}

	}
	return root;
}


int depth(nptr root)
{
	if(root==NULL)
	return 0;
	else
	{
		int left,right;
		left = 1+depth(root->left);
		right= 1+depth(root->right);

		if(left > right)
		return left;
		else
		return right;
	}
}

int main()
{
	printf("Enter the option \n1.INSERT\n2.DISPLAY\n3.DELETE\n4.DEPTH\n5.LEVELERSAL\n6.LEAVES\n7.NODES\n");
	int option;
	nptr root=NULL;
	int ele;
	q.front=-1;
	q.rear=-1;
	while(1)
	{
		scanf("%d",&option);
		switch(option)
		{
			case 1 :printf("Enter the element to be inserted to BST " );
					scanf("%d",&ele);
					root = insert(root,ele);
					break;
			case 2 :printf("THe elements are \n");
					display(root);
					break;
			case 3 :printf("Enter Element to be deleted \n");
					scanf("%d",&ele);
					deletenode(root,ele);
					break;
			case 4 : printf("Depth : %d",depth(root));
					break;
			case 5 : printf("LEVEL ORDER TRAVERSAL : \n");
					levelorder(root);
					break;
			case 6 : printf("LEAVES : %d",leaves(root));
					break;
			case 7 : printf("NODES  : %d",nodes(root));

					break;
		}
	}


}
