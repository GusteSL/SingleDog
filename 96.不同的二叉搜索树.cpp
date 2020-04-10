/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 0;
        vector<int> tmp_dp(n+1);
        tmp_dp[0] = 1;
        tmp_dp[1] = 1;
        for(int i = 2; i < tmp_dp.size(); ++i) {
            tmp_dp[i] = 0;
            for(int j = 0; j < i; ++j) {
                tmp_dp[i] += tmp_dp[j]*tmp_dp[i-j-1];
            }
        }
        return tmp_dp.back();
    }
};
// @lc code=end

