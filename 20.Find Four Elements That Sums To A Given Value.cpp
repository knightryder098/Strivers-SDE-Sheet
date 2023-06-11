
//https://www.codingninjas.com/codestudio/problems/find-four-elements-that-sums-to-a-given-value_8230785?challengeSlug=striver-sde-challenge&leftPanelTab=1

//K sum -- can get result for any k
//     void kSum(vector<int>& nums, int target, int k, int start, vector<vector<int>>& res, vector<int>& curr, int sm){
//         if(k == 2){
//             int i = start, j = nums.size() - 1;
//             target -= sm;
//             while(i < j){
//                 if(nums[i] + nums[j] < target) i++;
//                 else if(nums[i] + nums[j] > target) j--;
//                 else{
//                     curr[curr.size() - 2] = nums[i];
//                     curr[curr.size() - 1] = nums[j];
//                     res.push_back(curr);
//                     while(i + 1 < j && nums[i] == nums[i + 1]) i++;
//                     i++;
//                     while(i < j - 1 && nums[j] == nums[j - 1]) j--;
//                     j--;
//                 }
//             }
//             return;
//         }
//         for(int i = start; i + k - 1 < nums.size(); i++){
//             curr[curr.size() - k] = nums[i];
//             kSum(nums, target, k - 1, i + 1, res, curr, sm + nums[i]);
//             while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
//         }
//     }
    
//     inline vector<vector<int>> kSumWrapper(vector<int>& nums, int target, int k){
//         vector<vector<int>> res;
//         sort(nums.begin(), nums.end());
//         vector<int> curr(k, 0);
//         kSum(nums, target, k, 0, res, curr, 0);
//         return res;
//     }
    
//     vector<vector<int>> Solution::fourSum(vector<int>& nums, int target) {
//         return kSumWrapper(nums, target, 4);
//     }



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
