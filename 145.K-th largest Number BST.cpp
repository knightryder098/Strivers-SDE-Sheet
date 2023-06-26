//https://www.codingninjas.com/studio/problems/k-th-largest-number-bst_8230750?challengeSlug=striver-sde-challenge&leftPanelTab=1

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

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    TreeNode<int>* curr = root;
    
 
    // count variable to keep count of visited Nodes
    int count = 0;
 
    while (curr != NULL) {
        // if right child is NULL
        if (curr->right == NULL) {
 
            // first increment count and check if count = k
            if (++count == k)
                return curr->data;
 
            // otherwise move to the left child
            curr = curr->left;
        }
 
        else {
 
            // find inorder successor of current Node
            TreeNode<int>* succ = curr->right;
 
            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;
 
            if (succ->left == NULL) {
 
                // set left child of successor to the
                // current Node
                succ->left = curr;
 
                // move current to its right
                curr = curr->right;
            }
 
            // restoring the tree back to original binary
            //  search tree removing threaded links
            else {
 
                succ->left = NULL;
 
                if (++count == k)
                   return curr->data;
 
                // move current to its left child
                curr = curr->left;
            }
        }
    }
 
    return -1;
}

