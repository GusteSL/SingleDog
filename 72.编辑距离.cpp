/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> tmp_count(n1+1, vector<int>(n2+1, 0));
        for(int i = 0; i < n1; ++i) {
            tmp_count[i+1][0] = tmp_count[i][0] + 1;
        }
        for(int i = 0; i < n2; ++i) {
            tmp_count[0][i+1] = tmp_count[0][i] + 1;
        }
        for(int i = 0; i < n1; ++i) {
            for(int j = 0; j < n2; ++j) {
                tmp_count[i+1][j+1] = min( tmp_count[i+1][j]+1,
                                      min( tmp_count[i][j+1]+1,
                                           word1[i] == word2[j] ? tmp_count[i][j] : tmp_count[i][j]+1));
            }
        }
        return tmp_count.back().back();
    }
};
// @lc code=end

