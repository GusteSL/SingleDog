/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<unordered_map<string, int>> word_barrel(26);
        for(int i = 0; i < words.size(); ++i) {
            ++word_barrel[words[i][0]-'a'][words[i]];
        }
        // for(int j = 0; j < word_barrel.size(); ++j) {
        //     for(auto word:word_barrel[j]) {
        //         cout << word.first << ":" << word.second << endl;
        //     }
        // }
        int result = 0;
        for(int i = 0; i < S.size(); ++i) {
            int char_id = S[i] - 'a';
            if(word_barrel[char_id].empty()) {
                continue;
            }
            vector<unordered_map<string, int>> tmp_barrel(26);
            for(auto itr = word_barrel[char_id].begin(); itr != word_barrel[char_id].end();) {
                if(S[i] == itr->first[0]) {
                    string new_str = itr->first.substr(1);
                    if(new_str.empty()) {
                        result += itr->second;
                        itr = word_barrel[char_id].erase(itr);
                    } else {
                        tmp_barrel[new_str[0]-'a'][new_str] = itr->second;
                        itr = word_barrel[char_id].erase(itr);
                    }
                } else {
                    ++itr;
                }
            }
            for(int j = 0; j < word_barrel.size(); ++j) {
                if(tmp_barrel[j].empty()) {
                    continue;
                }
                for(auto word:tmp_barrel[j]) {
                    // cout << word.first << ":" << word.second << endl;
                    word_barrel[j][word.first] += word.second;
                }
            }
            // cout << "---------\n";
        }
        return result;
    }
};
// @lc code=end

