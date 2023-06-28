//https://www.codingninjas.com/studio/problems/next-smaller-element_8230814?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>tmp;
    tmp.push(arr[n-1]);
    vector<int>ans(n);
    ans[n-1]=-1;
    for(int i=n-2;i>=0;i--){
        int val=arr[i];
        while(tmp.size() and tmp.top()>=val)tmp.pop();
        if(tmp.size())ans[i]=tmp.top();
        else
        ans[i]=-1;
        tmp.push(val);
    }
    return ans;
}
