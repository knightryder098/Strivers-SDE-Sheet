//https://www.codingninjas.com/studio/problems/diameter-of-binary-tree_8230762?challengeSlug=striver-sde-challenge&leftPanelTab=1

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
int getHeight(TreeNode<int>*root,int &ans){
    if(!root)return 0;
    int l=getHeight(root->left,ans);
    int r=getHeight(root->right,ans);
    ans=max(ans,l+r);
    return max(l,r)+1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans=0;
    getHeight(root,ans);
    return ans; 
}
