//https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_8230794?challengeSlug=striver-sde-challenge&leftPanelTab=0
bool cycle(int src,vector<int>&path,vector<int>&visited,vector<vector<int>>&graph){
  visited[src]=1;
  path[src]=1;
  for(auto x:graph[src]){
    if(visited[x]==0){
      if(cycle(x,path,visited,graph))return 1;
    }
    else{
      if(path[x])return 1;
    }
  }
  path[src]=0;
  return 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>>graph(n+1,vector<int>());
  vector<int>visited(n+1,0),path(n+1,0);
  for(auto x:edges){
    graph[x.first].push_back(x.second);
  }

  for(int i=1;i<=n;i++){
    if(visited[i]==0){
      if(cycle(i,path,visited,graph))return 1;
    }
  }
  return 0;
}
