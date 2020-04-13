/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> tmp_dp(s.size()+1, 0);
        tmp_dp[0] = 1;
        for(size_t i = 0; i < s.size(); ++i) {
            // cout << s[i] << endl;
            for(int j = 0; j < wordDict.size() && tmp_dp[i+1] == 0; ++j) {
                if(i+1 < wordDict[j].size()) continue;
                tmp_dp[i+1] = tmp_dp[i+1-wordDict[j].size()] && s.substr(i+1-wordDict[j].size(), wordDict[j].size()) == wordDict[j];
                // cout << i+1-wordDict[j].size() << "\t" << wordDict[j].size() << endl;
                // cout << tmp_dp[i+1] << " = " << tmp_dp[i+1-wordDict[j].size()] << "\t" << s.substr(i+1-wordDict[j].size(), wordDict[j].size()) << "\t" << wordDict[j] << endl;
            }
        }
        return tmp_dp.back();
    }
};
// @lc code=end

