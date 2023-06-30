//https://www.codingninjas.com/studio/problems/serialize-and-deserialize-binary-tree_8230748?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(!root)
        return "";
        string ans="";
        queue<TreeNode<int>*>lola;
        lola.push(root);
        while(!lola.empty()){
            TreeNode<int>* hehe=lola.front();
            lola.pop();
            if(!hehe)
            ans+="#,";
            else
            ans+=to_string(hehe->data)+',';

            if(hehe){
                lola.push(hehe->left);
                lola.push(hehe->right);
            }
        }
        return ans;

}

TreeNode<int>* deserializeTree(string &data)
{
 //    Write your code here for deserializing the tree
        if(data.empty())
        return NULL;

        stringstream s(data);
        string num;
        getline(s,num,',');
        TreeNode<int>*root=new TreeNode<int>(stoi(num));
        queue<TreeNode<int>*>lola;
        lola.push(root);
        while(!lola.empty()){
            TreeNode<int>* hehe=lola.front();
            lola.pop();

            getline(s,num,',');
            if(num=="#"){
                hehe->left=NULL;
            }
            else{
                TreeNode<int>* ll=new TreeNode<int>(stoi(num));
                hehe->left=ll;
                lola.push(ll);
            }

            getline(s,num,',');

            if(num=="#"){
                hehe->right=NULL;
            }
            else{
                TreeNode<int>* rr=new TreeNode<int>(stoi(num));
                hehe->right=rr;
                lola.push(rr);
            }

        }
        return root;

}



