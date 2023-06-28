//https://www.codingninjas.com/studio/problems/symmetric-tree_8230686?challengeSlug=striver-sde-challenge&leftPanelTab=1

/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool symmtric(BinaryTreeNode<int>* left,BinaryTreeNode<int>* right)
    {
        if(left==NULL || right==NULL)
            return (left==right);
        if(left->data!=right->data)
            return false;
        return (symmtric(left->left,right->right)&& symmtric(left->right,right->left));
    }
bool isSymmetric(BinaryTreeNode<int>* root) {   
    if(!root)return true;     
    return (symmtric(root->left,root->right));
}



