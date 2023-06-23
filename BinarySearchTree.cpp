#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	Node *left,*right;
	Node(int x)
	{
		key=x;
		left=right=NULL;
	}
};

void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

int recursiveSearch(Node *root,int x)
{
	if(root==NULL)
		return false;
	if(root->key==x)
		return true;
	else if(x<root->key)
		return recursiveSearch(root->left,x);
	else
		return recursiveSearch(root->right,x);
}

int iterativeSearch(Node *root,int x)
{
	while(root!=NULL)
	{
		if(root->key==x)
			return true;

		if(x<root->key)
			root=root->left;
		else
			root=root->right;
	}
	return false;
}

// Check BST
int checkBSTwrapper(Node *root,int min,int max)
{
	if(root==NULL)
		return true;
		return (root->key>min && root->key<max && checkBSTwrapper(root->left,min,root->key) && checkBSTwrapper(root->right,root->key,max));
}
bool checkBST(Node *root)
{
	checkBSTwrapper(root,INT_MIN,INT_MAX);
}

int main()
{
	Node *root = new Node(10);
	root->left = new Node(5);
	root->right= new Node(15);
	root->left->left = new Node(3);
	root->left->right = new Node(7);
	root->right->left = new Node(12);
	root->right->right = new Node(17);
	inorder(root);
	cout<<endl<<"recursiveSearch :"<<recursiveSearch(root,3)<<endl;
	cout<<"iterativeSearch :"<<iterativeSearch(root,55)<<endl;
	cout<<"checkBST :"<<checkBST(root)<<endl;
	return 0;
}