//https://www.codingninjas.com/codestudio/problems/merge-intervals_8230700?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(begin(intervals),end(intervals),[&](const vector<int>&a,const vector<int>&b){return a[0]<b[0];});
    vector<vector<int>>ans;
    for(int i=0;i<intervals.size()-1;i++){
        if(intervals[i][1]>=intervals[i+1][0]){
            intervals[i+1][0]=intervals[i][0];
            intervals[i+1][1]=max(intervals[i][1],intervals[i+1][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    ans.push_back(intervals.back());
    return ans;
}
