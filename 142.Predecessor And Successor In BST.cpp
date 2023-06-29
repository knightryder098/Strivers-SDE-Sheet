
//https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_8230742?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void solve(BinaryTreeNode<int>*root,int key,int &p,int &s){
    if(!root)return;
    solve(root->left,key,p,s);
    if(root->data<key){
        p=root->data;
    }
    if(root->data>key and s==-1){
        s=root->data;
    }
    solve(root->right,key,p,s);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int p=-1,s=-1;
    if(!root)return {p,s};
    solve(root,key,p,s);
    return {p,s};
}
