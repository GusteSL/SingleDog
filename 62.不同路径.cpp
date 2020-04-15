/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > tmp_count(m, vector<int>(n, 0) );
        for(int i = 0; i < m; ++i) {
            tmp_count[i][0] = 1;
        }
        for(int i = 0; i < n; ++i) {
            tmp_count[0][i] = 1;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                tmp_count[i][j] = tmp_count[i-1][j] + tmp_count[i][j-1];
            }
        }
        return tmp_count.back().back();
    }
};
// @lc code=end

