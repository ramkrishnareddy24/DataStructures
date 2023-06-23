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
		// cout<<root->key<<" ";
		inorder(root->right);
	}

}

// Recursive Solution
bool Search(Node *root,int x)
{
	if(root==NULL)
		return false;
	if(root->key==x)
		return true;
	else if(x<root->key)
		return Search(root->left,x);
	else if(x>root->key)
		return Search(root->right,x);
}

// Iterative Solution
bool search(Node *root,int x)
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

// Recursive Solution
Node *insert(Node *root,int x)
{
	Node *temp = new Node(x);
	if(root==NULL)
		return temp;
	if(x<root->key)
		root->left=insert(root->left,x);
	else if(x>root->key)
		root->right=insert(root->right,x);

	return root;
}

// Iterative
Node *Insert(Node *root,int x)
{
	Node *temp = new Node(x);
	Node *parent=NULL,*curr=root;

	while(curr!=NULL)
	{
		parent = curr;

		if(x<curr->key)
			curr=curr->left;
		else if(x>curr->key)
			curr=curr->right;
		else
			return root;
	}

	if(parent==NULL)
		return temp;
	if(x<parent->key)
		parent->left=temp;
	else
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

// Deletion in BST
Node *delNode(Node *root,int x)
{
	if(root==NULL)
		return root;

	if(x<root->key)
		root->left=delNode(root->left,x);
	else if(x>root->key)
		root->right=delNode(root->right,x);
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
			Node *temp=root->left;
			delete root;
			return temp;
		}
		else
		{
			Node *succ=getSuccessor(root);
			succ->key=root->key;
			root->right=delNode(root->right,succ->key);
		}
		return root;
	}
}

// Floor in BST
Node *floorInBST(Node *root,int x)
{
	Node *res=NULL; //or res=INT_MAX
	while(root!=NULL)
	{
		if(root->key==x)
			return root;

		if(x<root->key)
			root=root->left;
		else
		{
			res=root;
			root=root->right;
		}
	}
	return res;
}

// Ciel in BST
Node *ceilInBST(Node *root,int x)
{
	Node *res=NULL; //or res=-1;
	while(root!=NULL)
	{
		if(root->key==x)
			return root;

		if(x<root->key)
		{
			res=root;
			root=root->left;
		}
		else
			root=root->right;
	}
	return res;
}


// Ceiling On leftSide
// Naive Solution
void ceilOnLeft(int arr[],int n)
{
	int diff=INT_MAX;
	cout<<-1<<" ";
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]>=arr[i])
				diff=min(diff,arr[j]-arr[i]);
		}
		if(diff==INT_MAX)
			cout<<-1<<" ";
		else
			cout<<diff+arr[i]<<" ";
	}
}

// Efficient Solution
void CeilOnLeft(int arr[],int n)
{
	set<int> s;
	cout<<-1<<" ";
	s.insert(arr[0]);

	for(int i=1;i<n;i++)
	{
		auto it=s.lower_bound(arr[i]);
		if(it==s.end())
			cout<<-1<<" ";
		else
			cout<<(*it)<<" ";

		s.insert(arr[i]);
	}
}

// Kth Smallest
// Naive Solution
int kthSmallest(Node *root,int k)
{
	int count=0;
	if(root!=NULL)
	{
		kthSmallest(root->left,k);
		count++;
		if(count==k)
		{
			return root->key;
		}
		kthSmallest(root->right,k);
	}
}

// KthSmallest
// Efficient Solution
Node* KthSmallest(Node *root,int &k)
{
	if(root==NULL)
		return NULL;

	Node *left = KthSmallest(root->left,k);

	if(left!=NULL)
		return left;

	k--;

	if(k==0)
		return root;

	return KthSmallest(root->right,k);
}
void printKth(Node *root,int k)
{
	Node *res=KthSmallest(root,k);
	if(res==NULL)
		cout<<"There are less than k nodes in BST";
	else
		cout<<res->key<<" ";
}

// check for BST
// Efficient Solution:1
bool isBST(Node *root,int min,int max)
{
	if(root==NULL)
		return true;
	return (root->key>min && root->key<max && isBST(root->left,min,root->key) && isBST(root->right,root->key,max));
}
bool isBSTfun(Node *root) //Wrapper Funtion
{
	isBST(root,INT_MIN,INT_MAX);
}



// // Check for BST
// // Efficeint Solution:2
// int prev=INT_MIN;
// bool isBsT(Node *root)
// {
// 	if(root==NULL)
// 		return true;
// 	if(isBsT(root->left)==false)
// 		return false;

// 	if(root->key<=prev)
// 		return false;

// 	return isBsT(root->right);
// }

