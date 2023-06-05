#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
      int l=0,mid=0,r=n-1;
      while(mid<=r){
         if(arr[mid]==0){
            swap(arr[mid++],arr[l++]);
         }
         else if(arr[mid]==1){
            mid++;
         }
         else{
            swap(arr[mid], arr[r--]);
         }
    }
}
