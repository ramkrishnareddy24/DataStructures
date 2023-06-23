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

// Inorder
void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right); 
	}
	
}

// Preorder
void preorder(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
	
}

// PostOrder
void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<" ";
	}
	
}

// LevelOrder
void levelOrder(Node *root)
{
	queue<Node *> q;
	q.push(root);

	while(!q.empty())
	{
		Node *node = q.front();
		q.pop();
		cout<<node->key<<" ";

		if(node->left!=NULL)
			q.push(node->left);
		if(node->right!=NULL)
			q.push(node->right);
	}
}

// Size of BinaryTree(Recusive)
int getSize(Node *root)
{
	if(root==NULL)
		return -1;
	else
		return (1+getSize(root->left)+getSize(root->right));
}

// Size of BinaryTree
// (Iterative using LevelOrder Traversal)
int getSizE(Node *root)
{
	if(root==NULL)
		return -1;

	queue<Node *> q;
	q.push(root);

	int count=0;
	while(!q.empty())
	{
		Node *node=q.front();
		count++;
		q.pop();
		

		if(node->left!=NULL)
			q.push(node->left);
		if(node->right!=NULL)
			q.push(node->right);
	}
	return count;
}

// Maximum of BinaryTree
int getMax(Node *root)
{
	if(root==NULL)
		return -1;
	else
		return max(root->key,max(getMax(root->left),getMax(root->right)));
}

// Maximum of BinaryTree
// (Iterative using LevelOrder)
int GetMax(Node *root)
{
	if(root==NULL)
		return -1;

	queue<Node *> q;
	q.push(root);

	int res=INT_MIN;
	while(!q.empty())
	{
		Node *node=q.front();
		res=max(res,node->key);
		q.pop();

		if(node->left!=NULL)
			q.push(node->left);
		if(node->right!=NULL)
			q.push(node->right);
	}
	return res;
}

// Height of Binary Tree
int height(Node *root)
{
	if(root==NULL)
		return -1;
	else
		return 1+(max(height(root->left),height(root->right)));
}

// Iterative Inorder
void inorderIterative(Node *root)
{
	stack<Node *> s;

	Node *curr=root;
	while(curr!=NULL || !s.empty())
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

// Iterative Preorder
void preorderIterative(Node *root)
{
	if(root==NULL)
		return;

	stack<Node *> s;
	s.push(root);

	while(!s.empty())
	{
		Node *curr=s.top();
		s.pop();
		cout<<curr->key<<" ";

		if(curr->right!=NULL)
			s.push(curr->right);
		if(curr->left!=NULL)
			s.push(curr->left);
	}
}


// Iterative Postorder using Two Stacks
void postorderIterative(Node *root)
{
	if(root==NULL)
		return;

	stack<Node*> s1;
	stack<Node*> s2;

	s1.push(root);

	Node *curr=root;
	
	while(!s1.empty())
	{
		curr=s1.top();
		s1.pop();

		s2.push(curr);

		if(curr->left!=NULL)
			s1.push(curr->left);
		if(curr->right!=NULL)
			s1.push(curr->right);
	}

	while(!s2.empty())
	{
		curr=s2.top();
		cout<<curr->key<<" ";
		s2.pop();
	}
}


// LevelOrder Line By Line
void levelOrderLineByLine(Node *root)
{
	if(root==NULL)
		return;

	queue<Node *> q;

	q.push(root);

	while(!q.empty())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			Node *curr=q.front();
			q.pop();
			cout<<curr->key<<" ";

			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}
		cout<<endl;
	}
}



// Print All Nodes at Distance key
void printNodesAtK(Node *root,int K)
{
	if(root==NULL)
		return;

	if(K==0)
		cout<<root->key<<" ";
	else
	{
		printNodesAtK(root->left,K-1);
		printNodesAtK(root->right,K-1);
	}
}

// Left View
void leftView(Node *root)
{
	if(root==NULL) return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			Node *curr=q.front();
			q.pop();

			if(i==0)
				cout<<curr->key<<" ";

			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}
	}
}

