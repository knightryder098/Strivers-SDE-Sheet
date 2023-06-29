//https://www.codingninjas.com/studio/problems/bellman-ford_8230845?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>distance(n+1,1000000000);
    distance[src]=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0],v=edges[j][1],wt=edges[j][2];
            if(distance[u]!=1000000000 and distance[u]+wt<distance[v]){
                distance[v]=distance[u]+wt;
            }
        }
    }

    return distance[dest];
}
