//https://www.codingninjas.com/studio/problems/height-of-the-binary-tree-from-inorder-and-level-order-traversal_8230730?challengeSlug=striver-sde-challenge&leftPanelTab=1


#include <bits/stdc++.h> 
// template <typename T>
// class TreeNode {
// public:
//     T val;
//     TreeNode<T> *left;
//     TreeNode<T> *right;

//     TreeNode(T val) {
//         this->val = val;
//         left = nullptr;
//         right = nullptr;
//     }
// };

// TreeNode<int>* buildTree(vector<int>& inorder, vector<int>& levelorder) {
//     if (inorder.empty() || levelorder.empty()) {
//         return nullptr;
//     }
//     TreeNode<int> *root = new TreeNode<int>(levelorder[0]);

//     auto it = find(inorder.begin(), inorder.end(), root->val);
//     int pos = it - inorder.begin();

//     vector<int> leftinorder(inorder.begin(), it);
//     vector<int> rightinorder(it + 1, inorder.end());
//     vector<int> level_left, level_right;
//     for (int i = 1; i < levelorder.size(); i++) {
//         auto it = find(leftinorder.begin(), leftinorder.end(), levelorder[i]);
//         if (it != leftinorder.end()) {
//             level_left.push_back(levelorder[i]);
//         } else {
//             level_right.push_back(levelorder[i]);
//         }
//     }

//     root->left = buildTree(leftinorder, level_left);
//     root->right = buildTree(rightinorder, level_right);
//     return root;
// }



// int getheight(const TreeNode<int>* root) {
//     if (!root) {
//         return 0;
//     }
//     int l = getheight(root->left);
//     int r = getheight(root->right);
//     return max(l, r) + 1;
// }

// int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder,int n) {
//     TreeNode<int> *root = buildTree(inorder, levelOrder);
//     int height = getheight(root);
//     return height-1;
// }


struct newtype{
 int left , right ;
 int height  ;
   newtype(int l , int r, int h){
       left = l;
       right = r;
       height = h;
   }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
// Write your code here.
   queue<newtype>q;
   q.push({0,N-1,0});
   vector<int>pos(N+1,0);
   for(int i = 0 ; i<N ;i++){
       pos[inorder[i]] = i; // storing the position to get in order 1
   }
   int mxh = 0;
   for(int i = 0 ;i<N ;i++){
       int curr = levelOrder[i];
       int currPos = pos[curr] ; // ushe element ka kya position hai level order mein
       auto now = q.front();
       q.pop();
       int left = now.left;
       int right = now.right;
       int height = now.height;
       mxh = max(mxh,height);
       if(currPos>left){
//             means left child exist
           q.push({left,currPos-1 , height+1});
       }
       if(currPos<right){
//             means right child exits
           q.push({currPos+1,right,height+1});
       }
      
   }
   return mxh;
   
}


