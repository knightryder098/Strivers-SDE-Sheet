
//https://www.codingninjas.com/codestudio/problems/maximum-meetings_8230795?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int,int>>>lola;
    for(int i=0;i<start.size();i++)
      lola.push_back({i+1,{start[i], end[i]}});
    sort(lola.begin(),lola.end(),[&](const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>>&b){return a.second.second<b.second.second;});
    // for(auto x:lola)cout<<x.first<<" "<<x.second<<'\n';
    vector<int>ans;
    int endd=lola[0].second.second;
    ans.push_back(lola[0].first);
    for(int i=1;i<start.size();i++){
        if(lola[i].second.first>endd){
            ans.push_back(lola[i].first);
            endd=lola[i].second.second;
        }
    }
    return ans;
   
}
