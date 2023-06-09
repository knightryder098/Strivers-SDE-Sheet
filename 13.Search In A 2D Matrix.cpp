// https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_8230773?challengeSlug=striver-sde-challenge&leftPanelTab=0


bool searchMatrix(vector<vector<int>>& mat, int target) {

    int n=mat.size();
    int m=mat[0].size();
    int j=m-1;
    int i=0;
    while(i<n and j>-1){
        if(mat[i][j]==target)return true;
        if(mat[i][j]<target)i++;
        else
        j--;
    } 
    return false;
}
