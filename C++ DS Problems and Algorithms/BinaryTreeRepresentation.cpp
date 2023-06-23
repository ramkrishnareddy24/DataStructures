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

int main()
{
	Node *root = new Node(20);
	root->left = new Node(10);
	root->right = new Node(30);
	root->left->left = new Node(5);
	root->left->right = new Node(15);
	root->right->left = new Node(25);
	root->right->right = new Node(40);
	cout<<"inorder"<<endl;
	inorder(root); cout<<endl;
	cout<<"preorder"<<endl;
	preorder(root); cout<<endl;
	cout<<"postorder"<<endl;
	postorder(root);
}