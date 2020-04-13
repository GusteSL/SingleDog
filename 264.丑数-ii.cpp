/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> tmp_dp;
        int tmp_num[3] = {0, 0, 0};
        tmp_dp.push_back(1);
        for(int i = 1; i < n; ++i) {
            // cout << tmp_dp[tmp_num[0]]*2 << "\t" << tmp_dp[tmp_num[1]]*3 << "\t" << tmp_dp[tmp_num[2]]*5 << "\t" << tmp_dp.back() << "\n";
            if(tmp_dp.back() == tmp_dp[tmp_num[0]]*2) {++tmp_num[0];}
            if(tmp_dp.back() == tmp_dp[tmp_num[1]]*3) {++tmp_num[1];}
            if(tmp_dp.back() == tmp_dp[tmp_num[2]]*5) {++tmp_num[2];}
            if(tmp_dp[tmp_num[0]]*2 <= tmp_dp[tmp_num[1]]*3 && tmp_dp[tmp_num[0]]*2 <= tmp_dp[tmp_num[2]]*5) {
                tmp_dp.push_back(tmp_dp[tmp_num[0]]*2);
                ++tmp_num[0];
            } else if(tmp_dp[tmp_num[1]]*3 <= tmp_dp[tmp_num[0]]*2 && tmp_dp[tmp_num[1]]*3 <= tmp_dp[tmp_num[2]]*5) {
                tmp_dp.push_back(tmp_dp[tmp_num[1]]*3);
                ++tmp_num[1];
            } else {
                tmp_dp.push_back(tmp_dp[tmp_num[2]]*5);
                ++tmp_num[2];
            }
        }
        return tmp_dp[n-1];
    }
};
// @lc code=end

