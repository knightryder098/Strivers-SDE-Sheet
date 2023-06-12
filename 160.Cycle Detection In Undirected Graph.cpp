
// /https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_8230798?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>>graph(n+1,vector<int>());
    for(auto x:edges){
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }

    vector<int>visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            visited[i]=1;
            queue<pair<int,int>>q;
            q.push({i,-1});
            while(!q.empty()){
                int src=q.front().first;
                int par=q.front().second;
                q.pop();
                for(auto child:graph[src]){
                    if(!visited[child]){
                        visited[child]=1;
                        q.push({child,src});
                    } else if(child!=par)return "Yes";
                }
            }
        }
    }
    return "No";
}
