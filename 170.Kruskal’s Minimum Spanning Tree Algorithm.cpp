
//https://www.codingninjas.com/studio/problems/kruskal-s-minimum-spanning-tree-algorithm_8230804?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
class DSU{
	vector<int>parent,sizeT;
	public:
		DSU(int n){
			parent.resize(n,0);
			iota(begin(parent),end(parent),0);
			sizeT.resize(n,1);
		}

		int findR(int a){
			if(a==parent[a])return a;
			return parent[a]=findR(parent[a]);
		}

		void joinab(int a,int b){
			a=findR(a);
			b=findR(b);
			if(a==b)return;
			if(sizeT[a]<sizeT[b]){
				parent[a]=b;
				sizeT[b]+=sizeT[a];
			}
			else{
				parent[b]=a;
				sizeT[a]+=sizeT[b];
			}
		}
};
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.

	sort(begin(graph),end(graph),[&](const vector<int>&a,const vector<int>&b){return a[2]<b[2];});
	DSU dj(n);
	int cost=0;
	for(int i=0;i<m;i++){
		int u=graph[i][0]-1;
		int v=graph[i][1]-1;
		int wt=graph[i][2];
		int pu=dj.findR(u);
		int pv=dj.findR(v);
		if(pu!=pv){
			cost+=wt;
			dj.joinab(u,v);
		}
	}
	return cost;
}
