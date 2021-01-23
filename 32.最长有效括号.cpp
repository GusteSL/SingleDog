/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        vector<int> len(s.size(), 0);
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == ')') {
                if(i-len[i-1]-1 >= 0 && s[i-len[i-1]-1] == '(') {
                    len[i] = len[i-1] + 2;
                }
                if(i-len[i] >= 0) {
                    len[i]+=len[i-len[i]];
                }
            }
            max_len = max(max_len, len[i]);
        }
        return max_len;
    }
};
// @lc code=end

