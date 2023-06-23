#include<iostream>
#include<math.h>
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

void inorder(Node *root) //left Root right
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

void preorder(Node *root) //Root left right
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root) //left right Root
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<" "; 
	}
}

int getSize(Node *root)
{
	if (root==NULL)
		return 0;
	return (1+getSize(root->left)+getSize(root->right));
}

int getMax(Node *root)
{
	if(root==NULL)
		return INT_MIN;
	else
		return max(root->key,max(getMax(root->left),getMax(root->right)));
}

int height(Node *root)
{
	if(root==NULL)
		return 0;
	else
		return max(height(root->left),height(root->right))+1;
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

// efficient solution
void IterativePreorder(Node *root)
{
	if(root==NULL) return;
	stack<Node *> s;
	Node *curr=root;
	while(curr!=NULL || s.empty()==false)
	{
		while(curr!=NULL)
		{
			cout<<curr->key<<" ";
			if(curr->right!=NULL)
				s.push(curr->right);
			curr=curr->left;
		}
		if(s.empty()==false) { curr=s.top(); s.pop(); }
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
	root->right->right->right = new Node(50);
	cout<<"inorder"<<endl;
	inorder(root); cout<<endl;
	cout<<"preorder"<<endl;
	preorder(root); cout<<endl;
	cout<<"postorder"<<endl;
	postorder(root); cout<<endl;
	cout<<getSize(root); cout<<endl;
	cout<<getMax(root); cout<<endl;
	cout<<height(root); cout<<endl;
	cout<<"IterativeInorder: ";iterativeInorder(root); cout<<endl;
	iterativePreorder(root); cout<<endl;
	IterativePreorder(root);
}