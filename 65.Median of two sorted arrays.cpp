// https://www.codingninjas.com/studio/problems/median-of-two-sorted-arrays_8230788?challengeSlug=striver-sde-challenge&leftPanelTab=0

int getK(vector<int>&a,int i1,int j1,vector<int>&b,int i2,int j2,int k){
	if(j1<i1)return b[i2+k];
	if(j2<i2)return a[i1+k];
	if(k==0)return min(a[i1],b[i2]);

	int len1=j1-i1+1;
	int len2=j2-i2+1;
	int mid1=(k*len1)/(len1+len2);
	int mid2=k-mid1-1;
	mid1+=i1;
	mid2+=i2;
	if(a[mid1]<b[mid2]){
		k=k-(mid1-i1+1);
		j2=mid2;
		i1=mid1+1;
	}
	else{
		k=k-(mid2-i2+1);
		j1=mid1;
		i2=mid2+1;
	}
	return getK(a,i1,j1,b,i2,j2,k);
}


double median(vector<int>& a, vector<int>& b) {
	// Write your code here.

	int n=a.size();
	int m=b.size();
	int tot=(m+n);
	if(tot%2==0){
		int aa=getK(a,0,n-1,b,0,m-1,tot/2);
		int bb=getK(a,0,n-1,b,0,m-1,(tot-1)/2);
		return (double)(aa+bb)/2.0;
	}
	else{
		return getK(a,0,n-1,b,0,m-1,tot/2);
	}
}
