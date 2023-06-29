//https://www.codingninjas.com/studio/problems/maximum-path-sum-between-two-leaves_8230713?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/


long helper(TreeNode<int>* root,long &ans){
    if(!root)return INT_MIN;
    if(!root->left and !root->right)return root->val;
    long int l=helper(root->left,ans);
    long int r=helper(root->right,ans);
    if(l==INT_MIN||r==INT_MIN)return max(l,r)+root->val;
    ans=max(ans,l+r+root->val);
    return max(l,r)+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)return -1;
    long ans=-1;
    helper(root,ans);
    return ans;
}




