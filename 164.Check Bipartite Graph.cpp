//https://www.codingninjas.com/studio/problems/check-bipartite-graph_8230761?challengeSlug=striver-sde-challenge&leftPanelTab=0

bool dfs(int src,int cC,vector<int>&color,vector<int>&visited,vector<vector<int>>&graph){
	visited[src]=1;
	color[src]=cC;
	for(auto child:graph[src]){
		if(visited[child]==0){
			if(dfs(child,-cC,color,visited,graph)==false)return false;
		}
		else{
			if(color[child]==cC)return false;
		}
	}
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n=edges.size();
	vector<vector<int>>graph(n,vector<int>());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	vector<int>colors(n,0);
	vector<int>visited(n,0);
	for(int i=0;i<n;i++){
		if(visited[i]==0){
			if(dfs(i,1,colors,visited,graph)==false)return false;
		}
	}
	return true;
}


//dsu
// #include<bits/stdc++.h>
// class DSU{
// 	vector<int>parent,sizeT;
// 	public:
// 		DSU(int n){
// 			parent.resize(n,0);
// 			iota(begin(parent),end(parent),0);
// 			sizeT.resize(n,1);
// 		}

// 		int findR(int a){
// 			if(parent[a]==a)return a;
// 			return parent[a]=findR(parent[a]);
// 		}

// 		void joinab(int a, int b) {
// 			int pa = findR(a);
// 			int pb = findR(b);
// 			if (pa == pb)
// 			return;
// 			if (sizeT[pa] < sizeT[pb]){
// 				parent[pa]=pb;
// 				sizeT[pb]+=sizeT[pa];
// 			}
// 			else{
// 				parent[pb]=pa;
// 				sizeT[pa]+=sizeT[pb];
// 			}
// 		}

// 		bool isBipart(){
// 			set<int>lola(begin(parent),end(parent));
// 			return lola.size()==2;
// 		}
// };

// bool isGraphBirpatite(vector<vector<int>> &edges) {
// 	int n=edges.size();
// 	DSU gg(n);
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			if(gg.findR(i)==gg.findR(edges[i][j]))return false;
// 			gg.joinab(edges[i][0],edges[i][j]);
// 		}
// 	}
// 	// for(int i=0;i<n;i++)gg.findR(i);
// 	return true;
// }
