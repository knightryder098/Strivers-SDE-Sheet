//https://www.codingninjas.com/codestudio/problems/level-order-traversal_8230716?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(!root)return {};
    vector<int>ans;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(q.size()){
        BinaryTreeNode<int>* curr=q.front();
        q.pop();
        ans.push_back(curr->val);
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
    return ans;
}
