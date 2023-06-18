//https://www.codingninjas.com/codestudio/problems/implement-trie-ll_8230840?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
class Node{
    Node *child[26];
    int cntEnd=0;
    int cntPref=0;
    public:
        bool contains(char &ch){return child[ch-'a']!=NULL;}
        void putNext(char &ch,Node* newNode){child[ch-'a']=newNode;}
        Node *getNext(char &ch){return child[ch-'a'];}
        void setEnd(){cntEnd++;}
        void setPref(){cntPref++;}
        void unsetEnd(){cntEnd--;}
        void unsetPref(){cntPref--;}
        int getEnd(){return cntEnd;}
        int getPref(){return cntPref;}
};
class Trie{
        Node *root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *tmp=root;
        for(auto &ch:word){
            if(!tmp->contains(ch)){
                tmp->putNext(ch,new Node());
            }
            tmp=tmp->getNext(ch);
            tmp->setPref();
        }
        tmp->setEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node *tmp=root;
        for(auto &ch:word){
            if(!tmp->contains(ch))return 0;
            tmp=tmp->getNext(ch);
        }
        return tmp->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node *tmp=root;
        for(auto &ch:word){
            if(!tmp->contains(ch))return 0;
            tmp=tmp->getNext(ch);
        }
        return tmp->getPref();
    }

    void erase(string &word){
        // Write your code here.
        Node *tmp=root;
        for(auto &ch:word){
            if(!tmp->contains(ch))return;
            tmp=tmp->getNext(ch);
            tmp->unsetPref();
        }
        tmp->unsetEnd();
    }
};