// // Fix a BST with two Nodes swapped
// Node *prev=NULL,*first=NULL,*second=NULL;
// void fixBST(Node *root)
// {
// 	if(root==NULL)
// 		return;
// 	fixBST(root->left);

// 	if(prev!=NULL && root->key<prev->key)
// 	{
// 		if(first==NULL)
// 			first=prev;
// 		second=root;
// 	}

// 	prev=root;
// 	fixBST(root->right);
// }

// Pair with Given Sum in BST
bool isPairSum(Node *root,int sum,unordered_set<int> &s)
{
	if(root==NULL)
		return false;

	if(isPairSum(root->left,sum,s)==true)
		return true;
	
	if(s.find(sum-root->key)!=s.end())
		return true;
	else
		s.insert(root->key);

	return isPairSum(root->right,sum,s);
}

// Vertical Sum in Binary Tree
// Efficient Solution
void vSumR(Node *root,int hd,map<int,int> &mp)
{
	if(root==NULL) return;
	vSumR(root->left,hd-1,mp);
	mp[hd]+=root->key;
	vSumR(root->right,hd+1,mp);
}
void vSum(Node *root)
{
	map<int,int> mp;
	vSumR(root,0,mp);
	for(auto x:mp)
		cout<<(x.second)<<" ";
}

// Vertical Traversal of Binary tree
void vTraversal(Node *root)
{
	map<int,vector<int>> mp;
	queue<pair<Node *,int>> q;
	q.push({root,0});

	while(!q.empty())
	{
		auto p=q.front();
		Node *curr=p.first;
		int hd=p.second;
		mp[hd].push_back(curr->key);
		q.pop();

		if(curr->left!=NULL)
			q.push({curr->left,hd-1});
		if(curr->right!=NULL)
			q.push({curr->right,hd+1});
	}

	for(auto p:mp)
	{
		vector<int> v=p.second;
		for(int x:v)
			cout<<x<<" ";
		cout<<endl;
	}
}

// Top View of Binary Tree
void TopView(Node *root)
{
	map<int,int> mp;
	queue<pair<Node*,int>> q;
	q.push({root,0});

	while(!q.empty())
	{
		auto p=q.front();
		Node *curr=p.first;
		int hd=p.second;
		if(mp.find(hd)==mp.end())
			mp[hd]=curr->key;
		q.pop();

		if(curr->left!=NULL)
			q.push({curr->left,hd-1});
		if(curr->right!=NULL)
			q.push({curr->right,hd+1});
	}

	for(auto p:mp)
	{
		cout<<p.second<<" ";
	}
}

// BottomView of Binary Tree
void BottomView(Node *root)
{
 	map<int,int> mp;
 	queue<pair<Node*,int>> q;
 	q.push({root,0});

 	while(!q.empty())
 	{
 		auto p=q.front();
 		Node *curr=p.first;
 		int hd=p.second;
 		mp[hd]=curr->key;
 		q.pop();

 		if(curr->left!=NULL)
 			q.push({curr->left,hd-1});
 		if(curr->right!=NULL)
 			q.push({curr->right,hd+1});
 	}

 	for(auto p:mp)
 		cout<<p.second<<" ";
}

int main()
{
	// Node *root=new Node(10);
	// root->left=new Node(5);
	// root->right=new Node(15);
	// root->left->left=new Node(3);
	// root->right->left=new Node(12);
	// root->right->right=new Node(30);
	// root->right->left->left=new Node(16);
	// cout<<"Searching 16(Rec): "<<Search(root,16)<<endl;
	// cout<<"Searching 16(Ite): "<<search(root,16)<<endl;
	// root = insert(root,2);
	// root = Insert(root,4);
	// inorder(root);
	// cout<<endl;
	// root = delNode(root,2);
	// inorder(root);
	// cout<<endl;
	// root = floorInBST(root,21);
	// root = ceilInBST(root,14);
	// int arr[]={2,8,30,15,25,12};
	// int n=sizeof(arr)/sizeof(arr[0]);
	// ceilOnLeft(arr,n);
	// cout<<endl;
	// CeilOnLeft(arr,n);
	// cout<<endl;
	// cout<<kthSmallest(root,3);
	// cout<<endl;
	// printKth(root,3);
	// cout<<endl;
	// cout<<"Check BST 1: "<<isBSTfun(root)<<endl;
	// cout<<"Check BsT 2: "<<isBsT(root)<<endl;
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	
	// vSum(root);
	// cout<<isPairSum(root,21,0);

	// cout<<isBSTfun(root);
	vTraversal(root);
	cout<<endl<<endl;
	TopView(root);
	cout<<endl<<endl;
	BottomView(root);
	return 0;
}