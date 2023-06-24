//https://www.codingninjas.com/studio/problems/bfs-in-graph_8230763?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
vector<int> BFS(int n, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>>graph(n,vector<int>());
    for(auto x:edges){
        graph[x.first].push_back(x.second);
        graph[x.second].push_back(x.first);
    }
    
    vector<int>ans;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            queue<int>q;
            q.push(i);
            while(q.size()){
                int par=q.front();
                q.pop();
                if(visited[par]==1)continue;
                visited[par]=1;
                ans.push_back(par);
                for(auto child:graph[par]){
                    if(visited[child]==0){
                        q.push(child);
                    }
                }
            }
        }
    }
    return ans;
}
