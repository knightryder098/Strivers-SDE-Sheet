//https://www.codingninjas.com/studio/problems/check-permutation_8230834?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int n=str1.size(),m=str2.size();
    if(n!=m)return false;
    vector<int>dict(26,0);
    for(auto x:str1)dict[x-'a']++;
    for (auto x : str2) {
      if(dict[x-'a']==0)return false;
      dict[x - 'a']--;
    }
    return true;
}
