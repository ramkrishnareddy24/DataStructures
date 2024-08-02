#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node* left;
	Node* right;
	Node(int x){
		key = x;
		left = right = nullptr;

	}
};

//inorder
void inorder(Node* root){
	if(root!=nullptr) {
		inorder(root->left);
		cout<<root->key;
		inorder(root->right);
	}
}

//preorder
void preorder(Node* root){
	if(root!=nullptr){
		cout<<root->key;
		preorder(root->left);
		preorder(root->right);
	}
}

//postorder
void postorder(Node* root){
	if(root!=nullptr){
		postorder(root->left);
		postorder(root->right);
		cout<<root->key;
	}
}

//LevelOrder Traversal
vector<int> levelOrder(Node* root){
	queue<Node*> q;
	q.push(root);

	vector<int> ans;

	while(!q.empty()){
		Node* node = q.front();
		q.pop();

		ans.push_back(node->key);

		if(node->left!=nullptr) q.push(node->left);
		if(node->right!=nullptr) q.push(node->right);
	}
	return ans;
}

//Size of Binary Tree (Recursive)
int getSize(Node* root){
	if(root==nullptr) return nullptr;
	else
	return 1+getSize(root->left)+getSize(root->right);
}

//Size of Binary Tree (Iterative -> using levelOrder)
int getSize(Node* root){
	queue<Node*> q;
	q.push(root);

	int size = 0;

	while(!q.empty()){
		Node* node = q.front();
		size++;
		q.pop();

		if(!node->left) q.push(node->left);
		if(!node->right) q.push(node->right);
	}
	return size;
}

//Maximum of Binary Tree (Recursive)
int getMax(Node* root){
	if(root==nullptr) return -1;
	return max(root->key,max(getMax(root->left),getMax(root->right)));
}

//Maximum of Binary Tree (Iterative)
int GetMax(Node* root){
	if(root==nullptr) return -1;

	queue<Node*> q;
	q.push(root);

	int res = INT_MIN;
	while(!q.empty()){
		Node* node = q.front();
		q.pop();

		res = max(res,node->key);

		if(!node->left) q.push(node->left);
		if(!node->right) q.push(node->right);
	}
	return res;
}

//Height of Binary Tree
int height(Node* root){
	if(root==nullptr) return -1;
	return 1+max(height(root->left),height(root->right));
}

//Level Order Line by Line
vector<int> levelOrderLineByLine(Node* root){
	vector<int> ans;
	if(root==nullptr) return nullptr;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node* node = q.front();
			q.pop();
			ans.push_back(node->key);

			if(!node->left) q.push(node->left);
			if(!node->right) q.push(node->right);
		}
		cout<<endl;
	}
	return ans;
}

//Left View of Binary Tree
vector<int> leftView(Node* root){
	vector<int> ans;

	if(root==nullptr) return nullptr;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node* node = q.front();
			q.pop();

			if(i==0) ans.push_back(node->key);

			if(!node->left) q.push(node->left);
			if(!node->right) q.push(node->right);
		}
	}
	return ans;
}

//Right View of Binary Tree
vector<int> rightView(Node* root){
	vector<int> ans;

	if(root==nullptr) return nullptr;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int n = q.size();
		for(int i=0;i<n;i++){
			Node* node = q.front();
			q.pop();

			if(i==n-1) ans.push_back(node->key);

			if(!node->left) q.push(node->left);
			if(!node->right) q.push(node->right);
		}
	}
	return ans;
}

//Iterative Inorder
vector<int> inorderIterative(Node* root){
	if(root==nullptr) return nullptr;

	stack<Node*> s;

	Node* curr = root;

	vector<int> inorder;

	while(curr!=nullptr || !s.empty()){

		while(curr!=nullptr){
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		s.pop();
		inorder.push_back(curr->key);
		curr = curr->right;
		
	}
	return inorder;
}

//Iterative Preorder // Resembles LevelOrder
vector<int> preorderIterative(Node* root){
	if(root==nullptr) return nullptr;

	stack<Node*> s;
	s.push(root);

	vector<int> preorder;
	while(!s.empty()){
		Node* curr = s.top();
		s.pop();
		preorder.push_back(curr->key);

		if(curr->right!=nullptr) s.push(curr->right);
		if(curr->left!=nullptr) s.push(curr->left);
	}
	return preorder;
}

//Iterative Postorder
vector<int> postorderIterative(Node* root){
	if(root==nullptr) return nullptr;

	stack<Node*> s1;
	stack<Node*> s2;

	s1.push(root);

	Node* curr = root;

	vector<int> postorder;

	while(!s1.empty()){
		curr = s1.top();
		s1.pop();

		s2.push(curr);

		if(curr->left!=nullptr) s1.push(curr->left);
		if(curr->right!=nullptr) s1.push(curr->right);
	}

	while(!s2.empty()){
		curr = s2.top();
		s2.pop();
		postorder.push_back(curr->key);
	}
	return postorder;
}

int main(){

}


































