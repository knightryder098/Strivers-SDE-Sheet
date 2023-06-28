//https://www.codingninjas.com/studio/problems/largest-rectangle-in-a-histogram_8230792?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
 int largestRectangle(vector < int > & heights) {
   // Write your code here.


        int n=heights.size();
        vector<int>leftsmaller(n),rightsmaller(n);
        stack<int>lola;
        leftsmaller[0]=0;
        lola.push(0);
        for(int i=1;i<n;i++){
            while(!lola.empty() and heights[lola.top()]>=heights[i])lola.pop();
            if(lola.empty())leftsmaller[i]=0;
            else
            leftsmaller[i]=lola.top()+1;
            lola.push(i);
        }

        rightsmaller[n-1]=n-1;
        while(!lola.empty())lola.pop();
        lola.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!lola.empty() and heights[lola.top()]>=heights[i])lola.pop();
            if(lola.empty())rightsmaller[i]=n-1;
            else
            rightsmaller[i]=lola.top()-1;
            lola.push(i);
        }
       int ans=0;
       for(int i=0;i<n;i++){
           ans=max((rightsmaller[i]-leftsmaller[i]+1)*heights[i],ans);
       }
       return ans;
 }
