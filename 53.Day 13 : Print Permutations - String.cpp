// https://www.codingninjas.com/codestudio/problems/day-13-print-permutations-string_8230703?challengeSlug=striver-sde-challenge&leftPanelTab=0



#include <bits/stdc++.h> 
void helper(string &s,int l,int r,vector<string>&ans){
    if(l==r){
        ans.push_back(s);
        return;
    }

    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        helper(s,l+1,r,ans);
        swap(s[i],s[l]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    sort(begin(s),end(s));
    helper(s,0,s.length()-1,ans);
    return ans;
}
