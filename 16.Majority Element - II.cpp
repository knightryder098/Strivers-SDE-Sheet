//https://www.codingninjas.com/codestudio/problems/majority-element-ii_8230738?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int cnt1=0,cnt2=0,ans1=INT_MIN,ans2=INT_MIN;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(cnt1==0 and arr[i]!=ans2){
            cnt1++;
            ans1=arr[i];
        }
        else if(cnt2==0 and arr[i]!=ans1){
            cnt2++;
            ans2=arr[i];
        }
        else if(ans1==arr[i])cnt1++;
        else if(ans2==arr[i])cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    vector<int>ans;
    cnt2=0;
    cnt1=0;
    for(auto x:arr){
        if(x==ans1)cnt1++;
        if(x==ans2)cnt2++;
    }

    if(cnt1>n/3)ans.push_back(ans1);
    if(cnt2>n/3)ans.push_back(ans2);
    
    return ans;

}
