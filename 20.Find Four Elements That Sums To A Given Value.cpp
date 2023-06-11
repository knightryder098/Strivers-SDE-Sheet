
//https://www.codingninjas.com/codestudio/problems/find-four-elements-that-sums-to-a-given-value_8230785?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

string fourSum(vector<int> nums, int target, int n) {
    // Write your code here.
    sort(nums.begin(),nums.end());
    if(n<4)return"No";
    for(int i=0;i<n-3;i++){
        if((long)nums[i]+(long)nums[i+1]+(long)nums[i+2]+(long)nums[i+3]>target)break;
        if((long)nums[i]+(long)nums[n-1]+(long)nums[n-2]+(long)nums[n-3]<target)continue;
        for(int j=i+1;j<n-2;j++){
            if((long)nums[i]+(long)nums[j]+(long)nums[j+1]+(long)nums[j+2]>target)break;
            if((long)nums[i]+(long)nums[j]+(long)nums[n-1]+(long)nums[n-2]<target)continue;
            int k=j+1,l=n-1;
            while(k<l){
                long sum=(long)nums[i]+(long)nums[j]+(long)nums[k]+(long)nums[l];
                if(sum==target)return "Yes";
                else if(sum<target)k++;
                else
                l--;
            }
        }
    }
    return "No";
}
