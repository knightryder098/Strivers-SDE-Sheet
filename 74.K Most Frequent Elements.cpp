//https://www.codingninjas.com/studio/problems/k-most-frequent-elements_8230853?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int>lola;
    for(auto x:arr)lola[x]++;
    vector<pair<int,int>>tmp;
    for(auto x:lola)tmp.push_back(x);
    sort(tmp.begin(),tmp.end(),[&](const pair<int,int>&a,const pair<int,int>&b){return a.second>b.second;});
    vector<int>ans;
    for(int i=0;i<k;i++){
        ans.push_back(tmp[i].first);
    }
    sort(begin(ans),end(ans));
    return ans;
}
