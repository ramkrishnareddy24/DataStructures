#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Optimized
int cnt(TreeNode *root)
{
        if(!root)
            return 0;
        else
           return (1+cnt(root->left)+cnt(root->right));
}

int sum(TreeNode *root)
{
        if(!root)
            return 0;
        else
            return (root->val+sum(root->left)+sum(root->right));
}

int averageOfSubtree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = averageOfSubtree(root->left)+averageOfSubtree(root->right);
        return sum(root)/cnt(root)==root->val?ans+1:ans;
}

int main()
{
    TreeNode  *root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    cout<<averageOfSubtree(root);//5
}