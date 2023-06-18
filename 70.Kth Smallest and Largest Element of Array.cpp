//https://www.codingninjas.com/codestudio/problems/kth-smallest-and-largest-element-of-array_8230829?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	// sort(begin(arr),end(arr));
	// return {arr[k-1],arr[n-k]};

	priority_queue<long>maxHeap,minHeap;
	for(auto x:arr){
		maxHeap.push(x);
		minHeap.push(-x);
		if(minHeap.size()>k)minHeap.pop();
		if(maxHeap.size()>k)maxHeap.pop();
	}

	return {maxHeap.top(),-1*minHeap.top()};
}
