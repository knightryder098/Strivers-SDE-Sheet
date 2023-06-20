//https://www.codingninjas.com/studio/problems/merge-k-sorted-arrays_8230770?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int>pq;
    for(auto x:kArrays){
        for(auto xx:x)pq.push(-xx);
    }
    vector<int>ans;
    while(pq.size()){
        ans.push_back(-1*pq.top());
        pq.pop();
    }
    return ans;
}
