// https://www.codingninjas.com/codestudio/problems/n-queens_8230707?challengeSlug=striver-sde-challenge&leftPanelTab=1

bool isSafe(int row,int col,vector<vector<int>>&tmp){
    for(int i=0;i<tmp.size();i++){
        if(tmp[row][i]==1)return false;
        if(tmp[i][col]==1)return false;
    }

    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        if(tmp[i][j]==1)
            return false;

    for(int i=row,j=col;i>=0 && j<tmp.size();i--,j++)
        if(tmp[i][j]==1)
            return false;

    return true;
}

void helper(int row,vector<vector<int>>&tmp,vector<vector<int>>&ans){
    if(row==tmp.size()){
        vector<int>d;
        for(auto x:tmp){
            for(auto y:x)
                d.push_back(y);
        }
        ans.push_back(d);
        return ;
    }

    for(int col=0;col<tmp.size();col++){
        if(isSafe(row,col,tmp)){
            tmp[row][col]=1;
            helper(row+1,tmp,ans);
            tmp[row][col]=0;
        }
    }

}


vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    
    vector<vector<int>>lola;
    vector<vector<int>>tmp(n,vector<int>(n,0));
    helper(0,tmp,lola);
    return lola;
}
