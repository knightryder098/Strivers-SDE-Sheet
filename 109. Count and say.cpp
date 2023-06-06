
//https://www.codingninjas.com/codestudio/problems/count-and-say_8230807?challengeSlug=striver-sde-challenge&leftPanelTab=0
//try to recreate the patter
//1 1
//2 21
//3 1211
//4 111221
//5 312211
//6 13112221
//7 1113213211
//8 31131211131221

#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.	
	string s="1";
	while(n-->1){
		int ct=1;
		string tmp="";
		for(int i=1;i<s.length();i++){
			if(s[i]!=s[i-1]){
				tmp+=to_string(ct);
				tmp+=s[i-1];
				ct=1;
			}
			else{
				ct++;
			}
		}
		tmp+=to_string(ct);
		tmp+=s.back();
		s=tmp;
	}

	return s;

}
