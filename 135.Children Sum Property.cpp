//https://www.codingninjas.com/studio/problems/children-sum-property_8230711?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void change(BinaryTreeNode<int>*root){
    if(!root)return;
    int child=0;
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;
    if(child<root->data){
        if(root->left)root->left->data=root->data;
        else if(root->right)root->right->data=root->data;
    }
    change(root->left);
    change(root->right);
    int sum=0;
    if(root->left)sum+=root->left->data;
    if(root->right)sum+=root->right->data;
    if(root->left||root->right)root->data=sum;
}

void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    change(root);
}  
