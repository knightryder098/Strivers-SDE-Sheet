https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-preorder-traversal_8230759?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
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
TreeNode<int>* solver(vector<int> &inorder, vector<int> &preorder, unordered_map<int, int> &hash, int &index, int start, int end){
    // Base Case
    if(start == end){
        TreeNode<int>* root;
        root = new TreeNode<int>(preorder[index]);
        index++;
        return root;
    }
    // if(index < start || index > end) return NULL;
    if(start > end || end < 0) return NULL;
    // Make the node
    TreeNode<int>* root;
    root = new TreeNode<int>(preorder[index]);
    int mid = hash[preorder[index]];
    index++;
    // Build Left Sub-Tree
    root->left = solver(inorder, preorder, hash, index, start, mid-1);
    // Build Right Sub-Tree
    root->right = solver(inorder, preorder, hash, index, mid + 1, end);

    return root;
} 

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int n = preorder.size();
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[inorder[i]] = i;
    }
    int index = 0;
    return solver(inorder, preorder, hash, index, 0, n-1); 
}
