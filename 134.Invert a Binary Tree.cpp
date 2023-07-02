//https://www.codingninjas.com/studio/problems/invert-a-binary-tree_8230838?challengeSlug=striver-sde-challenge&leftPanelTab=0

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

bool storParents(TreeNode<int> *root, stack<TreeNode<int> *> &parents,TreeNode<int> *leaf) {
    
    parents.push(root);

    if (!root->left and !root->right) {
        if (root->data == leaf->data)
            return true;
        else
            parents.pop();
        return false;
    }

    if (root->left) {
        if (storParents(root->left, parents, leaf))
        return true;
    }

    if (root->right) {
        if (storParents(root->right, parents, leaf))
        return true;
    }

    parents.pop();
    return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf) {
  if (!root)
    return NULL;

  stack<TreeNode<int> *> parents;
  storParents(root, parents, leaf);

  TreeNode<int> *head = parents.top();
  parents.pop();

  TreeNode<int> *par = head;
  while (!parents.empty()) {
    auto p = parents.top();
    parents.pop();

    if (p->right == head) {
      p->right = p->left;
      p->left = NULL;
    } else {
      p->left = NULL;
    }

    head->left = p;
    head = p;
  }

  return par;
}

//if there is no particular node to make the root
//  TreeNode<int>* invertTree(TreeNode<int>* root) {
//         // Base Case
//         if(root==NULL)
//             return NULL;
//         invertTree(root->left); //Call the left substree
//         invertTree(root->right); //Call the right substree
//         // Swap the nodes
//         TreeNode<int>* temp = root->left;
//         root->left = root->right;
//         root->right = temp;
//         return root; // Return the root
//     }
