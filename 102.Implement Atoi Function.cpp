//https://www.codingninjas.com/studio/problems/implement-atoi-function_8230776?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int i=0;
    int num=0;
    bool sign=true;
    while(i<str.size()){
        if(str[i]=='-')sign=false;
        else if(str[i]>='0' and str[i]<='9'){
            int dig=str[i]-'0';
            if(num>INT_MAX/10){
                num=INT_MAX;
                break;
            }
            else{
                num=num*10+dig;
            }
        }
        i++;
    }

    if(num==INT_MAX and sign==false)return INT_MIN;
    else if(sign==false)return -1*num;
    return num;
}
