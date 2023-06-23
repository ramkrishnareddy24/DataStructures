#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

bool search(Node *root,int x)
{
    if(root==NULL)
    return false;
    if(root->key==x)
    return true;
    else if(x<root->key)
    return search(root->left,x);
    else if(x>root->key)
    return search(root->right,x);
}

int main()
{
    Node *root=new Node(15);
    root->left=new Node(5);
    root->right=new Node(20);
    root->left->left=new Node(3);
    root->right->left=new Node(18);
    root->right->right=new Node(80);
    root->right->left->left=new Node(16);
    cout<<"Searching 16: "<<search(root,16)<<endl;
    return 0;
}