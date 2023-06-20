//https://www.codingninjas.com/studio/problems/maximum-xor-of-two-numbers-in-an-array_8230852?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
class Node{
    Node *child[2];
    public:
        bool contains(int bit){return child[bit]!=NULL;}
        void putNext(int bit,Node* new_Node){child[bit]=new_Node;}
        Node* getNext(int bit){return child[bit];}
};
class Trie{
    Node *root;
    public:
        Trie(){
            root=new Node();
        }

        void insert(int num){
            Node *tmp=root;
            for(int i=31;i>=0;i--){
                int bit=((num>>i)&1);
                if(!tmp->contains(bit)){
                    tmp->putNext(bit,new Node());
                }
                tmp=tmp->getNext(bit);
            }
        }

        int maximumXor(int num){
            Node *tmp=root;
            int ans=0;
            for(int i=31;i>=0;i--){
                int bit=((num>>i)&1);
                if(tmp->contains(1-bit)){
                    ans|=(1<<i);
                    tmp=tmp->getNext(1-bit);
                }
                else{
                    tmp=tmp->getNext(bit);
                }
            }
            return ans;
        }
};
int maximumXor(vector<int> A)
{
    // Write your code here.   
    Trie T;
    for(auto x:A){
        T.insert(x);
    }

    int ans=0;
    for(auto x:A){
        ans=max(ans,T.maximumXor(x));
    }
    return ans;
}
