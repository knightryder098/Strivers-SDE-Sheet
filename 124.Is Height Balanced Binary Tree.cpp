//https://www.codingninjas.com/studio/problems/is-height-balanced-binary-tree_8230771?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
int height(BinaryTreeNode<int>*root){
    if(!root)return 0;
    int l=height(root->left);
    if(l==-1)return -1;
    int r=height(root->right);
    if(r==-1)return -1;
    if(abs(l-r)>1)return -1;
    return max(l,r)+1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(!root)return true;
    if(height(root)==-1)return false;
    return true;
}
