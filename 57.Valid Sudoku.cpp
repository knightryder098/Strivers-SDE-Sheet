
// https://www.codingninjas.com/codestudio/problems/valid-sudoku_8230704?challengeSlug=striver-sde-challenge&leftPanelTab=0

bool isSafe(int i,int j,int val,int matrix[9][9]){
    for(int x=0;x<9;x++){
        if(matrix[i][x]==val)return false;
        if(matrix[x][j]==val)return false;
    }
    i=i-i%3;
    j=j-j%3;
    for(int x=0;x<3;x++){
        for(int y=0;y<3;y++){
            if(matrix[i+x][j+y]==val)return false;
        }
    }
    return true;
}

bool solve(int i,int j,int matrix[9][9]){
    if(i==9)return true;
    if(j==9)return solve(i+1,0,matrix);
    if(matrix[i][j]!=0)return solve(i,j+1,matrix);
    for(int x=1;x<=9;x++){
        if(isSafe(i,j,x,matrix)){
            matrix[i][j]=x;
            if(solve(i,j+1,matrix))return true;
            matrix[i][j]=0;
        }
    }
    return false;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(0,0,matrix);
}
