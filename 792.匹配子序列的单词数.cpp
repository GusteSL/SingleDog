/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int count = 0;
        vector<int> tmp_val(words.size(), 0);
        for(int i = 0; i < S.size(); ++i) {
            for(int j = 0; j < words.size(); ++j) {
                if(S[i] == words[j][tmp_val[j]]) {
                    ++tmp_val[j];
                    if(tmp_val[j] == words[j].size()) {
                        ++count;
                        words.erase(words.begin()+j);
                        tmp_val.erase(tmp_val.begin()+j);
                        --j;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

