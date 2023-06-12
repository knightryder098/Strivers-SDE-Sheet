// /https://www.codingninjas.com/codestudio/problems/single-element-in-a-sorted-array_8230826?challengeSlug=striver-sde-challenge&leftPanelTab=1

int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int ans=0;
	for(auto x:arr)ans^=x;
	return ans;
}
