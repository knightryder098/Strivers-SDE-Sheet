
//https://www.codingninjas.com/codestudio/problems/fractional-knapsack_8230767?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),[&](const pair<int,int>&a,const pair<int,int>&b){return (double)a.second/(double)a.first>(double)b.second/(double)b.first;});
    double profit=0;
    int i=0;
    while(w and i<items.size()){
        double weight=items[i].first;
        double val=items[i].second;
        if(weight<=w){
            profit+=val;
            w-=weight;
        }
        else{
            profit+=w*(val/weight);
            w=0;
        }
        i++;
    }
    return profit;
}
