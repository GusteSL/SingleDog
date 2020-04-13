/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        vector<int> tmp_dp(s.size()+1, 0);
        tmp_dp[0] = 1;
        for(int i = 0; i < s.size(); ++i) {
            for(int j = 0; j < wordDict.size() && tmp_dp[i+1] == 0; ++j) {
                if(i+1 < wordDict[j].size()) continue;
                tmp_dp[i+1] = tmp_dp[i+1-wordDict[j].size()] == 1 && s.substr(i+1-wordDict[j].size(), wordDict[j].size()) == wordDict[j];
            }
        }
        if(tmp_dp.back() == 0) return result;
        for(int i = 0; i < wordDict.size(); ++i) {
            if(s.size() < wordDict[i].size()) continue;
            if(s == wordDict[i]) {
                result.push_back(wordDict[i]);
                continue;
            }
            if(s.substr(0, wordDict[i].size()) == wordDict[i]) {
                vector<string> tmp_result = wordBreak(s.substr(wordDict[i].size()), wordDict);
                for(int j = 0; j < tmp_result.size(); ++j) {
                    result.push_back(wordDict[i]+" "+tmp_result[j]);
                }
            }
        }
        return result;
    }
};
// @lc code=end
