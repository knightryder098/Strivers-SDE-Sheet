#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int>ans;
	for(auto x:arr){
		ans.push(-x);
		if(ans.size()>K)ans.pop();
	}
	return -1*ans.top();
}
