//https://www.codingninjas.com/codestudio/problems/maximum-consecutive-ones_8230736?challengeSlug=striver-sde-challenge&leftPanelTab=0


int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int maxi = 0;
    int cnt0 = 0;
    
    for(int i = 0, j = 0; i < n; i++){
        // if we find 0 increment count
        if(arr[i] == 0){
            cnt0++;
        }


       // if we encounter that cnt0 is greater than k, increment the j counter
        while(cnt0 > k){
           if(arr[j] == 0){
               cnt0--;
           }
           j++;
        }

        maxi = max(maxi, i-j+1);
    }

    return maxi;
}

