
//https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_8230745?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    if(!root)return {};
    map<int,BinaryTreeNode<int>*>lola;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    while(q.size()){
        int pos=q.front().second;
        BinaryTreeNode<int>*curr=q.front().first;
        q.pop();

        lola[pos]=curr;
        if(curr->left)q.push({curr->left,pos-1});
        if(curr->right)q.push({curr->right,pos+1});
    }

    vector<int>ans;
    for(auto x:lola){
        ans.push_back(x.second->data);
    }
    return ans;
    
}
