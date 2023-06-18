//https://www.codingninjas.com/codestudio/problems/chess-tournament_8230779?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
bool possible(int dis,int ct,vector<int>&pos){
	int player1=pos[0];
	for(int i=1;i<pos.size();i++){
		if(pos[i]-player1>=dis){
			ct--;
			player1=pos[i];
		}
		if(ct==1)return true;
	}
	return false;
}
int chessTournament(vector<int> pos , int n ,  int c){
	// Write your code here
	sort(begin(pos),end(pos));
	int low=1,high=pos[n-1]-pos[0];
	int ans=0;
	while(low<=high){
		int dis=low+(high-low)/2;
		if(possible(dis,c,pos)){
			ans=dis;
			low=dis+1;
		}
		else{
			high=dis-1;
		}
	}
	return ans;
}
