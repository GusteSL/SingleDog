/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        vector<int> tmp_dp[2];
        tmp_dp[0].resize(triangle.size());
        tmp_dp[1].resize(triangle.size());
        tmp_dp[0][0] = triangle[0][0];
        int min_total = tmp_dp[0][0];
        for(int i = 1; i < triangle.size(); ++i) {
            int tmp_i = i%2;
            int other_i = (i+1)%2;
            tmp_dp[tmp_i][0] = triangle[i][0] + tmp_dp[other_i][0];
            tmp_dp[tmp_i][triangle[i].size()-1] = triangle[i][triangle[i].size()-1] + tmp_dp[other_i][triangle[i-1].size()-1];
            min_total = min(tmp_dp[tmp_i][0], tmp_dp[tmp_i][triangle[i].size()-1]);
            for(int j = 1; j < triangle[i].size()-1; ++j) {
                tmp_dp[tmp_i][j] = triangle[i][j] + min(tmp_dp[other_i][j-1], tmp_dp[other_i][j]);
                min_total = min(min_total, tmp_dp[tmp_i][j]);
            }
            // for(int j = 0; j < triangle[i].size(); ++j) {
            //     cout << tmp_dp[tmp_i][j] << " ";
            // }
            // cout << endl;
        }
        return min_total;
    }
};
// @lc code=end