// Right View
void rightView(Node *root)
{
	if(root==NULL) return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int n=q.size();
		for(int i=0;i<n;i++)
		{
			Node *curr=q.front();
			q.pop();
			
			if(i==n-1)
				cout<<curr->key<<" ";

			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}
	}
}

// Children Sum Property
int isSum(Node *root)
{
	if(root==NULL)
		return true;

	if(root->left==NULL && root->right==NULL)
		return true;

	int sum=0;
	if(root->left!=NULL)
		sum+=root->left->key;
	if(root->right!=NULL)
		sum+=root->right->key;

	if(sum==root->key && isSum(root->left) && isSum(root->right))
		return true;
	else
		return false;
}


// check whether tree is Balanced
int isBalanced(Node *root)
{
	if(root==NULL)
		return true;

	int lh=height(root->left);
	int rh=height(root->right);

	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
		return true;
	else
		return false;
}

// Width of Binary Tree
int width(Node *root)
{
	if(root==NULL)
		return -1;

	queue<Node*> q;
	q.push(root);

	int res=0;
	while(!q.empty())
	{
		int count=q.size();
		res=max(res,count);

		Node *curr=q.front();
		q.pop();

		if(curr->left!=NULL)
			q.push(curr->left);
		if(curr->right!=NULL)
			q.push(curr->right);
	}
	return res;
}

// Spiral form
void spiral(Node *root)
{
	if(root==NULL) return;

	stack<Node*> s1;
	stack<Node*> s2;

	s1.push(root);

	while(!s1.empty() || !s2.empty())
	{
		while(!s1.empty())
		{
			Node *curr1=s1.top();
			s1.pop();
			cout<<curr1->key<<" ";

			if(curr1->left!=NULL)
				s2.push(curr1->left);
			if(curr1->right!=NULL)
				s2.push(curr1->right);
		}
		cout<<"\n";
		while(!s2.empty())
		{
			Node *curr2=s2.top();
			s2.pop();
			cout<<curr2->key<<" ";

			if(curr2->left!=NULL)
				s1.push(curr2->left);
			if(curr2->right!=NULL)
				s1.push(curr2->right);
		}
		cout<<"\n";
	}
}

// Diameter
int diameter(Node *root)
{
	if(root==NULL)
		return -1;

	int d1=1+height(root->left)+height(root->right);

	int d2=diameter(root->left);
	int d3=diameter(root->right);

	return max(d1,max(d2,d3));
}

// Count Nodes
int count(Node *root)
{
	if(root==NULL)
		return 0;
	else
		return 1+count(root->left)+count(root->right);
}

int main()
{
	Node *root = new Node(5);
	root->left=new Node(10);
	root->right=new Node(20);
	root->left->left=new Node(30);
	root->left->right=new Node(40);
	root->right->left=new Node(50);
	root->right->right=new Node(60);
	root->right->right->right=new Node(80);

	cout<<"Inorder :";inorder(root);cout<<endl;
	// cout<<"Preorder :";preorder(root);cout<<endl;
	// cout<<"Postorder :";postorder(root);cout<<endl;
	// cout<<"Levelorder :";levelOrder(root);cout<<endl;
	// cout<<"getSize :"<<getSize(root)<<endl;
	// cout<<"getSizE :"<<getSizE(root)<<endl;
	// cout<<"getMax :"<<getMax(root)<<endl;
	// cout<<"GetMax :"<<GetMax(root)<<endl;
	// cout<<"height :"<<height(root)<<endl;
	// cout<<"inorderIterative :";inorderIterative(root);cout<<endl;
	// cout<<"preorderIterative :";preorderIterative(root);cout<<endl;
	// cout<<"postorderIterative :";postorderIterative(root);cout<<endl;
	// cout<<"levelOrderLineByLine :"<<endl;levelOrderLineByLine(root);cout<<endl;
	cout<<"leftView :";leftView(root);cout<<endl;
	// cout<<"rightView :";rightView(root);cout<<endl;
	// cout<<"isSum :"<<isSum(root)<<endl;
	// cout<<"spiral :"<<endl;spiral(root);cout<<endl;
	// cout<<"width :"<<width(root)<<endl;
	// cout<<"diameter :"<<diameter(root)<<endl;
	// cout<<"count :"<<count(root)<<endl;

	return 0;
}