//https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_8230832?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),[&](const vector<int>&a,const vector<int>&b){return a[1]>b[1];});
    // for(auto x:jobs){
    //     cout<<x[1]<<" ";
    // }
    vector<int>slot(3001,-1);
    int profit=0;
    for(int i=0;i<jobs.size();i++){
        int j=jobs[i][0]-1;
        while(j>=0 and slot[j]==0){
            j--;
        }
        if(j>=0){
            profit+=jobs[i][1];
            slot[j]=0;
        }
    }
    return profit;
}
