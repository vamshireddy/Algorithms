#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct node
{
	int data;
	struct node* next;
	struct node* prev;
}node;


void insertFront(node** head,node** tail,int ele)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = ele;
	temp->prev = NULL;
	temp->next = NULL;
	
	if(*head==NULL)
	{
		*head = temp;
		*tail = temp;
	}
	else
	{
		temp->next = *head;
		temp->next->prev = temp;
		*head = temp;
	}
}

void insertRear(node** head,node** tail,int ele)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = ele;
	temp->prev = NULL;
	temp->next = NULL;
	if(*head==NULL)
	{
		*head = temp;
		*tail = temp;
	}
	else
	{
		(*tail)->next = temp;
		temp->prev->next = temp;
		*tail = temp;
	}
}

void deleteNode(node** head,node** tail,int no)
{
	

int main()
{
	
