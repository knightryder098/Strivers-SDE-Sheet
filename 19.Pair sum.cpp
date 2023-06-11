//https://www.codingninjas.com/codestudio/problems/pair-sum_8230699?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   sort(begin(arr),end(arr));
   map<int,int>lola;
   vector<vector<int>>ans;
   for(int i=0;i<arr.size();i++){
      int tmp=s-arr[i];
      if(lola.find(tmp)==lola.end()){
         lola[arr[i]]++;
      }
      else{
         int ct=lola[tmp];
         while(ct--){
            ans.push_back({tmp,arr[i]});
         }
         lola[arr[i]]++;
      }
   }
   // for(auto x:lola)cout<<x.first<<" ";
   sort(begin(ans),end(ans));
   return ans;

}
