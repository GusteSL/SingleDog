/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size();
        int np = p.size();
        vector<vector<bool> > tmp_conut(ns+1, vector<bool>(np+1, false));
        tmp_conut[0][0] = true;
        for(int i = 0; i < np; ++i) {
            tmp_conut[0][i+1] = p[i] == '*' ? tmp_conut[0][i] : false;
        }
        for(int i = 0; i < ns; ++i) {
            for(int j = 0; j < np; ++j) {
                if(p[j] == '*') {
                    tmp_conut[i+1][j+1] = tmp_conut[i][j+1] || tmp_conut[i][j] || tmp_conut[i+1][j];
                } else {
                    tmp_conut[i+1][j+1] = p[j] == '?' ? tmp_conut[i][j] : tmp_conut[i][j] && s[i] == p[j];
                }
            }
        }
        return tmp_conut.back().back();
    }
};
// @lc code=end

