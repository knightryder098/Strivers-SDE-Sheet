//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_8230844?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
bool helper(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp){
    if(tar==0)return true;
    if(tar<0)return false;
    if(ind==0)return arr[0]==tar;
    if(dp[ind][tar]!=-1)return dp[ind][tar];
    if(arr[ind]<=tar){
        return dp[ind][tar]=helper(ind-1,tar-arr[ind],arr,dp)|helper(ind-1,tar,arr,dp);
    }
    return dp[ind][tar]=helper(ind-1,tar,arr,dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    sort(begin(arr),end(arr));
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return helper(n-1,k,arr,dp);
}
