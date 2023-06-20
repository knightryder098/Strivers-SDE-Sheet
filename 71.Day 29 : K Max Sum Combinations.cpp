//https://www.codingninjas.com/studio/problems/day-29-k-max-sum-combinations_8230768?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	if(n*n<k)return {};
	set<pair<int,int>>visited;
	priority_queue<pair<int,pair<int,int>>>pq;
	sort(begin(a),end(a),greater<int>());
	sort(begin(b),end(b),greater<int>());
	visited.insert({0,0});
	pq.push({a[0]+b[0],{0,0}});
	vector<int>ans;
	int ct=0;
	while(ct<k){
		int val=pq.top().first;
		int i=pq.top().second.first;
		int j=pq.top().second.second;
		pq.pop();
		ans.push_back(val);
		ct++;
		if(i+1<n and visited.find({i+1,j})==visited.end()){
			pq.push({a[i+1]+b[j],{i+1,j}});
			visited.insert({i+1,j});
		}

		if(j+1<n and visited.find({i,j+1})==visited.end()){
			pq.push({a[i]+b[j+1],{i,j+1}});
			visited.insert({i,j+1});
		}
	}
	return ans;
}
