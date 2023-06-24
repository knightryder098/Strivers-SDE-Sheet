//https://www.codingninjas.com/studio/problems/left-view-of-a-binary-tree_8230757?challengeSlug=striver-sde-challenge&leftPanelTab=0

Left View Of a Binary Tree#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if(!root)return {};
    vector<int>ans;
    queue<TreeNode<int>*>q;
    q.push(root);
    int level=0;
    while(q.size()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            TreeNode<int>*curr=q.front();
            q.pop();
            if(level==ans.size())ans.push_back(curr->data);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        level++;
    }
    return ans;
}
