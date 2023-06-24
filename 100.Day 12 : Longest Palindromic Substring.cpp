//https://www.codingninjas.com/studio/problems/day-12-longest-palindromic-substring_8230702?challengeSlug=striver-sde-challenge&leftPanelTab=0
void helper(string &s, int l,int r,string &ans){

    while(l>=0 and r<s.size()){
        if(s[l]==s[r]){
            l--;
            r++;
        }
        else
        break;
    }
    if(r-l-1>ans.size()){
        ans=s.substr(l+1,r-l-1);
    }
}
string longestPalinSubstring(string str)
{
    // Write your code here.
    int n=str.size();
    string ans="";
    for(int i=0;i<n;i++){
        helper(str,i,i,ans);
        helper(str,i,i+1,ans);
    }
    return ans;
}
