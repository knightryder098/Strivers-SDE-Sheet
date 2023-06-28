//https://www.codingninjas.com/studio/problems/binary-tree-zigzag-traversal_8230796?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>ans;
    if(!root)return {};
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    int lev=0;
    while(q.size()){
        int sz=q.size();
        vector<int>tmp;
        for(int i=0;i<sz;i++){
            BinaryTreeNode<int>*curr=q.front();
            q.pop();
            tmp.push_back(curr->data);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }

        if(lev%2==0){
            for(auto x:tmp)ans.push_back(x);
        }
        else{
            reverse(tmp.begin(),tmp.end());
            for(auto x:tmp)ans.push_back(x);
        }
        lev++;
    }
    return ans;
}
