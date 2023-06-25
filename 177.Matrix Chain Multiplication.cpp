//https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_8230769?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
int helper(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+helper(i,k,arr,dp)+helper(k+1,j,arr,dp);
        ans=min(ans,steps);
    }
    return dp[i][j]=ans;

}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
    return helper(1,N-1,arr,dp);
}
