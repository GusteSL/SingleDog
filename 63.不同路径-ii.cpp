/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long int>> tmp_count(m, vector<long int>(n,0));
        for(int i = 0; i < m && obstacleGrid[i][0] != 1; ++i) {
            tmp_count[i][0] = 1;
        }
        for(int i = 0; i < n && obstacleGrid[0][i] != 1; ++i) {
            tmp_count[0][i] = 1;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                tmp_count[i][j] = obstacleGrid[i][j] == 1 ? 0 : tmp_count[i-1][j] + tmp_count[i][j-1];
                cout << tmp_count[i][j] << " ";
            }
            cout << endl;
        }
        return tmp_count.back().back();
    }
};
// @lc code=end

