//https://www.codingninjas.com/codestudio/problems/return-subsets-sum-to-k_8230706?challengeSlug=striver-sde-challenge&leftPanelTab=1

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    // sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<(1<<n);i++){
        vector<int>curr;
        int sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum+=arr[j];
                curr.push_back(arr[j]);
            }
        }
        if(sum==k)ans.push_back(curr);
    }
    return ans;
}
