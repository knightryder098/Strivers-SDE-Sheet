//https://www.codingninjas.com/studio/problems/boundary-traversal-of-binary-tree_8230712?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>*root){
    return (!root->left and !root->right);
}

void addleft(TreeNode<int>*root,vector<int>&ans){
    TreeNode<int>*curr=root->left;
    while(curr){
        if(!isLeaf(curr))ans.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else
        curr=curr->right;
    }
}

void addleaf(TreeNode<int>*root,vector<int>&ans){
    if(isLeaf(root))ans.push_back(root->data);
    if(root->left)addleaf(root->left,ans);
    if(root->right)addleaf(root->right,ans);
}

void addright(TreeNode<int>*root,vector<int>&ans){
    TreeNode<int>*curr=root->right;
    vector<int>tmp;
    while(curr){
        if(!isLeaf(curr))tmp.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else
        curr=curr->left;
    }

    for(int i=tmp.size()-1;i>=0;i--){
        ans.push_back(tmp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>ans;
    if(!root)return {};
    if(!isLeaf(root))ans.push_back(root->data);
    addleft(root,ans);
    addleaf(root,ans);
    addright(root,ans);
    return ans;
}
