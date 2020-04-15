/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        size_t n = dungeon.size();
        size_t m = dungeon[0].size();
        vector<vector<int>> tmp_dp(n, vector<int>(m, 0));
        tmp_dp.back().back() = 1-min(0, dungeon.back().back());
        for(int i = n-2; i >= 0; --i) {
            tmp_dp[i].back() = max(1, tmp_dp[i+1].back()-dungeon[i].back());
        }
        for(int i = m-2; i >= 0; --i) {
            tmp_dp.back()[i] = max(1, tmp_dp.back()[i+1]-dungeon.back()[i]);
        }
        for(int i = n-2; i >= 0; --i) {
            for(int j = m-2; j >= 0; --j) {
                tmp_dp[i][j] = min( max(1, tmp_dp[i+1][j]-dungeon[i][j]),
                                    max(1, tmp_dp[i][j+1]-dungeon[i][j]));
            }
        }

        // for(int i = 0; i < n; ++i) {
        //     for(int j = 0; j < m; ++j) {
        //         cout << tmp_dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return tmp_dp[0][0];
    }
};
// @lc code=end

