// https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_8230708?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    
    int lastNum = INT_MIN;
    int count = 0, ans = 0;
    sort (arr.begin(),arr.end());
    for (int i=0;i<n;i++){
        if (arr[i]-1 == lastNum){
            count += 1;
            lastNum = arr[i];
        }
        else if (arr[i] != lastNum){
//        cout<<arr[i];
            count = 1;
            lastNum = arr[i];
        }
        if (count > ans){
            ans = count;
        }
    }
    return ans;
}
