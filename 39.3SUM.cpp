// https://www.codingninjas.com/codestudio/problems/3sum_8230739?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(begin(arr),end(arr));
	set<vector<int>>ans;
	if(n<3)return {};
	for(int i=0;i<n-2;i++){
		if(arr[i]+arr[i+1]+arr[i+2]>K)break;
		if(arr[i]+arr[n-1]+arr[n-2]<K)continue;
		int l=i+1,k=n-1;
		while(l<k){
			int currsum=arr[i]+arr[l]+arr[k];
			if(currsum==K){
				ans.insert({arr[i],arr[l],arr[k]});
				l++;
				k--;
			}
			else if(currsum<K){
				l++;
			}
			else{
				k--;
			}
		}
	}
	return vector<vector<int>>(ans.begin(),ans.end());
}
