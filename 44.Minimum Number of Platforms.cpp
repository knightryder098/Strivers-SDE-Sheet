
// https://www.codingninjas.com/codestudio/problems/minimum-number-of-platforms_8230720?challengeSlug=striver-sde-challenge&leftPanelTab=0

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    vector<int>platform(2400,0);
    for(int i=0;i<n;i++){
        platform[at[i]]++;
        platform[dt[i]+1]--;
    }

    int ans=platform[0];
    for(int i=1;i<2400;i++){
        platform[i]+=platform[i-1];
        ans=max(ans,platform[i]);
    }
    return ans;
}
