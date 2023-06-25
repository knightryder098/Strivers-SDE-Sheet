//https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_8230691?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
long helper(int ind,int val,int *denominations,vector<vector<long>>&dp){
    if(ind==0){
        if(val%denominations[ind]==0)return 1;
        else
        return 0;
    }
    if(dp[ind][val]!=-1)return dp[ind][val];
    long nottake=helper(ind-1,val,denominations,dp);
    long take=0;
    if(denominations[ind]<=val)
    take=helper(ind,val-denominations[ind],denominations,dp);

    return dp[ind][val]=take+nottake;

}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    sort(denominations,denominations+n);
    vector<vector<long>>dp(n,vector<long>(value+1,-1));
    return helper(n-1,value,denominations,dp);
}
