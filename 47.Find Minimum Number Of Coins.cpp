//https://www.codingninjas.com/codestudio/problems/find-minimum-number-of-coins_8230766?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int>coins={1,2,5,10,20,50,100,500,1000};
int helper(int i,int tar,vector<vector<int>>&dp){
    if(i==0)return tar;
    if(tar==0)return 0;
    if(dp[i][tar]!=-1)return dp[i][tar];
    if(tar>=coins[i]){
        int cnt=tar/coins[i];
        int rem=tar%coins[i];
        return dp[i][tar]=cnt+helper(i-1,rem,dp);
    }
    else{
        return dp[i][tar]=helper(i-1,tar,dp);
    }
}
int findMinimumCoins(int amount) 
{
    // Write your code here
    // vector<vector<int>>dp(9,vector<int>(amount+1,-1));
    // return helper(8,amount,dp);

    vector<vector<int>> dp(9, vector<int>(amount + 1, INT_MAX));
    
    // Initialization
    for(int i=0;i<=8;i++)
        dp[i][0]=0;
    
    for(int j=1;j<=amount;j++){
        for(int i=0;i<=8;i++){
            if(i==0){
                dp[i][j]=j; // Maximum number of coins required to form j using only 1-rupee coin
            }
            else{
                dp[i][j]=dp[i-1][j]; // If i-th coin not used
                if(j>=coins[i]){
                    dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]); // If i-th coin is used
                }
            }
        }
    }

    return dp[8][amount];
}
