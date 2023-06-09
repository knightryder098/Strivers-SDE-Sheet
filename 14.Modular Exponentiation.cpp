
//https://www.codingninjas.com/codestudio/problems/modular-exponentiation_8230803?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

int modularExponentiation(long x, long n, long m) {
	// Write your code here.

	x%=m;
	if(x==0)return 0;
	long res=1;
	while(n){
		if(n&1){
			res=(res*x)%m;
		}
		x=(x*x)%m;
		n>>=1;
	}
	return res%m;
}
