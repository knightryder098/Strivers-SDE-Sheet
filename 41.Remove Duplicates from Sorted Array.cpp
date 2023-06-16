
//https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-sorted-array_8230811?challengeSlug=striver-sde-challenge&leftPanelTab=0

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int ct=0;
	for(int i=1;i<n;i++){
		if(arr[i]==arr[i-1])ct++;
		else
		arr[i-ct]=arr[i];
	}
	return n-ct;
}
