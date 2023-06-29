//https://www.codingninjas.com/studio/problems/dfs-traversal_8230690?challengeSlug=striver-sde-challenge&leftPanelTab=0
void dfs(int src,vector<int>&visited,vector<vector<int>>&graph,vector<int>&curr){
    curr.push_back(src);
    visited[src]=true;
    for(auto x:graph[src]){
        if(visited[x]==0)dfs(x,visited,graph,curr);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>graph(V,vector<int>());
    for(auto x:edges){
        int u=x[0],v=x[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int>visited(V,0);
    vector<vector<int>>ans;
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            vector<int>curr;
            dfs(i,visited,graph,curr);
            ans.push_back(curr);
        }
    }
    return ans;
}
