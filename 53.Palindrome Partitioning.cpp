//https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_8230726?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

bool check(int l,int r, string s){
    while(l<=r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;r--;
    }
    return true;
}

void helper(int ind,string &s,vector<string>&curr,vector<vector<string>>&ans){
    if(ind==s.size()){
        ans.push_back(curr);
        return;
    }

    for(int i=ind;i<s.size();i++){
        if(check(ind,i,s)){
            string tmp=s.substr(ind,i-ind+1);
            curr.push_back(tmp);
            helper(i+1,s,curr,ans);
            curr.pop_back();
        }
    }
}


vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>>ans;
    vector<string>curr;
    helper(0,s,curr,ans);
    return ans;
}
