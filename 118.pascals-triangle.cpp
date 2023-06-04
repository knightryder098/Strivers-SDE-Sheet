/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (71.08%)
 * Likes:    10103
 * Dislikes: 325
 * Total Accepted:    1.2M
 * Total Submissions: 1.7M
 * Testcase Example:  '5'
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 * 
 * 
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= numRows <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>prev(1,1);
        ans.push_back(prev);
        for(int i=1;i<numRows;i++){
            vector<int>tmp(i+1,1);
            for(int j=1;j<i;j++){
                tmp[j]=prev[j]+prev[j-1];
            }
            ans.push_back(tmp);
            prev=tmp;
        }
        return ans;
    }
};
// @lc code=end

