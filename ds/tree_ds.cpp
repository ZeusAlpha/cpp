//Basic tree datastructure

#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct node Node;

struct node
{
	int value;
	Node *left, *right;
};

Node* insert(Node* root, int v)
{
	if(root == NULL)
	{
		root = (Node *)malloc(sizeof(Node));
		root->value = v;
		root->left = NULL;
		root->right = NULL;
	}
	else if(v<root->value)
	{
		root->left = insert(root->left, v);
	}
	else
	{
		root->right = insert(root->right, v);
	}
	return root;
}

int main()
{
	Node *root = NULL;
	int temp;
	cin >> temp;
	while(temp!=9999)
	{
		root = insert(root,temp);
		cin >> temp;
	}
}
