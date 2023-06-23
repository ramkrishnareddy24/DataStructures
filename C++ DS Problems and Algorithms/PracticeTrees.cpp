#include<iostream>
#include<bits/stdc++.h>
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

void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<" ";
	}
}

int height(Node *root)
{
	if(root==NULL)
		return 0;
	else
		return max(height(root->left),height(root->right))+1;
}

int getSize(Node *root)
{
	if(root==NULL)
		return 0;
	return getSize(root->left)+getSize(root->right)+1;
}

int getMAX(Node *root)
{
	if(root==NULL)
		return INT_MIN;
	else
		return max(root->key,max(getMAX(root->left),getMAX(root->right)));
}

void iterativeInorder(Node *root)
{
	stack<Node *> s;
	Node *curr=root;
	while(curr!=NULL || s.empty()==false)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		curr=s.top();
		s.pop();
		cout<<curr->key<<" ";
		curr=curr->right;
	}
}

void iterativePreorder(Node *root)
{
	if(root==NULL) return;
	stack<Node *> s;
	s.push(root);
	while(s.empty()==false)
	{
		Node *curr=s.top();
		cout<<curr->key<<" ";
		s.pop();

		if(curr->right!=NULL) s.push(curr->right);
		if(curr->left!=NULL) s.push(curr->left);
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
	root->right->right = new Node(40);
	inorder(root); cout<<endl;
	preorder(root); cout<<endl;
	postorder(root); cout<<endl;
	cout<<height(root)<<endl;
	cout<<getSize(root)<<endl;
	cout<<getMAX(root)<<endl;
	cout<<endl;
	iterativeInorder(root); cout<<endl;
	iterativePreorder(root);
}