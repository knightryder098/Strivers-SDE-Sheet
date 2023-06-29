//https://www.codingninjas.com/studio/problems/topological-sort_8230784?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
// void dfs(int src,stack<int>&st,vector<vector<int>>&graph,vector<int>&visited){
//     visited[src]=1;
//     for(auto x:graph[src]){
//         if(visited[x]==0)dfs(x,st,graph,visited);
//     }
//     st.push(src);
// }
// vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
//     // Write your code here
//     vector<vector<int>>graph(v,vector<int>());
//     for(auto x:edges){
//         graph[x[0]].push_back(x[1]);
//     }

//     vector<int>visited(v,0);
//     stack<int>st;
//     for(int i=0;i<v;i++){
//         if(visited[i]==0){
//             dfs(i,st,graph,visited);
//         }
//     }

//     vector<int>ans;
    
//     while(!st.empty()){
//         int par=st.top();
//         st.pop();
//         ans.push_back(par);
//     }
    
//     return ans;
// }

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {

    vector<int>inorder(v,0);
    vector<vector<int>>graph(v,vector<int>());
    for(auto x:edges){
        inorder[x[1]]++;
        graph[x[0]].push_back(x[1]);
    }

    queue<int>q;
    for(int i=0;i<v;i++){
        if(inorder[i]==0)q.push(i);
    }
    vector<int>ans;
    while(q.size()){
        int par=q.front();q.pop();
        ans.push_back(par);
        for(auto x:graph[par]){
            inorder[x]--;
            if(inorder[x]==0){
                q.push(x);
            }
        }
    }

    return ans;
}
