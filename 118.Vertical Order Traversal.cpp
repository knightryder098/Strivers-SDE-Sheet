//https://www.codingninjas.com/studio/problems/vertical-order-traversal_8230758?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.

        map<int,vector<pair<int,int>>>location;
        queue<pair<TreeNode<int>*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size()){
            TreeNode<int>* par=q.front().first;
            int pos=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            location[pos].push_back({par->data,level});
            if(par->left)q.push({par->left,{pos-1,level+1}});
            if(par->right)q.push({par->right,{pos+1,level+1}});
        }

        vector<int>ans;
        for(auto x:location){
            for(auto xx:x.second)
            ans.push_back(xx.first);
        }
        return ans;

}
