/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) return 0;
        auto TmpSort = [](const vector<int>& e1, const vector<int>& e2){
            if(e1[0] == e2[0]) return e1[1] > e2[1];
            return e1[0] < e2[0];
        };
        sort(envelopes.begin(), envelopes.end(), TmpSort);
        vector<int> tmp_dp(envelopes.size(), 0);
        vector<int> len_min;
        len_min.push_back(envelopes[0][1]);
        tmp_dp[0] = 1;
        for(int i = 1; i < envelopes.size(); ++i) {
            if(envelopes[i][1] > len_min.back()) {
                len_min.push_back(envelopes[i][1]);
                continue;
            }
            for(int j = 0; j < len_min.size(); ++j) {
                if(envelopes[i][1] <= len_min[j]) {
                    len_min[j] = envelopes[i][1];
                    break;
                }
            }
        }
        return len_min.size();
    }
};
// @lc code=end

