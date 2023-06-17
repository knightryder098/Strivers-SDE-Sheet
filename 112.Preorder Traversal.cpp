//https://www.codingninjas.com/codestudio/problems/preorder-traversal_8230856?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void helper(TreeNode* root,vector<int>&ans){
    if(!root)return;
    ans.push_back(root->data);
    helper(root->left,ans);
    helper(root->right,ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
    helper(root,ans);
    return ans;
}
