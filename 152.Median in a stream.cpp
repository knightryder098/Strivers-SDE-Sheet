//https://www.codingninjas.com/studio/problems/median-in-a-stream_8230765?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int>ans;
	priority_queue<int>maxHeap;
	priority_queue<int,vector<int>,greater<int>>minHeap;
	for(int i=0;i<n;i++){
		int val=arr[i];
		if(maxHeap.empty()||val<=maxHeap.top()){
			maxHeap.push(val);
		}
		else{
			minHeap.push(val);
		}

		int diff=maxHeap.size()-minHeap.size();
		if(diff<-1){
			int tmp=minHeap.top();
			minHeap.pop();
			maxHeap.push(tmp);
		}
		else if(diff>1){
			int tmp=maxHeap.top();
			maxHeap.pop();
			minHeap.push(tmp);
		}

		diff=maxHeap.size()-minHeap.size();
		if(diff==0){
			int a=maxHeap.top();
			int b=minHeap.top();
			int res=(a+b)/2;
			ans.push_back(res);
		}
		else if(diff==-1){
			int a=minHeap.top();
			ans.push_back(a);
		}
		else{
			ans.push_back(maxHeap.top());
		}
	}
	return ans;
}
