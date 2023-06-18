//https://www.codingninjas.com/codestudio/problems/m-coloring-problem_8230777?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
bool isSafe(int col,int src,vector<vector<int>>&mat,vector<int>&color){
    for(int i=0;i<mat.size();i++){
        if(mat[src][i]==1 and color[i]==col)return false;
    }
    return true;
}
bool helper(int src,vector<vector<int>>&mat,vector<int>&color,int col){
    if(src==mat.size())return true;
    for(int x=1;x<=col;x++){
        if(isSafe(x,src,mat,color)){
            color[src]=x;
            if(helper(src+1,mat,color,col))return true;
            color[src]=0;
        }
    }
    return false;
} 
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int>colors(n,0);
    if(helper(0,mat,colors,m))return "YES";
    else
    return "NO";
}
