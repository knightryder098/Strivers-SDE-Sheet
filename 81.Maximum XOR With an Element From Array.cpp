//https://www.codingninjas.com/studio/problems/maximum-xor-with-an-element-from-array_8230839?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
class Node{
	Node *child[2];
	public:
		bool contains(int bit){return child[bit]!=NULL;}
		void putNext(int bit,Node *newNode){child[bit]=newNode;}
		Node* getNext(int bit){return child[bit];}
};

class Trie{
	Node *root;
	public:
		Trie(){
			root=new Node();
		}

		void insert(int num){
			Node *tmp=root;
			for(int i=31;i>=0;i--){
				int bit=((num>>i)&1);
				if(!tmp->contains(bit)){
					tmp->putNext(bit,new Node());
				}
				tmp=tmp->getNext(bit);
			}
		}

		int maximumXor(int num){
			int ans=0;
			Node *tmp=root;
			for(int i=31;i>=0;i--){
				int bit=((num>>i)&1);
				if(tmp->contains(1-bit)){
					ans|=(1<<i);
					tmp=tmp->getNext(1-bit);
				}
				else{
					tmp=tmp->getNext(bit);
				}
			}
			return ans;
		}
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>>&q){
	//	Write your coode here.
	vector<pair<int,pair<int,int>>>lola;
	for(int i=0;i<q.size();i++){
		lola.push_back({q[i][1],{i,q[i][0]}});
	}
	sort(begin(lola),end(lola));
	int i=0;
	sort(arr.begin(),arr.end());
	Trie T;
	vector<int>ans(q.size(),0);
	for(auto x:lola){
		int ai=x.first;
		int ind=x.second.first;
		int xi=x.second.second;
		while(i<arr.size() and arr[i]<=ai){
			T.insert(arr[i]);
			i++;
		}
		if(i==0)ans[ind]=-1;
		else{
			ans[ind]=T.maximumXor(xi);
		}
	
	}
	return ans;

}
