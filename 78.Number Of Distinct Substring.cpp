//https://www.codingninjas.com/studio/problems/number-of-distinct-substring_8230842?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
class Node{
    Node *child[26];
    public:
        bool contains(char &ch){return child[ch-'a']!=NULL;}
        void putNext(char &ch,Node* newNode){child[ch-'a']=newNode;}
        Node* getNext(char &ch){return child[ch-'a'];}
};

class Trie{
    Node *root;
    int cnt=0;
    public:
        Trie(){
            root=new Node();
        }

        void insert(string &word){
            Node *tmp=root;
            for(auto &ch:word){
                if(!tmp->contains(ch)){
                    cnt++;
                    tmp->putNext(ch,new Node());
                }
                tmp=tmp->getNext(ch);
            }
        }

        int get(){return cnt;}
};
int distinctSubstring(string &word) {
    //  Write your code here.
    Trie T;
    int n=word.size();
    for(int i=0;i<n;i++){
        string tmp=word.substr(i);
        T.insert(tmp);
    }
    return T.get();
}
