
//https://www.codingninjas.com/studio/problems/path-in-a-tree_8230860?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

void helper(vector<int>&ans,int val,TreeNode<int>*root){
	if(!root)return;
	ans.push_back(root->data);
	if(root->data==val)return;
	helper(ans,val,root->left);
	helper(ans,val,root->right);
	if(ans.back()!=val)ans.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	if(!root)return {};
	vector<int>ans;
	int found=0;
	helper(ans,x,root);
	return ans;
}
