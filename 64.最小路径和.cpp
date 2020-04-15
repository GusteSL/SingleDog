/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long int>> tmp_count(m, vector<long int>(n, 0));
        tmp_count[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i) {
            tmp_count[i][0] = tmp_count[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < n; ++i) {
            tmp_count[0][i] = tmp_count[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                tmp_count[i][j] = min(tmp_count[i-1][j], tmp_count[i][j-1]) + grid[i][j];
            }
        }
        return tmp_count.back().back();
    }
};
// @lc code=end

