
// https://www.codingninjas.com/codestudio/problems/reverse-pairs_8230825?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
int merge(vector<int>&arr,int low,int mid,int high){
	
	int count=0;
	int l=low,r=mid+1;
	for(int i=low;i<=mid;i++){
		while(r<=high and arr[i]>2*(long)arr[r])r++;
		count+=r-mid-1;
	}
	
	r=mid+1;
	vector<int>tmp;
	while(l<=mid and r<=high){
		if(arr[l]<=arr[r]){
			tmp.push_back(arr[l++]);
		}
		else{
			tmp.push_back(arr[r++]);
		}
	}
	while(l<=mid)tmp.push_back(arr[l++]);
	while(r<=high)tmp.push_back(arr[r++]);
	for(int i=low;i<=high;i++)arr[i]=tmp[i-low];
	return count;
} 

int mergeSort(vector<int>&arr,int low,int high){
	int count=0;
	if(low<high){
		int mid=(low+high)/2;
		count+=mergeSort(arr,low,mid);
		count+=mergeSort(arr,mid+1,high);
		count+=merge(arr,low,mid,high);
	}

	return count;
	
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
	return mergeSort(arr,0,n-1);
}
