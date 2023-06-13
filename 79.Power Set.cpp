// https://www.codingninjas.com/codestudio/problems/power-set_8230797?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n=v.size();
    vector<vector<int>>ans;
    for(int i=1;i<(1<<n);i++){
        vector<int>tmp;
        for(int j=0;j<n;j++){
            if(i&(1<<j))tmp.push_back(v[j]);
        }
        ans.push_back(tmp);
    }
    return ans;
}
