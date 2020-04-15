/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        size_t start_i = 0;
        for(start_i = 0; start_i < s.size() && s[start_i] == '0'; ++start_i) {}
        if(start_i != 0) {
            return 0;
        }
        if(1 == s.size()) {
            return 1;
        }
        vector<size_t> tmp_dp(s.size(), 0);
        tmp_dp[start_i] = 1;
        if(s[start_i+1] == '0' && s[start_i] != '1' && s[start_i] != '2') {
            return 0;
        } else if(s[start_i+1] != '0' && (s[start_i] == '1' || (s[start_i] == '2' && s[start_i+1] < '7'))) {
            tmp_dp[start_i+1] = 2;
        } else {
            tmp_dp[start_i+1] = 1;
        }
        for(int i = start_i+2; i < s.size(); ++i) {
            if(s[i] == '0' && s[i-1] != '1' && s[i-1] != '2') {
                return 0;
            } else if(s[i] == '0') {
                tmp_dp[i] = tmp_dp[i-2];
            } else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')){
                tmp_dp[i] = tmp_dp[i-1] + tmp_dp[i-2];
            } else {
                tmp_dp[i] = tmp_dp[i-1];
            }
        }
        return tmp_dp.back();
    }
};
// @lc code=end

