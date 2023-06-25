//https://www.codingninjas.com/studio/problems/edit-distance_8230685?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>

int helper(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i==0)return j;
    if(j==0)return i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i-1]==t[j-1])
    return dp[i][j]=helper(i-1,j-1,s,t,dp);
    else{
    int del=1+helper(i-1,j,s,t,dp);
    int ins=1+helper(i,j-1,s,t,dp);
    int rep=1+helper(i-1,j-1,s,t,dp);
    return dp[i][j]=min({del,ins,rep});
    }
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return helper(n,m,str1,str2,dp);
}
