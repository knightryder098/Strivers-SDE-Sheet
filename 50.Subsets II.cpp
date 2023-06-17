//https://www.codingninjas.com/codestudio/problems/subsets-ii_8230855?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<(1<<n);i++){
        vector<int>curr;
        for(int j=0;j<n;j++){
            if(i&(1<<j))curr.push_back(arr[j]);
        }
        ans.insert(curr);
    }
    vector<vector<int>>res(ans.begin(),ans.end());
   
    // return vector<vector<int>>(ans.begin(),ans.end());
    return res;
}
