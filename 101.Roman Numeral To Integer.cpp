//https://www.codingninjas.com/studio/problems/roman-numeral-to-integer_8230780?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                                                                         
int romanToInt(string s) {
    // Write your code here
    map<char,int>values={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };

    int num=0;
    int i=0;
    while(i<s.size()){
        int x=values[s[i]],y=0;
        if(i+1<s.size())
            y=values[s[i+1]];

        if(y>x){
            num=num+(y-x);
            i+=2;
        }
        else{
            num=num+(x);
        i++;
        }
    }
    return num;
}
