//https://www.codingninjas.com/studio/problems/online-stock-span_8230843?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int>ans;
    stack<int>lola;
    lola.push(-1);
    
    for(int i=0;i<price.size();i++){
        int val=price[i];
        while(lola.top()!=-1 and price[lola.top()]<=val)lola.pop();

        if(lola.top()==-1)ans.push_back(i+1);
        else{
            ans.push_back(i-lola.top());
        }
        lola.push(i);
    }
    return ans;
}
