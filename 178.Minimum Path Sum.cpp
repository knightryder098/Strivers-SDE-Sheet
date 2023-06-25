//https://www.codingninjas.com/studio/problems/minimum-path-sum_8230791?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
int helper(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    int n=grid.size();
    int m=grid[0].size();
    if(i==n-1 and j==m-1)return grid[i][j];
    if(i==n||j==m)return INT_MAX;

    if(dp[i][j]!=-1)return dp[i][j];


    int down=helper(i+1,j,grid,dp);
    int right=helper(i,j+1,grid,dp);
    
    return dp[i][j]=min(down,right)+grid[i][j];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return helper(0,0,grid,dp);
}
