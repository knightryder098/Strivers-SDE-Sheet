//https://www.codingninjas.com/codestudio/problems/longest-substring-without-repeating-characters_8230684?challengeSlug=striver-sde-challenge&leftPanelTab=0


#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int start=0;
    int n=input.size();
    int len=1;
    int ans=1;
    map<char,int>lola;
    lola[input[0]]=1;
    for(int i=1;i<n;i++){
        char ch=input[i];
        if(!lola[ch]){
            lola[ch]=1;
            len++;
        }
        else{
            ans=max(ans,len);
            while(lola[ch] and start<n){
                len--;
                lola[input[start++]]--;
            }
            lola[ch]=1;
            len++;
        }
    }
    ans=max(ans,len);
    return ans;
}
