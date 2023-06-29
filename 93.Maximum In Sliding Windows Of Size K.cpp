
//https://www.codingninjas.com/studio/problems/maximum-in-sliding-windows-of-size-k_8230772?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h> 
class segTree{
    vector<int>seg;
    int n;
    public:
        segTree(int n){
            seg.resize(4*n);
            this->n=n;
        }

        void build(int ind,int l,int h,vector<int>&arr){
            if(l==h){
                seg[ind]=arr[l];
                return;
            }

            int mid=(l+h)/2;
            build(2*ind+1,l,mid,arr);
            build(2*ind+2,mid+1,h,arr);
            seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
        }

        int query(int ind,int low,int high,int l,int r){
            if(r<low || high<l)return INT_MIN;
            if(l<=low and high<=r)return seg[ind];

            int mid=(low+high)/2;
            int left=query(2*ind+1,low,mid,l,r);
            int right=query(2*ind+2,mid+1,high,l,r);
            return max(left,right);
        }

        int get(int left,int right){
            return query(0,0,n-1,left,right);
        }
};
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    int n=nums.size();
    segTree T(n);
    T.build(0,0,n-1,nums);
    vector<int>ans(n-k+1);
    for(int i=0;i<ans.size();i++){
        ans[i]=T.get(i,i+k-1);
    }
    return ans;
}
