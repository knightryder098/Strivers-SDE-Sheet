/
//https://www.codingninjas.com/studio/problems/ceil-from-bst_8230754?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    if(!node)return -1;
    if(node->data==x)return x;
    if(node->data<x)return findCeil(node->right,x);
    int left=findCeil(node->left,x);
    return (left!=-1&& left>=x)?left:node->data;
    
}
