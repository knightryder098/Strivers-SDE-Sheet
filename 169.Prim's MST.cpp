
//https://www.codingninjas.com/studio/problems/prim-s-mst_8230809?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<int>parent(n+1,-1),visited(n+1,0),distance(n+1,INT_MAX);
    vector<vector<pair<int,int>>>graph(n+1,vector<pair<int,int>>());
    for(auto x:g){
        int u=x.first.first;
        int v=x.first.second;
        int w=x.second;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    priority_queue<pair<int,int>>pq;
    pq.push({0,1});
    distance[1]=0;
    
    parent[1]=1;
    while(pq.size()){
        int par=pq.top().second;
        pq.pop();
        visited[par]=1;
        for(auto x:graph[par]){
            int v=x.first;
            int wt=x.second;
            if(visited[v]==0 and wt<distance[v]){
                parent[v]=par;
                distance[v]=wt;
                pq.push({-distance[v],v});
            }
        }
    }
    vector<pair<pair<int,int>,int>>ans;
    for(int i=2;i<=n;i++){
        int u=parent[i],v=i,w=distance[i];
        ans.push_back({{u,v},w});
    }
    return ans;
    
}
