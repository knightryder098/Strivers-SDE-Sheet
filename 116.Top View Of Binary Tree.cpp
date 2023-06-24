//https://www.codingninjas.com/studio/problems/top-view-of-binary-tree_8230721?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
  // Write your code here.
  if(!root)return {};
  map<int,TreeNode<int>*> column;
  queue<pair<TreeNode<int> *, int>> q;
    q.push({root,0});
    vector<int>ans;
    while(q.size()){
        TreeNode<int>* curr=q.front().first;
        int pos=q.front().second;
        q.pop();

        if(column.find(pos)==column.end()){
            column[pos]=curr;
        }

        if(curr->left)q.push({curr->left,pos-1});
        if(curr->right)q.push({curr->right,pos+1});
    }

    for(auto x:column){
        ans.push_back(x.second->val);
    }
    return ans;
}
