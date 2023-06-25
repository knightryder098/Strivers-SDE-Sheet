//https://www.codingninjas.com/studio/problems/rod-cutting-problem_8230727?challengeSlug=striver-sde-challenge&leftPanelTab=1
int helper(int ind,int len,vector<int>&prices,vector<vector<int>>&dp){
	if(ind==0)return prices[ind]*len;
	if(dp[ind][len]!=-1)return dp[ind][len];
	int notcut=helper(ind-1,len,prices,dp);
	int cut=INT_MIN;
	if(ind+1<=len){
		cut=prices[ind]+helper(ind,len-(ind+1),prices,dp);
	}
	return dp[ind][len]=max(notcut,cut);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	return helper(n-1,n,price,dp);
}
