//https://www.codingninjas.com/codestudio/problems/maximum-activities_8230800?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>>lola;
    int n=start.size();
    for(int i=0;i<n;i++)lola.push_back({start[i],finish[i]});
    sort(begin(lola),end(lola),[&](const pair<int,int>&a,const pair<int,int>&b){return a.second<b.second;});
    // for(auto x:lola)cout<<x.first<<" "<<x.second<<'\n';
    int ct=1;
    int end=lola[0].second;
    for(int i=1;i<n;i++){
        if(lola[i].first>=end){
            ct++;
            end=lola[i].second;
        }
    }
    return ct;
}
