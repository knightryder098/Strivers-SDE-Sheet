
//https://www.codingninjas.com/codestudio/problems/combination-sum-ii_8230820?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
void helper(int ind,int target,int n,vector<int>&ds,vector<int>&arr,vector<vector<int>>&ans){
	if(target==0){
		ans.push_back(ds);
		return;
	}

	for(int i=ind;i<n;i++){
		if(i!=ind and arr[i]==arr[i-1])continue;
		if(arr[i]>target)break;
		ds.push_back(arr[i]);
		helper(i+1,target-arr[i],n,ds,arr,ans);
		ds.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(begin(arr),end(arr));
	vector<vector<int>>ans;
	vector<int>ds;
	helper(0,target,n,ds,arr,ans);
	return ans;
}
