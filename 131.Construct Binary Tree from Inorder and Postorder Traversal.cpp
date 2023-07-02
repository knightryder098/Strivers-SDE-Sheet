
//https://www.codingninjas.com/studio/problems/construct-binary-tree-from-inorder-and-postorder-traversal_8230837?challengeSlug=striver-sde-challenge&leftPanelTab=1

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/


//postorder --> inorder
int len=0;
TreeNode<int>* helper(vector<int>&inorder,int i,int j,vector<int>&postorder){
     if(i>j)return nullptr;
     
     int rt=postorder[len--];
     TreeNode<int>*root=new TreeNode<int>(rt);
     int idx=i;
     for(int x=i;x<=j;x++){
          if(inorder[x]==rt){
               idx=x;
               break;
          }
     }
     root->right=helper(inorder,idx+1,j,postorder);
     root->left=helper(inorder,i,idx-1,postorder);
     return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     len=postOrder.size()-1;
     return helper(inOrder,0,len,postOrder);

}



///preorder -->inorder



    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     len=0;
    //     return helper(preorder,0,inorder.size()-1,inorder);
    // }

    // TreeNode* helper(vector<int>&preorder,int i,int j,vector<int>&inorder){
    //     if(i>j)return nullptr;

    //     int rt=preorder[len++];
    //     TreeNode* root= new TreeNode(rt);
    //     int idx=i;
    //     for(int x=i;x<=j;x++){
    //         if(inorder[x]==rt){
    //             idx=x;
    //             break;
    //         }
    //     }
    //     root->left=helper(preorder,i,idx-1,inorder);
    //     root->right=helper(preorder,idx+1,j,inorder);
    //     return root;
    // }

