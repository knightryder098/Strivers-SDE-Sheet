
//https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_8230733?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
   vector<int>lola=arr;
   int i=0;
   while(i<n){
       if(lola[i]==lola[lola[i]-1]){
           i++;
       }
       else{
           swap(lola[i],lola[lola[i]-1]);
       }
   }
   for(int i=0;i<n;i++){
       if(lola[i]!=i+1){
           return {i+1,lola[i]};
       }
   }
   return {};
}
