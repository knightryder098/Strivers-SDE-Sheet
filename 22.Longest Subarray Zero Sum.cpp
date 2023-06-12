// https://www.codingninjas.com/codestudio/problems/longest-subarray-zero-sum_8230747?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  for(int i=1;i<arr.size();i++){
    arr[i]+=arr[i-1];
  }
  map<int,int>lola;
  int ans=0;
  for(int i=0;i<arr.size();i++){
    if(arr[i]==0)ans=i+1;
    else if(lola.find(arr[i])!=lola.end()){
      ans=max(ans,i-lola[arr[i]]);
    }
    else
      lola[arr[i]]=i;
  }
  return ans;

}
