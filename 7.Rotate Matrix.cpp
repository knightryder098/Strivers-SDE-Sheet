//https://www.codingninjas.com/codestudio/problems/rotate-matrix_8230774?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int top=0,bottom=n-1,left=0,right=m-1;
    while(top<bottom and left<right){
        int x=mat[top][left];
        for(int i=left+1;i<=right;i++){
            int tmp=mat[top][i];
            mat[top][i]=x;
            x=tmp;
        }
        top++;
        for(int i=top;i<=bottom;i++){
            int tmp=mat[i][right];
            mat[i][right]=x;
            x=tmp;
        }
        right--;
        for(int i=right;i>=left;i--){
            int tmp=mat[bottom][i];
            mat[bottom][i]=x;
            x=tmp;
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            int tmp=mat[i][left];
            mat[i][left]=x;
            x=tmp;
        }
        left++;
        mat[top-1][left-1]=x;
    }

}
