
// https://www.codingninjas.com/codestudio/problems/count-inversions_8230680?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
long long mergeBothpart(long long *arr,int low,int mid,int high){
    int left=low,right=mid+1;
    long long count=0;
    vector<long long>tmp;
    while(left<=mid and right<=high){
        if(arr[left]<=arr[right]){
            tmp.push_back(arr[left++]);
        }
        else{
            tmp.push_back(arr[right++]);
            count+=(mid-left+1);
        }
    }
    while(left<=mid)tmp.push_back(arr[left++]);
    while(right<=high)tmp.push_back(arr[right++]);
    for(int i=low;i<=high;i++)arr[i]=tmp[i-low];
    return count;
}

long long mergeSort(long long *arr, int low,int high){
    int count=0;
    if(low<high){
        int mid=(low+high)/2;
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        count+=mergeBothpart(arr,low,mid,high);
    }
    return count;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr,0,n-1);
}
