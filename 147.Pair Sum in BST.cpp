//https://www.codingninjas.com/studio/problems/pair-sum-in-bst_8230756?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
bool helper(BinaryTreeNode<int>*root,int k,unordered_map<int,bool>&mp){
    if(!root)return false;
    int curr=root->data;
    if(mp.find(k-curr)!=mp.end())return true;
    mp[curr]=true;
    return helper(root->left,k,mp)|helper(root->right,k,mp);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    if(!root)return false;
    unordered_map<int,bool>mp;
    return helper(root,k,mp);
}
