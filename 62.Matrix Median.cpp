//https://www.codingninjas.com/codestudio/problems/matrix-median_8230735?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int countsmaller(vector<int>&arr,int mid){
    int i=0,j=arr.size()-1;
    while(i<=j){
        int m=(i+j)/2;
        if(arr[m]<=mid){
            i=m+1;
        }
        else
        j=m-1;
    }
    return i;
}
int getMedian(vector<vector<int>> &matrix)
{
//     // Write your code here.
//     vector<int>tmp;
//     for(auto x:matrix){
//         for(auto y:x)tmp.push_back(y);
//     }
//     sort(begin(tmp),end(tmp));
//     int n=tmp.size();
//     return tmp[n/2];


    int mini=INT_MAX,maxi=-1;
    int n=matrix.size(),m=matrix[0].size();
    for(int i=0;i<n;i++){
        mini=min(mini,matrix[i][0]);
        maxi=max(maxi,matrix[i][m-1]);
    }

    while(mini<=maxi){
        int mid=(mini+maxi)/2;
        int ct=0;
        for(int i=0;i<n;i++){
            ct+=countsmaller(matrix[i],mid);
        }

        if(ct<=(n*m)/2)mini=mid+1;
        else
        maxi=mid-1;
    }
    return mini;
}
