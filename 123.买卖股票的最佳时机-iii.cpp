/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }
        vector<vector<vector<int>>> tmp_dp(3, vector<vector<int>>(prices.size(), vector<int>(2, 0)));
        for(int i = 0; i < tmp_dp.size(); ++i) {
            for(int j = 0; j < 1/*tmp_dp[i].size()*/; ++j) {
                tmp_dp[i][j][0] = 0;
                tmp_dp[i][j][1] = -prices[j];
            }
        }
        for(int i = 0; i < 1; ++i) {
            for(int j = 0; j < tmp_dp[i].size(); ++j) {
                tmp_dp[i][j][0] = 0;
                tmp_dp[i][j][1] = -prices[j];
            }
        }
        for(int i = 1; i < tmp_dp.size(); ++i) {
            for(int j = 1; j < tmp_dp[i].size(); ++j) {
                tmp_dp[i][j][0] = max(tmp_dp[i][j-1][0], tmp_dp[i][j-1][1] + prices[j]);
                tmp_dp[i][j][1] = max(tmp_dp[i][j-1][1], tmp_dp[i-1][j-1][0] - prices[j]);
            }
        }
        
        // for(int i = 0; i < tmp_dp.size(); ++i) {
        //     for(int j = 0; j < tmp_dp[i].size(); ++j) {
        //         cout << tmp_dp[i][j][0] << " ";
        //     }
        //     cout << endl;
        // }
        
        // for(int i = 0; i < tmp_dp.size(); ++i) {
        //     for(int j = 0; j < tmp_dp[i].size(); ++j) {
        //         cout << tmp_dp[i][j][1] << " ";
        //     }
        //     cout << endl;
        // }
        return tmp_dp.back().back()[0];
    }
};
// @lc code=end

