
// https://www.codingninjas.com/codestudio/problems/implement-trie_8230696?challengeSlug=striver-sde-challenge&leftPanelTab=1


/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node{
    Node *child[26];
    bool isend=false;
    public:
        bool contains(char &ch){return child[ch-'a']!=NULL;}
        void putNext(char &ch,Node* newNode){child[ch-'a']=newNode;}
        Node *getNext(char &ch){return child[ch-'a'];}
        void setEnd(){isend=true;}
        bool getEnd(){return isend;}
};

class Trie {
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * tmp=root;
        for(auto &ch:word){
            if(!tmp->contains(ch)){
                tmp->putNext(ch,new Node());
            }
            tmp=tmp->getNext(ch);
        }
        tmp->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * tmp=root;
        for(auto &ch:word){
            if(tmp->contains(ch)){
                tmp=tmp->getNext(ch);
            }
            else
            return false;
        }
        return tmp->getEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * tmp=root;
        for(auto &ch:prefix){
         if(tmp->contains(ch)){
                tmp=tmp->getNext(ch);
            }
            else
            return false;
        }
        return true;
    
    }
};
