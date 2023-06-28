//https://www.codingninjas.com/studio/problems/rotting-oranges_8230701?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
        int ans = 0;
        queue<pair<int, int>> lola;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    lola.push({i, j});
            }
        }
        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1,0,1,0};
        while (!lola.empty())
        {    
            int sz = lola.size();
            bool flag=false;
            for (int i = 0; i < sz; i++)
            {
                int row = lola.front().first;
                int col = lola.front().second;
                lola.pop();
                for (int x = 0; x < 4; x++)
                {
                    int nr = row + dr[x];
                    int nc = col + dc[x];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == 0 || grid[nr][nc] == 2)continue;
                    
                    grid[nr][nc]=2;
                    flag=true;
                    lola.push({nr, nc});
                }
            }
            if(flag)ans++;
           
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return ans;
}
