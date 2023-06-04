/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (51.59%)
 * Likes:    11556
 * Dislikes: 625
 * Total Accepted:    1M
 * Total Submissions: 1.9M
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row
 * and column to 0's.
 * 
 * You must do it in place.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[0].length
 * 1 <= m, n <= 200
 * -2^31 <= matrix[i][j] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * A straightforward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Appraoch 1
        //brute force
        //time - O(N^3)
        //space - O(N*M)
        int n=matrix.size();
        int m=matrix[0].size();
        // vector<vector<int>>visited(n,vector<int>(m,1));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==0 and visited[i][j]){
        //             for(int k=0;k<n;k++){
        //                 if(matrix[k][j]!=0){
        //                     matrix[k][j]=visited[k][j]=0;
        //                 }
        //             }
        //             for(int k=0;k<m;k++){
        //                 if(matrix[i][k]!=0){
        //                     matrix[i][k]=visited[i][k]=0;
        //                 }
        //             }
        //         }
        //     }
        // }



        //Approach 2
        //using set, we can store the row  and column number where
        //0 is occuring
        //then update each row , column accordingly
        //time - O(N*M)
        //space -O(N+M)

        set<int>row,col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto r:row){
            for(int i=0;i<m;i++)matrix[r][i]=0;
        }
        for(auto c:col){
            for(int i=0;i<n;i++)matrix[i][c]=0;
        }

    }
};
// @lc code=end

