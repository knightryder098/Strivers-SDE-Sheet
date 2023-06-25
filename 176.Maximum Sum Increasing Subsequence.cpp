//https://www.codingninjas.com/studio/problems/maximum-sum-increasing-subsequence_8230821?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
int helper(int ind,int prev,vector<int>&rack,vector<vector<int>>&dp){
	int n=rack.size();
	if(ind==n)return 0;
	if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
	int notTake=helper(ind+1,prev,rack,dp);
	int take=0;
	if(prev==-1|| rack[ind]>rack[prev])
	take+=rack[ind]+helper(ind+1,ind,rack,dp);

	return dp[ind][prev+1]=max(take,notTake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	return helper(0,-1,rack,dp);
}
