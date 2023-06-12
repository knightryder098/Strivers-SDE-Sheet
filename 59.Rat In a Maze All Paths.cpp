// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze-all-paths_8230705?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
void helper(int i,int j,vector<vector<int>>&ans,vector<vector<int>>&maze){
  int n=maze.size();
  if(i==n-1 and j==n-1){
    vector<int>tmp;
    for(auto x:maze){
      for(auto y:x)if(y==2)tmp.push_back(1);
      else
      tmp.push_back(0);
    }
    ans.push_back(tmp);
    return;
  }  
  int dr[]={0,1,-1,0};
  int dc[]={1,0,0,-1};
  for(int x=0;x<4;x++){
    int ni=i+dr[x];
    int nj=j+dc[x];
    if(ni>=0 and nj>=0 and ni<n and nj<n and maze[ni][nj]==1){
      maze[ni][nj]=2;
      helper(ni,nj,ans,maze);
      maze[ni][nj]=1;
    }
  }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here
  if(maze[0][0]==0||maze[n-1][n-1]==0)return {};
  vector<vector<int>>ans;
  maze[0][0]=2;
  helper(0,0,ans,maze);
  return ans; 
}
