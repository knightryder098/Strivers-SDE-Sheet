//https://www.codingninjas.com/codestudio/problems/min-heap_8230863?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
class minHP{
    vector<int>heap;
    void bubbleup(int ind){
        if(ind==0)return;
        int parent=(ind-1)/2;
        if(heap[parent]>heap[ind]){
            swap(heap[parent],heap[ind]);
            bubbleup(parent);
        }
    }

    void bubbledown(int ind){
        int l=2*ind+1;
        int r=2*ind+2;
        int root=ind;
        if(l<heap.size() and heap[l]<heap[root]){
            root=l;
        }
        if(r<heap.size() and heap[r]<heap[root]){
            root=r;
        }

        if(root!=ind){
            swap(heap[root],heap[ind]);
            bubbledown(root);
        }
    }

    public:
        void push(int val){
            heap.push_back(val);
            bubbleup(heap.size()-1);
        }

        void pop(){
            if(heap.size()==0)return ;
            swap(heap[0],heap.back());
            heap.pop_back();
            bubbledown(0);
        }
        int top(){
            return heap.size()==0?-1:heap[0];
        }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    minHP H;
    vector<int>ans;
    for(auto x:q){
        if(x[0]==0){
            H.push(x[1]);
        }
        else{
            ans.push_back(H.top());
            H.pop();
        }
    }
    return ans;
}
