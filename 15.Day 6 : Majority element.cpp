//https://www.codingninjas.com/codestudio/problems/day-6-majority-element_8230731?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int maxi=arr[0],ct=1;
	for(int i=1;i<n;i++){
		if(arr[i]!=maxi){
			ct--;
			if(ct==0){
				ct=1;
				maxi=arr[i];
			}
		}
		else{
			ct++;
		}
	}

	ct=0;
	for(int i=0;i<n;i++){
		if(arr[i]==maxi){
			ct++;
		}
	}
	return (ct>n/2)?maxi:-1;
}
