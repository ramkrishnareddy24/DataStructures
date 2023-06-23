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

// Inorder Traversal
void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}

}

// Preorder Traversal
void preorder(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

// Postorder Traversal
void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<" ";
	}
}

// LevelOrder Traversal
void LevelOrder(Node *root)
{
	queue<Node *> q;

	q.push(root);

	while(!q.empty())
	{
		Node *node=q.front();
		cout<<node->key<<" ";
		q.pop();

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
		return 0;
	else
		return (1+getSize(root->left)+getSize(root->right));
}

// Size of BinaryTree
// (Iterative using LevelOrder Traversal)
int GetSize(Node *root)
{
	if(root==NULL)
		return 0;

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
		return INT_MIN;
	else
		return max(root->key,max(getMax(root->left),getMax(root->right)));
}

// Maximum of BinaryTree
// (Iterative using LevelOrder)
int GetMax(Node *root)
{
	if(root==NULL)
		return INT_MIN;

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

// Height of BinaryTree
int Height(Node *root)
{
	if(root==NULL)
		return 0;
	else
		return (1+max(Height(root->left),Height(root->right)));
}

// Iteartive Inorder Traversal
void Inorder(Node *root)
{
	stack<Node*> s;

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
void Preorder(Node *root)
{
	if(root==NULL)
		return;

	stack<Node*> s;
	s.push(root);

	while(!s.empty())
	{
		Node *curr=s.top();
		cout<<curr->key<<" ";
		s.pop();

		if(curr->right!=NULL)
			s.push(curr->right);
		if(curr->left!=NULL)
			s.push(curr->left);
	}
}


// Iterative Preorder (Optimized)
void PreorderOptimized(Node *root)
{
	if(root==NULL)
		return;

	stack<Node*> s;

	Node *curr=root;
	while(curr!=NULL || !s.empty())
	{
		while(curr!=NULL)
		{
			cout<<curr->key<<" ";

			if(curr->right!=NULL)
				s.push(curr->right);

			curr=curr->left;
		}

		if(!s.empty())
		{
			curr=s.top();
			s.pop();
		}
	}
}

// Iterative Postorder using Two Stacks
void PostOrder(Node *root)
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

// Iterative PostOrder using One Stack
vector<int> PostOrderOptimal(Node *root)
{
	stack<Node*> s;
	vector<int> v;
	Node *curr=root;
	
	while(curr!=NULL || !s.empty())
	{
		Node *temp;
		if(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		else
			temp=s.top()->right;

		if(temp==NULL)
		{
			temp=s.top();
			s.pop();
			v.push_back(temp->key);

			while(!s.empty() && temp==s.top()->right)
			{
				temp=s.top();
				s.pop();
				v.push_back(temp->key);
			}
		}
		else
			curr=temp;
	}
	return v;
}

// LevelOrder Traversal by Line BY Line
void LevelOrderLineBYLine(Node *root)
{
	if(root==NULL)
		return;

	queue<Node*> q;

	q.push(root);
	q.push(NULL);

	while(q.size()>1)
	{
		Node *curr=q.front();
		q.pop();

		if(curr==NULL)
		{
			cout<<"\n";
			q.push(NULL);
			continue;
		}

		cout<<curr->key<<" ";

		if(curr->left!=NULL)
			q.push(curr->left);
		if(curr->right!=NULL)
			q.push(curr->right);
	}
}

// LevelOrder Traversal by Line BY Line
// Method-2
void LevelOrderLineBYLineMethod2(Node *root)
{
	if(root==NULL)
		return;

	queue<Node*> q;

	q.push(root);

	while(!q.empty())
	{
		int count=q.size();
		for(int i=0;i<count;i++)
		{
			Node *curr=q.front();
			q.pop();
			cout<<curr->key<<" ";

			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}
		cout<<"\n";
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

// Print Leftview Of Binary Tree(Recursive)
int maxLevel=0;
void printLeft(Node *root,int level)
{
	if(root==NULL)
		return;

	if(maxLevel<level)
	{
		cout<<root->key<<" ";
		maxLevel=level;
	}
	printLeft(root->left,level+1);
	printLeft(root->right,level+1);
}
void PrintLeftView(Node *root)
{
	printLeft(root,1);
}

// Print Leftview Of Binary Tree(Iterative)
// using LevelOrder LineBYLine
void printLeftViewIterative(Node *root)
{
	if(root==NULL)
		return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		int count=q.size();
		for(int i=0;i<count;i++)
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

// Children Sum Property
bool isCSum(Node *root)
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

	if(root->key==sum && isCSum(root->left) && isCSum(root->right))
		return true;
	else
		return false;
}

// Check for Balanced tree
// Naive Solution
int height(Node *root)
{
	if(root==NULL)
		return 0;
	else
		return max(height(root->left),height(root->right))+1;
}
bool isBalanced(Node *root)
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

// Check for Balanced tree
// Efficient Solution
int IsBalanced(Node *root)
{
	if(root==NULL)
		return 0;

	int lh=IsBalanced(root->left);
	if(lh==-1)
		return -1;
	int rh=IsBalanced(root->right);
	if(rh==-1)
		return -1;

	if(abs(lh-rh)>1)
		return -1;

	return max(lh,rh)+1;
}

// Maximum Width Of Binary Tree
// using LevelOrder Traversal Line BY Line
int maxWidth(Node *root)
{
	if(root==NULL)
		return 0;

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

// BinaryTree to Doubly LinkedList
// Efficient Solution
Node *BinaryTreeToDoublyLinkedList(Node *root)
{
	Node *prev=NULL; //declare globally

	if(root==NULL)
		return root;
	
	Node *head=BinaryTreeToDoublyLinkedList(root->left);

	if(prev==NULL)
		head=root;
	else
	{
		root->left=prev;
		prev->right=root;
	}
	prev=root;

	BinaryTreeToDoublyLinkedList(root->right);

	return head;
}

// construct Tree using Inorder and Preorder Traveral nodes
int preIndex=0;
Node *constructTree(int in[],int pre[],int iS,int iE)
{
	if(iS>iE)
		return NULL;

	Node *root=new Node(pre[preIndex++]);

	int inIndex;
	for(int i=iS;i<=iE;i++)
	{
		if(in[i]==root->key)
		{
			inIndex=i;
			break;
		}
	}
	root->left=constructTree(in,pre,iS,inIndex-1);
	root->right=constructTree(in,pre,inIndex+1,iE);

	return root;
}

// Spiral-Form Traversal :Method-1
void printSpiral(Node *root)
{
	if(root==NULL)
		return;

	queue<Node*> q;
	stack<int> s;
	bool reverse=false;

	q.push(root);

	while(!q.empty())
	{
		int count=q.size();
		for(int i=0;i<count;i++)
		{
			Node *curr=q.front();
			q.pop();

			if(reverse)
				s.push(curr->key);
			else
				cout<<curr->key<<" ";

			if(curr->left!=NULL)
				q.push(curr->left);
			if(curr->right!=NULL)
				q.push(curr->right);
		}

		if(reverse)
		{
			while(!s.empty())
			{
				cout<<s.top()<<" ";
				s.pop();
			}
		}
		reverse=!reverse;
		cout<<"\n";
	}
}

// Spiral-Form Traversal : Method-2 //Efficient Solution
void PrintSpiral(Node *root)
{
	if(root==NULL)
		return;

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

			if(curr2->right!=NULL)
				s1.push(curr2->right);
			if(curr2->left!=NULL)
				s1.push(curr2->left);
		}
		cout<<"\n";
	}
}

// Diameter of BinaryTree
// Naive Solution
int diameter(Node *root)
{
	if(root==NULL)
		return 0;

	int d1=height(root->left)+height(root->right)+1;

	int d2=diameter(root->left);
	int d3=diameter(root->right);

	return max(d1,max(d2,d3));
}

// Efficient Solution
int res=0;
int heightDiameter(Node *root)
{
	if(root==NULL)
		return 0;

	int lh=heightDiameter(root->left);
	int rh=heightDiameter(root->right);

	res=max(res,lh+rh+1);

	return 1+max(lh,rh);
}

// Lowest Common Ancestor
// Naive Solution
bool findPath(Node *root,vector<Node*> p,int n)
{
	if(root==NULL)
		return false;
	p.push_back(root);

	if(root->key==n)
		return true;

	if(findPath(root->left,p,n) || findPath(root->right,p,n))
		return true;

	p.pop_back();
	return false;
}
Node *lca(Node *root,int n1,int n2)
{
	vector<Node*> path1,path2;

	if(findPath(root,path1,n1)==false || findPath(root,path2,n2)==false)
		return NULL;

	for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
		if(path1[i+1]!=path2[i+1])
			return path1[i];

	return NULL;
}

// Efficeint Solution
Node *LCA(Node *root,int n1,int n2)
{
	if(root==NULL)
		return NULL;

	if(root->key==n1 || root->key==n2)
		return root;

	Node *lca1=LCA(root->left,n1,n2);
	Node *lca2=LCA(root->right,n1,n2);

	if(lca1!=NULL && lca2!=NULL)
		return root;

	if(lca1!=NULL)
		return lca1;
	else
		return lca2;
}

// Time taken to Burn complete Binary Tree
// Efficient Solution
int Res=0;
int burnTime(Node *root,int leaf,int &dist)
{
	if(root==NULL)
		return 0;

	if(root->key==leaf)
	{
		dist=0;
		return 1;
	}

	int ldist=-1,rdist=-1;
	int lh=burnTime(root->left,leaf,ldist);
	int rh=burnTime(root->right,leaf,rdist);

	if(ldist!=-1)
	{
		dist=ldist+1;
		Res=max(Res,dist+rh);
	}
	else if(rdist!=-1)
	{
		dist=rdist+1;
		Res=max(Res,dist+lh);
	}

	return max(lh,rh)+1;
}

// CountNodes in complete BinaryTree
// Naive Solution
int countNodes(Node *root)
{
	if(root==NULL)
		return 0;
	else
		return 1+countNodes(root->left)+countNodes(root->right);
}

// Efficeint Solution
int CountNodes(Node *root)
{
	if(root==NULL)
		return 0;

	int lh=0,rh=0;
	Node *curr=root;
	while(curr!=NULL)
	{
		lh++;
		curr=curr->left;
	}

	curr=root;
	while(curr!=NULL)
	{
		rh++;
		curr=curr->right;
	}

	if(lh==rh)
		return pow(2,lh)-1;

	return 1+CountNodes(root->left)+CountNodes(root->right);
}

// Serialize and DeSerialize
const int EMPTY=-1;
void serialize(Node *root,vector<int> &arr)
{
	if(root==NULL)
	{
		arr.push_back(EMPTY);
		return;
	}

	arr.push_back(root->key);
	serialize(root->left,arr);
	serialize(root->right,arr);
}

int index=0;
Node *deSerialize(vector<int> &arr)
{
	if(index==arr.size())
		return NULL;

	int val=arr[index];
	index++;

	if(val==EMPTY)
		return NULL;

	Node *root=new Node(val);
	root->left=deSerialize(arr);
	root->right=deSerialize(arr);

	return root;
}

// Time taken to burn Binary tree
/*
int findMaxDistance(map<Node<int>*,Node<int>*> &mpp,Node<int>* target)
{
	queue<Node<int>*,int> q;
	q.push(target);
	map<Node<int>*,int> vis;
	vis[target] = 1;
	int maxi = 0;

	while(!q.empty())
	{
		int sz = q.size();
		int fl = 0;
		for(int i=0;i<sz;i++)
		{
			auto node = q.front();
			q.pop();
			if(node->left && !vis[node->left])
			{
				fl=1;
				vis[node->left]=1;
				q.push(node ->left);
			}
			if(node->right && !vis[node->right])
			{
				fl=1;
				vis[node->right]=1;
				q.push(node->right);
			}

			if(mpp[node] && !vis[mpp[node]])
			{
				fl=1;
				vis[mpp[node]]=1;
				q.push(mpp[node]);
			}
		}
		if(fl) maxi++;
	}
	return maxi;
}
*/

// Check if Two Trees are Identical
bool isIdentical(Node *r1,Node *r2)
{
	if(r1==NULL && r2==NULL)
		return true;

	if(r1!=NULL && r2!=NULL)
	{
		return
		(
			r1->key==r2->key && isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right)
		);
	}
	return false;
}

// Leetcode 102
// vector<vector<int>> levelOrder(TreeNode* root)
// {
//         vector<vector<int>> ans;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         if(!root) return {};
        
//         while(!q.empty())
//         {
//             int n=q.size();
//             vector<int> v;
//             for(int i=0;i<n;i++)
//             {
//                 TreeNode *node=q.front();
//                 q.pop();
//                 v.push_back(node->val);
                
                
//                 if(node->left)
//                     q.push(node->left);
//                 if(node->right)
//                     q.push(node->right);
//             }
//             ans.push_back(v);
                 
//         }
//         return ans;
// }

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	root->right->right=new Node(70);
	
	cout<<"inorder: "; inorder(root);
	cout<<endl;
	cout<<"preorder: "; preorder(root);
	cout<<endl;
	cout<<"postorder: "; postorder(root);
	cout<<endl;
	cout<<"Levelorder: "; LevelOrder(root);
	cout<<endl;
	cout<<"Size(Recursive): "<<getSize(root)<<endl;
	cout<<"Size(Iterative): "<<GetSize(root)<<endl;
	cout<<"Max Val(REC): "<<getMax(root)<<endl;
	cout<<"MAX Val(ITE): "<<GetMax(root)<<endl;
	cout<<"Height: "<<Height(root)<<endl;
	cout<<"Iterative Inorder: "; Inorder(root);
	cout<<endl;
	cout<<"Iterative Preorder: "; Preorder(root);
	cout<<endl;
	cout<<"Iterative PreorderOptimized: "; PreorderOptimized(root);
	cout<<endl;
	cout<<"Iteartive Postorder: "; PostOrder(root); cout<<endl;
	// cout<<"Optimal Postorder: "; PostOrderOptimal(root); cout<<endl;
	cout<<"LevelOrderLineBYLine: "<<endl; LevelOrderLineBYLine(root);
	cout<<endl;
	cout<<"LevelOrderLineBYLineMethod2: "<<endl;
	LevelOrderLineBYLineMethod2(root);
	cout<<endl;
	cout<<"printNodesAtK: ";
	printNodesAtK(root,2);
	cout<<endl<<"Left View(Recursive): "; PrintLeftView(root);
	cout<<endl<<"Left View(Iterative): "; printLeftViewIterative(root);
	cout<<endl<<"is ChildrenSum property: "<<isCSum(root)<<endl;
	cout<<"isBalanced Tree (Naive): "<<isBalanced(root)<<endl;
	cout<<"IsBalanced Tree (Efficient): "<<IsBalanced(root)<<endl;
	cout<<"Maximum Width of BinaryTree: "<<maxWidth(root)<<endl;
	root = BinaryTreeToDoublyLinkedList(root);

	int in[]={20,10,40,30,50};
	int pre[]={10,20,30,40,50};
	int n=sizeof(in)/sizeof(in[0]);
	root = constructTree(in,pre,0,n-1);
	cout<<"Inorder Traversal of New Tree: ";inorder(root);
	cout<<endl;

	cout<<"printSpiral: "<<endl; printSpiral(root);
	cout<<endl<<"PrintSpiral: "<<endl; PrintSpiral(root);

	cout<<"diameter: "<<diameter(root)<<endl;
	cout<<"Diameter: "<<heightDiameter(root)<<endl;

	cout<<"LCA: "; root = LCA(root,20,50);cout<<endl;
	// cout<<"burnTime: "<<burnTime(root,50,0);
	cout<<"countNodes(Naive): "<<countNodes(root)<<endl;
	cout<<"CountNodes(Efficient): "<<CountNodes(root)<<endl;
	vector<int> v={1,2,3,4,5};
	cout<<"serialize: "; serialize(root,v);

	return 0;
}