/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1.empty()) return s2 == s3;
        if(s2.empty()) return s1 == s3;
        // return (s1[0] == s3[0] && isInterleave(s1.substr(1), s2, s3.substr(1))) || (s2[0] == s3[0] && isInterleave(s1, s2.substr(1), s3.substr(1)));
        size_t s1_n = s1.size();
        size_t s2_n = s2.size();
        vector<vector<bool>> tmp_dp(s1_n+1, vector<bool>(s2_n+1, false));
        tmp_dp[0][0] = true;
        for(int i = 0; i < s1.size() && s1[i] == s3[i]; ++i) {
            tmp_dp[i+1][0] = true;
        }
        for(int i = 0; i < s2.size() && s2[i] == s3[i]; ++i) {
            tmp_dp[0][i+1] = true;
        }
        for(int i = 0; i < s1.size(); ++i) {
            for(int j = 0; j < s2.size(); ++j) {
                tmp_dp[i+1][j+1] = (s1[i] == s3[i+j+1] && tmp_dp[i][j+1]) || (s2[j] == s3[i+j+1] && tmp_dp[i+1][j]);
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

