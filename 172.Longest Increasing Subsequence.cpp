//https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_8230689?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
int helper(int ind,int prev,int arr[],int n,vector<vector<int>>&dp){
    if(ind==n)return 0;
    if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

    int len=helper(ind+1,prev,arr,n,dp);
    if(prev==-1||arr[ind]>arr[prev]){
        len=max(len,1+helper(ind+1,ind,arr,n,dp));
    }
    
    return dp[ind][prev+1]=len;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // if(n<=1)return n;
    // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    // return helper(0,-1,arr,n,dp);
    vector<int>tmp;
    tmp.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(tmp.back()<arr[i]){
            tmp.push_back(arr[i]);
        }
        else{
            auto it=lower_bound(tmp.begin(),tmp.end(),arr[i]);
            *it=arr[i];
        }
    }
    return tmp.size();
}
