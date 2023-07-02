//https://www.codingninjas.com/studio/problems/connect-nodes-at-same-level_8230790?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.

     if(!root)return;
        queue<BinaryTreeNode<int>*>pq;
        pq.push(root);
        while(pq.size()){
            BinaryTreeNode<int>* last=nullptr;
            for(int i=pq.size();i>0;i--){
                BinaryTreeNode<int>* curr=pq.front();pq.pop();
                curr->next=last;
                last=curr;
                if(curr->right){
                    pq.push(curr->right);
                }
                if(curr->left)pq.push(curr->left);
            }
        }
    
}
