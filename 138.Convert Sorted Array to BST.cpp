//https://www.codingninjas.com/studio/problems/convert-sorted-array-to-bst_8230836?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* solve(vector<int> &arr, int e, int s){
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = solve(arr, mid-1, s);
    root->right = solve(arr, e, mid+1);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return solve(arr, n-1, 0);
}
