/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        if(matrix[0].empty()) return 0;
        int max_i = 0;
        vector<vector<int>> tmp_dp(2, vector<int>(matrix[0].size(),0));
        for(int i = 0; i < matrix[0].size(); ++i) {
            if(matrix[0][i] == '1') {
                ++tmp_dp[0][i];
                max_i = max(max_i, tmp_dp[0][i]);
            }
        }
        for(int i = 1; i < matrix.size(); ++i) {
            int cur_i = i%2;
            int pre_i = (i+1)%2;
            tmp_dp[cur_i][0] = matrix[i][0] == '1' ? 1 : 0;
            max_i = max(max_i, tmp_dp[cur_i][0]);
            for(int j = 1; j < matrix[i].size(); ++j) {
                if(matrix[i][j] == '1') {
                    tmp_dp[cur_i][j] = 1 + min(tmp_dp[cur_i][j-1], min(tmp_dp[pre_i][j], tmp_dp[pre_i][j-1]));
                } else {
                    tmp_dp[cur_i][j] = 0;
                }
                max_i = max(max_i, tmp_dp[cur_i][j]);
            }
        }
        return max_i*max_i;
    }
};
// @lc code=end

