//https://www.codingninjas.com/studio/problems/count-distinct-element-in-every-k-size-window_8230749?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    map<int,int>lola;
    vector<int>ans;
    for(int i=0;i<k;i++)lola[arr[i]]++;
    int start=0;
    ans.push_back(lola.size());
    for(int i=k;i<arr.size();i++){
        int curr=arr[i];
        lola[arr[i-k]]--;
        if(lola[arr[i-k]]==0)lola.erase(arr[i-k]);
        lola[arr[i]]++;
        ans.push_back(lola.size());
    }
    return ans;
	
}
