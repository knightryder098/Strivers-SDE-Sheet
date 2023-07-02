
//https://www.codingninjas.com/studio/problems/construct-bst-from-preorder-traversal_8230850?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(vector<int> &arr, int &i, int bound){
    if(i == arr.size() || arr[i]>bound) return NULL;
    
    TreeNode<int>* root = new TreeNode<int>(arr[i++]);
    
    root->left = solve(arr, i, root->data);
    root->right = solve(arr, i, bound);
    
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0;
    int bound = 100000;
    return solve(preOrder, i, bound);
}
