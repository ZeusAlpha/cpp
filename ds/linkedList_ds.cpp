#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
} node;

node *create_ll(node *root, int key)
{
	if(root==NULL)
	{
		root = (node *)malloc(sizeof(root));
		root->data = key;
		root->next = NULL;
	}
	else
	{
		root->next = create_ll(root->next,key);
	}
	return root;
}

int main()
{
	node *root = NULL;
	int temp;
	cin >> temp;
	while(temp!=999)
	{
		root = create_ll(root,temp);
		cin >> temp;
	}
}
