
//https://www.codingninjas.com/codestudio/problems/strongly-connected-components-tarjan-s-algorithm_8230789?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
void dfs(int src,vector<int>&visited,vector<vector<int>>&graph,stack<int>&lola){
    visited[src]=1;
    for(auto x:graph[src]){
        if(visited[x]==0){
            dfs(x,visited,graph,lola);
        }
    }
    lola.push(src);
}
void dfs2(int src,vector<vector<int>>&graph,vector<int>&visited,vector<int>&tmp){
    // cout<<"LELE ";
    visited[src]=1;
    tmp.push_back(src);
    for(auto x:graph[src]){
        if(visited[x]==0){
            dfs2(x,graph,visited,tmp);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>>graph(n,vector<int>()),graphT(n,vector<int>());
    for(auto x:edges){
        graph[x[0]].push_back(x[1]);
        graphT[x[1]].push_back(x[0]);
    }

    stack<int>lola;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(visited[i]==0)dfs(i,visited,graph,lola);
    }
    // while(!lola.empty()){
    //     cout<<lola.top()<<" ";lola.pop();
    // }
    // cout<<"\n";
    for(int i=0;i<n;i++)visited[i]=0;
    vector<vector<int>>ans;
    while(!lola.empty()){
        // cout<<"LELE";
        int src=lola.top();
        lola.pop();
        // cout<<src<<" ";
        if(visited[src]==1)continue;
        vector<int>tmp;
        dfs2(src,graphT,visited,tmp);
        // sort(begin(tmp),end(tmp));
        ans.push_back(tmp);
    }
    return ans;
}
