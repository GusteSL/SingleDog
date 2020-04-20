/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        vector<vector<size_t>> tmp_dp(s.size()+1, vector<size_t>(t.size()+1, 0));
        for(int i = 0; i < tmp_dp.size(); ++i) {
            tmp_dp[i][0] = 1;
        }
        for(int i = 0; i < s.size(); ++i) {
            for(int j = 0; j < t.size(); ++j) {
                if(s[i] == t[j]) {
                    tmp_dp[i+1][j+1] = tmp_dp[i][j+1] + tmp_dp[i][j];
                } else {
                    tmp_dp[i+1][j+1] = tmp_dp[i][j+1];
                }
            }
        }
        // for(int i = 0; i < tmp_dp.size(); ++i) {
        //     for(int j = 0; j < tmp_dp[i].size(); ++j) {
        //         cout << tmp_dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return tmp_dp.back().back();
    }
};
// @lc code=end

