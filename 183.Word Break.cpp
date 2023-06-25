//https://www.codingninjas.com/studio/problems/word-break_8230808?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
bool helper(int ind,set<string>&lola,string &tar,int n){
    if(ind==n)return true;
    string word="";
    for(int i=ind;i<n;i++){
        word+=tar[i];
        if(lola.find(word)!=lola.end()){
            return helper(i+1,lola,tar,n);
        }
    }
    return false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    int m=target.size();
    set<string>lola(arr.begin(),arr.end());
    return helper(0,lola,target,m);
}
