//https://www.codingninjas.com/studio/problems/dijkstra-s-shortest-path_8230755?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<vector<pair<int,int>>>graph(vertices,vector<pair<int,int>>());
    for(auto x:vec){
        int u=x[0],v=x[1],w=x[2];
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    vector<int>distance(vertices,INT_MAX);
    distance[source]=0;
    //min heap
    priority_queue<pair<int,int>>pq;
    pq.push({0,source});
    while(pq.size()){
        int par=pq.top().second;
        int curr=-1*pq.top().first;
        pq.pop();
        for(auto child:graph[par]){
            int v=child.first;
            int cost=child.second;
            if(cost+curr<distance[v]){
                distance[v]=cost+curr;
                pq.push({-distance[v],v});
            }
        }
    }

    
    return distance;
}
