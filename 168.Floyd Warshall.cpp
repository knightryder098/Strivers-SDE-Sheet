//https://www.codingninjas.com/studio/problems/floyd-warshall_8230846?challengeSlug=striver-sde-challenge&leftPanelTab=0

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<long>>distance(n+1,vector<long>(n+1,1000000000));
    for(int i=1;i<=n;i++){
        distance[i][i]=0;
    }

    for(auto x:edges){
        int u=x[0],v=x[1],w=x[2];
        distance[u][v]=w;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(distance[i][k]!=1000000000 and distance[k][j]!=1000000000)
                distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }

    return distance[src][dest];
}

