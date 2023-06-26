//https://www.codingninjas.com/studio/problems/search-in-bst_8230841?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(!root)return false;
    if(root->data==x)return true;
    if(x<root->data)return searchInBST(root->left,x);
    else
    return searchInBST(root->right,x);
}
