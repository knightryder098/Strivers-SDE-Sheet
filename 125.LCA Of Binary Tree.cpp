
//https://www.codingninjas.com/studio/problems/lca-of-binary-tree_8230760?challengeSlug=striver-sde-challenge&leftPanelTab=1

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

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	// Recursive Approach
    // Base Case
    // Time Complexity: O(N)
    // Space Complexity: O(Height)
    if(root == NULL) return -1;
    if(root->data == x) return x;
    if(root->data == y) return y;
    int left = lowestCommonAncestor(root->left, x, y);
    int right = lowestCommonAncestor(root->right, x, y);
    if(left != -1 && right != -1) return root->data;
    return max(left, right);
}
