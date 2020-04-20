/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n_s = s.size();
        int n_p = p.size();
        vector<vector<int> > tmp_val(n_s+1, vector<int>(n_p+1, false) );
        tmp_val[0][0] = true;
        for(int i = 1; i < n_p && p[i] == '*'; i+=2) {
            tmp_val[0][i+1] = true;
        }
        for(int i = 0; i < n_s; ++i) {
            for(int j = 0; j < n_p; ++j) {
                if(p[j] == '*') {
                    tmp_val[i+1][j+1] = tmp_val[i+1][j] || tmp_val[i+1][j-1] || ((s[i] == p[j-1] || p[j-1] == '.') && tmp_val[i][j+1]);
                } else if(p[j] == '.') {
                    tmp_val[i+1][j+1] = tmp_val[i][j];
                } else {
                    tmp_val[i+1][j+1] = s[i] == p[j] && tmp_val[i][j];
                }
            }
        }
        return tmp_val.back().back();
    }
};
// @lc code=end

