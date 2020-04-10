/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int max_profit = 0;
        int min_price = prices[0];
        for(int i = 1; i < prices.size(); ++i) {
            min_price = min_price < prices[i] ? min_price : prices[i];
            max_profit = max(max_profit, prices[i]-min_price);
        }
        return max_profit;
    }
};
// @lc code=end

