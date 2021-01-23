/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        Split(str, words, ' ');
        if(pattern.size() != words.size()) {
            return false;
        }
        map<char, string> c_s_hash;
        map<string, char> s_c_hash;
        for(int i = 0; i < pattern.size(); ++i) {
            if(c_s_hash.find(pattern[i]) != c_s_hash.end()) {
                if(c_s_hash[pattern[i]] != words[i]) {
                    return false;
                }
            } else {
                c_s_hash[pattern[i]] = words[i];
            }
            if(s_c_hash.find(words[i]) != s_c_hash.end()) {
                if(s_c_hash[words[i]] != pattern[i]) {
                    return false;
                }
            } else {
                s_c_hash[words[i]] = pattern[i];
            }
        }
        return true;
    }
    void Split(string& s, vector<string>& words, char c) {
        s += ' ';
        for(int i = 0, len = 0; i < s.size(); ++i) {
            // cout << s[i] << endl;
            if(s[i] == c) {
                if(len != 0) {
                    words.push_back(s.substr(i-len, len));
                    len = 0;
                    cout << words.back() << endl;
                }
            } else {
                ++len;
            }
        }
    }
};
// @lc code=end

