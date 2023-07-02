//https://www.codingninjas.com/studio/problems/lca-of-two-nodes-in-a-bst_8230778?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
 {  
  if(root==NULL)return NULL;
    if(root->data>P->data&&root->data>Q->data)
 return LCAinaBST(root->left,P,Q);   
 else
    if(root->data<P->data&&root->data<Q->data)
   return LCAinaBST(root->right,P,Q);   
   else{
     return root;  
  }
}  
