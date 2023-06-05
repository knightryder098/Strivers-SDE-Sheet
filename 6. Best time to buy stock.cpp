#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int profit=0;
    int mini=prices[0];
    for(int i=1;i<prices.size();i++){
        profit=max(profit,prices[i]-mini);
        mini=min(mini,prices[i]);
    }
    return profit;
}
