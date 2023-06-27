//https://www.codingninjas.com/studio/problems/flood-fill-algorithm_8230806?challengeSlug=striver-sde-challenge&leftPanelTab=0

void helper(int i,int j,int old,int newc,vector<vector<int>>&image){
    int dr[]={-1,0,1,0};
    int dc[]={0,-1,0,1};
    image[i][j]=newc;
    for(int x=0;x<4;x++){
        int ni=i+dr[x];
        int nj=j+dc[x];
        if(ni>=0 and nj>=0 and ni<image.size() and nj<image[0].size()){
            if(image[ni][nj]==old){
                helper(ni,nj,old,newc,image);
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    
    int old=image[x][y];
    if(old==newColor)return image;
    helper(x,y,old,newColor,image);
    return image; 
}
