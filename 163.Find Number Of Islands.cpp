//https://www.codingninjas.com/studio/problems/find-number-of-islands_8230692?challengeSlug=striver-sde-challenge&leftPanelTab=1

void dfs(int i,int j,int n,int m,int **arr){
   int dr[]={-1,0,1,0,-1,1,-1,1};
   int dc[]={0,1,0,-1,1,1,-1,-1};
   arr[i][j]=0;
   for(int x=0;x<8;x++){
      int ni=i+dr[x];
      int nj=j+dc[x];
      if(ni>=0 and nj>=0 and ni<n and nj<m and arr[ni][nj]==1){
         dfs(ni,nj,n,m,arr);
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int ct=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(arr[i][j]==1){
            ct++;
            dfs(i,j,n,m,arr);
         }
      }
   }
   return ct;
}
