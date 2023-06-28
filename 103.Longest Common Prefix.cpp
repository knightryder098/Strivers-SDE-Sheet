//https://www.codingninjas.com/studio/problems/longest-common-prefix_8230847?challengeSlug=striver-sde-challenge&leftPanelTab=1
class Node{
    Node*child[26];
    bool isEnd=false;
    public:
        bool contains(char &ch){return child[ch-'a']!=NULL;}
        void putNext(char&ch,Node* newNode){child[ch-'a']=newNode;}
        Node* getNext(char &ch){return child[ch-'a'];}
        void setEnd(){isEnd=true;}
        bool getEnd(){return isEnd;}
};

class Trie{
    Node *root;
    public:
        Trie(){
            root=new Node();
        }

        void insert(string &word){
            Node* tmp=root;
            for(auto &ch:word){
                if(!tmp->contains(ch)){
                    tmp->putNext(ch,new Node());
                }
                tmp=tmp->getNext(ch);
            }
            tmp->setEnd();
        }

        int helper(Node * root,int &index){
        int ct=0;
        for(int i=0;i<26;i++){
            char ch='a'+i;
            if(root->contains(ch)){
                ct++;
                index=i;
            }
            else
            if(ct>1)break;
        }
        return ct;
    }

    string lcp(){
        Node *tmp=root;
        int i;
        string ans="";
        while(helper(tmp,i)==1 and tmp->getEnd()==false){
            char ch='a'+i;
            tmp=tmp->getNext(ch);
            ans+=ch;
        }
        return ans;
    }


};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here

    // Trie T;
    // int maxi=-1;
    // for(auto &word:arr){
    //     int len=word.length();
    //     maxi=max(len,maxi);
    //     T.insert(word);
    // }
    
    // return T.lcp();


    if(arr.empty()) return "";
    
    int m=arr[0].length();
    for(int j=0;j<m;j++){
        char c=arr[0][j];
        for(int i=1;i<n;i++){
            if(j>=arr[i].length()||arr[i][j]!=c){
                return arr[0].substr(0,j);
            }
        }
    }
    return arr[0];
}


