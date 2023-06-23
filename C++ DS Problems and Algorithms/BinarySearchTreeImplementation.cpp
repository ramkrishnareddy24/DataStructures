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
	else if(x==root->key)
		return true;
	else if(x<root->key)
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
		else if(x<root->key)
			root=root->left;
		else
			root=root->right;
	}
	return false;
}

Node *insert(Node *root,int x)
{
	Node *temp = new Node(x);
	if(root==NULL)
		return temp;
	else if(x<root->key)
		root->left = insert(root->left,x);
	else if(x>root->key)
		root->right = insert(root->right,x);
	return root;
}

Node *iterativeInsert(Node *root,int x)
{
	Node *temp = new Node(x);
	Node *parent=NULL,*curr=root;

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

Node *getSuccessor(Node *curr)
{
	curr=curr->right;
	while(curr!=NULL && curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}

Node *delNodeREC(Node *root,int x)
{
	if(root==NULL) return root;

	if(x<root->key)
		root->left=delNodeREC(root->left,x);
	else if(x>root->key)
		root->right=delNodeREC(root->right,x);
	else
	{
		if(root->left==NULL)
		{
			Node *temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL)
		{
			Node *temp=root->right;
			delete root;
			return temp;
		}
		else
		{
			Node *succ=getSuccessor(root);
			root->key=succ->key;
			root->right=delNodeREC(root->right,succ->key);
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
	Node *root = new Node(15);
	root->left = new Node(5);
	root->right = new Node(20);
	root->left->left = new Node(3);
	root->right->left = new Node(18);
	root->right->right = new Node(80);
	root->right->left->left = new Node(16);
	cout<<recursiveSearch(root,16)<<endl;
	cout<<iterativeSearch(root,18)<<endl;
	root = insert(root,19);
	root = iterativeInsert(root,40);
	inorder(root);cout<<endl;
	root = delNodeREC(root,19);
	inorder(root);
}