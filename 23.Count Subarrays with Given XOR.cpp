// https://www.codingninjas.com/codestudio/problems/count-subarrays-with-given-xor_8230830?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    map<int,int>lola;
    int ct=0;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans^=arr[i];
        if(ans==x)ct++;
        if(lola.find(ans^x)!=lola.end()){
            ct+=lola[ans^x];
        }
        lola[ans]++;
    }
    return ct;
}
