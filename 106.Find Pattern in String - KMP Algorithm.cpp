//https://www.codingninjas.com/studio/problems/find-pattern-in-string-kmp-algorithm_8230819?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 

void lps(string p,vector<int>&temp,int pS)
{
    temp[0]=0;
    int i=0;
    int j=1;
    while(j<pS)
    {
        if(p[i]==p[j])
        {
            i++;
            temp[j]=i;
            j++;
        }
        else
        {
            if(i!=0)
            i=temp[i-1];
            else
            {
                temp[j]=0;
                j++;
            }
        }
    }
}
// find p in s
bool findPattern(string p, string s)
{
    // Write your code here.
    int pS=p.size();
    int sS=s.size();
    vector<int>temp(pS);
    lps(p,temp,pS); //create lps of pattern
    int i=0; //for pattern
    int j=0; //for string main
    while(j<sS)
    {
        if(s[j]==p[i])
        {
            i++;
            j++;
        }
        if(i==pS)
        return true;
        else if(j<sS && s[j]!=p[i])
        {
            if(i!=0)
            i=temp[i-1];
            else
            j++;
        }
    }
    return false;
}
