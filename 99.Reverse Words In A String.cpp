//https://www.codingninjas.com/studio/problems/reverse-words-in-a-string_8230698?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include<bits/stdc++.h>
string reverseString(string &s){
	// Write your code here.
	stack<string>lola;
        string ss;
        for(auto ch:s){
            if(ch!=' ')ss+=ch;
            else{
                if(!ss.empty())
                    lola.push(ss);
                ss="";
            }
        }
        s.clear();
        if(!ss.empty())
            s+=ss+" ";
        while(!lola.empty()){
            string word=lola.top();
            s+=word+" ";
            lola.pop();
        }
        s.pop_back();
        return s;
}
