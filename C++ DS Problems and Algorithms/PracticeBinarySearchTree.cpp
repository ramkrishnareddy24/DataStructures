#include<iostream>
using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
	Node(int k)
	{
		key=k;
		left=right=NULL;
	}
};

Node *recursiveInsert(Node *root,int x)
{
	Node *temp = new Node(x);
	if(root==NULL)
		return temp;
	else if(x<root->key)
		root->left=recursiveInsert(root->left,x);
	else
		root->right=recursiveInsert(root->right,x);
	return root;
}

Node *iterativeInsert(Node *root,int x)
{
	Node *temp = new Node(x);
	Node *parent = NULL,*curr=root;
	while(curr!=NULL)
	{
		parent=curr;
		if(x<curr->key)
			curr=curr->left;
		else if(x>curr->key)
			curr=curr->right;
		else
			return root;
	}

	if(parent==NULL)
		return temp;
	else if(x<parent->key)
		parent->left=temp;
	else
		parent->right=temp;
	return root;
}

bool recursiveSearch(Node *root,int x)
{
	if(root==NULL)
		return false;
	else if(x==root->key)
		return true;
	else
		if(x<root->key)
			return recursiveSearch(root->left,x);
		else if(x>root->key)
			return recursiveSearch(root->right,x);
}

bool iterativeSearch(Node *root,int x)
{
	while(root!=NULL)
	{
		if(root->key==x)
			return true;
		else if(x<root->key)
			root=root->left;
		else
			root=root->right;
	}
	return false;
}

void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

int main()
{
	Node *root=NULL;
	root  = recursiveInsert(root,15);
	root  = recursiveInsert(root,5);
	root  = recursiveInsert(root,20);
	root  = recursiveInsert(root,3);
	root  = recursiveInsert(root,18);
	root  = recursiveInsert(root,80);
	root  = recursiveInsert(root,16);
	root = iterativeInsert(root,12);
	inorder(root);
	cout<<recursiveSearch(root,5)<<endl;
	cout<<iterativeSearch(root,12)<<endl;
}