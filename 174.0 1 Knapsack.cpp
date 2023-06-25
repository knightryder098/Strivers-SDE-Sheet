//https://www.codingninjas.com/studio/problems/0-1-knapsack_8230801?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include<bits/stdc++.h>
int helper(int ind,int tot,vector<pair<int,int>>&bag,vector<vector<int>>&dp){
	if(ind==0){
		if(bag[ind].first<=tot)return bag[ind].second;
		return 0;
	}
	if(dp[ind][tot]!=-1)return dp[ind][tot];
	int notTake=helper(ind-1,tot,bag,dp);
	int take=0;
	if(bag[ind].first<=tot){
		take+=bag[ind].second+helper(ind-1,tot-bag[ind].first,bag,dp);
	}

	return dp[ind][tot]=max(take,notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<pair<int,int>>bag;
	for(int i=0;i<n;i++){
		bag.push_back({weights[i],values[i]});
	}

	sort(begin(bag),end(bag));
	vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
	return helper(n-1,w,bag,dp);
}
