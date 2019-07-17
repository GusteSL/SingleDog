/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        for(int i = 0; strs.size() > 0; ++i) {
            bool all_same = strs[0].size() > i;
            for(int j = 1; j < strs.size() && all_same; ++j) {
                all_same = strs[j].size() > i && strs[0][i] == strs[j][i];
            }
            if(all_same) {
                result.push_back(strs[0][i]);
            } else {
                break;
            }
        }
        return result;
    }
};

