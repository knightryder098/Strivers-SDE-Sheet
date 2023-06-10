
// https://www.codingninjas.com/codestudio/problems/word-break-ii_8230786?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include <bits/stdc++.h> 
void helper(int ind,string &curr,string &s,unordered_set<string>&visited,vector<string>&ans){
  if(ind==s.length()){
      curr.pop_back();
      ans.push_back(curr);
      return;
  }
  string word="";
  for(int i=ind;i<s.length();i++){
      word+=s[i];
      if(visited.find(word)!=visited.end()){
          string tmp=curr+word+" ";
          helper(i+1,tmp,s,visited,ans);
      }
  }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_set<string>visited(begin(dictionary),end(dictionary));
    vector<string>ans;
    string curr="";
    helper(0,curr,s,visited,ans);
    return ans;

}
