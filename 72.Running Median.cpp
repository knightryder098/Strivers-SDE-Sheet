//https://www.codingninjas.com/studio/problems/running-median_8230682?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    for(int i=0;i<n;i++){
        int val=arr[i];

        if(maxheap.empty()||val<=maxheap.top()){
            maxheap.push(val);
        }
        else{
            minHeap.push(val);
        }

        if(maxheap.size()>minHeap.size()+1){
            minHeap.push(maxheap.top());
            maxheap.pop();
        }
        else if(maxheap.size()<minHeap.size()){
            maxheap.push(minHeap.top());
            minHeap.pop();
        }

        if(minHeap.size()<maxheap.size())cout<<maxheap.top()<<" ";
        else{
            cout<<(maxheap.top()+minHeap.top())/2<<" ";
        }
    }
}
