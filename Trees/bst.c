#include<stdio.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
}node;

typedef struct node* nptr;

nptr insert(nptr root,int ele)
{
    if(root==NULL)
    {
        nptr temp = (nptr)malloc(sizeof(node));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = ele;
        temp->parent = NULL;
        return temp;
    }
    else if(root->data<ele)
    {
        root->right = insert(root->right,ele);
        root->right->parent = root;
    }
    else if(ele<root->data)
    {
        root->left = insert(root->left,ele);
        root->left->parent = root;
    }
    return root;
}

void inorder(nptr root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int min(nptr root)
{
    if(root==NULL)
    {
        printf("\nNo min keys!!\n");
        return;
    }
    while(root->left!=NULL)
    {
        root = root->left;
    }
   return root->data;
}

int max(nptr root)
{
    if(root==NULL)
    {
        printf("\nNo max keys!!\n");
        return;
    }
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root->data;
}

nptr max_pointer(nptr root)
{
    if(root==NULL)
    {
        printf("\nNo max keys!!\n");
        return;
    }
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

void predecessor(nptr root,int ele)
{
    if(root==NULL)
    {
        printf("No elements!!");
        return;
    }
    else if(root->data<ele)
    {
        predecessor(root->right,ele);
    }
    else if(root->data>ele)
    {
        predecessor(root->left,ele);
    }
    else
    {
        if(root->left!=NULL)
        {
            int p =  max(root->left);
            printf("Predecessor is %d\n",p);
            return;
        }
        else
        {
            root = root->parent;
            while(root!=NULL && root->data>ele)
            {
                root = root->parent;
            }
            if(root == NULL)
            {
                printf("No predecessors!!!\n");
                return;
            }
            int p =  root->data;
            printf("Predecessor is %d\n",p);
            return;
        }
    }
}

void successor(nptr root,int ele)
{
    if(root==NULL)
    {
        printf("Element Not found!!!\n");
        return;
    }
    else if(root->data == ele)
    {
        if(root->right!=NULL)
        {
            int p = min(root->right);
            printf("Successor %d !\n",p);
            return;
        }
        else
        {
            root = root->parent;
            while(root!=NULL && root->data<ele)
            {
                root = root->parent;
            }
            if(root==NULL)
            {
                printf("No successor!!\n");
                return;
            }
            else
            {
                printf("Successor %d!\n",root->data);
                return;
            }
        }

    }
    else if(root->data < ele)
    {
        successor(root->right,ele);
    }
    else if(root->data > ele)
    {
        successor(root->left,ele);
    }
}


int search(nptr root,int ele)
{
    if(root==NULL)
    {
        printf("Not found!!\n");
        return -1;
    }
    else if(root->data == ele)
    {
        printf("Found!!! \n");
        return 1;
    }
    else if(root->data<ele)
    {
        search(root->right,ele);
    }
    else
    {
        search(root->left,ele);
    }
}


nptr delete_node(nptr root,int ele)
{
    if(root==NULL)
    {
        printf("Nothing to delete!\n");
        return NULL;
    }
    else if(root->data == ele)
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        if(root->right==NULL && root->left!=NULL)
        {
            nptr temp = root->left;
            free(root);
            return temp;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            nptr temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            nptr min = max_pointer(root->left);
            int temp = min->data;
            min->data = root->data;
            root->data = temp;
            root->left = delete_node(root->left,min->data);
        }
    }
    else if(root->data<ele)
    {
        root->right = delete_node(root->right,ele);
    }
    else if(root->data>ele)
    {
        root->left = delete_node(root->left,ele);
    }
    return root;
}

nptr stack[100];
int index = -1;

void inorder_iter(nptr root)
{
    stack[++index] = root;
    while(index>-1)
    {
        nptr cur = stack[index];
        if(cur->left != NULL)
        {
            stack[++index] = cur->left;
            continue;
        }
        else if(cur->right !=NULL)
        {
            stack[++index] = cur->right;
            continue;
        }
        else
        {
            printf("%d ",cur->data);
            index--;
        }
    }

}

int main()
{
    nptr root = (nptr)malloc(sizeof(node));
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,40);
    root = insert(root,30);
    root = insert(root,45);
    inorder(root);
    printf("\n");
    root = delete_node(root,40);
    inorder(root);

}
