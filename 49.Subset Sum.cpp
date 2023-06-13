// https://www.codingninjas.com/codestudio/problems/subset-sum_8230859?challengeSlug=striver-sde-challenge&leftPanelTab=0


#include <bits/stdc++.h> 
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    int n=num.size();
    for(int i=0;i<(1<<n);i++){
        int tot=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))tot+=num[j];
        }
        ans.push_back(tot);
    }
    sort(begin(ans),end(ans));
    return ans;
}
