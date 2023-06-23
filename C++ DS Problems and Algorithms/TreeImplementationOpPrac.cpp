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

vector<int> Inorder(Node *root)
{
	stack<Node *> s;
	vector<int> list;
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
		list.push_back(curr->key);
		curr=curr->right;
	}
	return list;
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
	//inorder(root);cout<<endl;
	Inorder(root);
}