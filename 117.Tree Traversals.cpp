//https://www.codingninjas.com/codestudio/problems/tree-traversals_8230775?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void inorder(BinaryTreeNode<int>* root, vector<int>&ans){
    if(!root)return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
void preorder(BinaryTreeNode<int>* root, vector<int>&ans){
    if(!root)return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
void postorder(BinaryTreeNode<int>* root, vector<int>&ans){
    if(!root)return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>ans1,ans2,ans3;
    inorder(root,ans1);
    preorder(root,ans2);
    postorder(root,ans3);
    ans.push_back(ans1);
    ans.push_back(ans2);
    ans.push_back(ans3);
    return ans;

}
