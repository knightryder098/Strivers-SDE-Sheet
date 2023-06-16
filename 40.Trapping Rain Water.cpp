
//https://www.codingninjas.com/codestudio/problems/trapping-rain-water_8230693?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    int tallest=0;
    for(int i=0;i<n;i++){
        if(arr[tallest]<arr[i]){
            tallest=i;
        }
    }

    long ans=0;
    long wall=0;
    for(int i=0;i<tallest;i++){
        if(arr[i]>wall){
            wall=arr[i];
        }
        else{
            ans+=wall-arr[i];
        }
    }

    wall=0;
    for(int i=n-1;i>tallest;i--){
        if(arr[i]>wall){
            wall=arr[i];
        }
        else{
            ans+=wall-arr[i];
        }
    }
    return ans;
}
