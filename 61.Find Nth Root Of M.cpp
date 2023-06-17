//https://www.codingninjas.com/codestudio/problems/find-nth-root-of-m_8230799?challengeSlug=striver-sde-challenge&leftPanelTab=1

#define ll long long int
int NthRoot(int n, int m) {
  // Write your code here.
  int l=1,r=m;
  while(l<=r){
    ll mid=(l+r)/2;
    if(pow(mid,n)==m)return mid;
    else if(pow(mid,n)>m)r=mid-1;
    else
    l=mid+1;
  }
  return -1;

}
