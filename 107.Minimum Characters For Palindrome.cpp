//https://www.codingninjas.com/studio/problems/minimum-characters-for-palindrome_8230737?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include<bits/stdc++.h>

int minCharsforPalindrome(string str) 
{
    // Write your code here.
    int i=0,j=str.size()-1;
    int x=j,ans=0;
    while(i<j)
    {
        if(str[i]==str[j])
        {
			i++;
            j--;
        }
        else
        {
            ans++;
            i=0;
            j=--x;
        }
    }
    return ans;
}
	
