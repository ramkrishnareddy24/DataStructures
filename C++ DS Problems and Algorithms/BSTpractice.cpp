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

bool recursiveSearch(Node *root,int x)
{
	if(root==NULL)
		return false;
	if(root->key==x)
		return true;
	if(x<root->key)
		return recursiveSearch(root->left,x);
	else
		return recursiveSearch(root->right,x);
}

bool iterativeSearch(Node *root,int x)
{
	while(root!=NULL)
	{
		if(root->key==x)
			return true;
		else
		if(x<root->key)
			root=root->left;
		else
			root=root->right;
	}
	return false;
}

Node *insertRec(Node *root,int x)
{
	Node *temp = new Node(x);
	if(root==NULL)
		return temp;
	if(x<root->key)
		root->left=insertRec(root->left,x);
	else
		root->right=insertRec(root->right,x);
	return root;
}

Node *insertIter(Node *root,int x)
{
	Node *temp = new Node(x);
	Node *curr=root;
	Node *parent=NULL;
	while(curr!=NULL)
	{
		parent=curr;
		if(x<curr->key)
			curr=curr->left;
		else
		if(x>curr->key)
			curr=curr->right;
		else
			return root;
	}

	if(parent==NULL)
		return temp;
	else if(x<parent->key)
		parent->left=temp;
	else if(x>parent->key)
		parent->right=temp;

	return root;
}

Node *getSuccessor(Node *curr)
{
	curr=curr->right;
	while(curr!=NULL && curr->left!=NULL)
		curr=curr->left;
	return curr;
}

Node *deleteREC(Node *root,int x)
{
	if(root==NULL) return root;

	if(x<root->key)
		root->left=deleteREC(root->left,x);
	else
		if(x>root->key)
			root->right=deleteREC(root->right,x);
	else
	{
		if(root->left==NULL)
		{
			Node *temp=root->right;
			delete root;
			return temp;
		}
		else
		if(root->right==NULL)
		{
			Node *temp=root->left;
			delete root;
			return temp;
		}
		else
		{
			Node *succ=getSuccessor(root);
			root->key=succ->key;
			root->right=deleteREC(root->right,succ->key);
		}
	}

	return root;
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
	Node *root = new Node(20);
	root->left = new Node(10);
	root->right = new Node(30);
	root->left->left = new Node(5);
	root->left->right = new Node(15);
	root->right->left = new Node(25);
	root->right->right = new Node(35);
	inorder(root); cout<<endl;
	cout<<recursiveSearch(root,30)<<endl;
	cout<<iterativeSearch(root,30)<<endl;
	root = insertRec(root,40);
	root = insertIter(root,50);
	root = insertIter(root,45);
	root = insertIter(root,44);
	inorder(root); cout<<endl;
	cout<<recursiveSearch(root,44)<<endl;
	cout<<iterativeSearch(root,45)<<endl;
	root = deleteREC(root,45);
	inorder(root);
}
