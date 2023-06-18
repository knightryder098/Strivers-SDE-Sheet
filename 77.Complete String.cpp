//https://www.codingninjas.com/codestudio/problems/complete-string_8230849?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
class Node{
    Node *child[26];
    bool isEnd=false;
    public:
        bool contains(char &ch){return child[ch-'a']!=NULL;}
        void putNext(char &ch,Node* newNode){child[ch-'a']=newNode;}
        Node* getNext(char &ch){return child[ch-'a'];}
        void setEnd(){isEnd=true;}
        bool getEnd(){return isEnd;}
} ;
class Trie{
    Node * root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(string &word){
            Node *tmp=root;
            for(auto &ch:word){
                if(!tmp->contains(ch)){
                    tmp->putNext(ch,new Node());
                }
                tmp=tmp->getNext(ch);
            }
            tmp->setEnd();
        }

        void longest(string &word,string &ans){
            Node *tmp=root;
            for(auto &ch:word){
                if(!tmp->contains(ch))return;
                tmp=tmp->getNext(ch);
                if(tmp->getEnd()==false)return;
            }

            if(word.size()>ans.size()){
                ans=word;
            }
            else if(ans.size()==word.size() and word<ans){
                ans=word;
            }
        }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie T;
    for(auto x:a){
        T.insert(x);
    }
    string ans="";
    for(auto x:a){
        T.longest(x,ans);
    }
    if(ans=="")return "None";
    return ans;
}
