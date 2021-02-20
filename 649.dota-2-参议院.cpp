/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        return Method2(senate);
    }
    string Method2(const string& senate) {
        if (senate.empty()) return "";
        queue<int> radiant, dire;
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            // std::cout << radiant.front() << " " << dire.front() << std::endl;
            if (radiant.front() < dire.front()) {
                radiant.push(radiant.front()+senate.size());
            } else {
                dire.push(dire.front()+senate.size());
            }
            radiant.pop();
            dire.pop();
        }
        if (!radiant.empty()) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
    string Method1(const string& senate) {
        if (senate.empty()) return "";
        vector<bool> forbidden_flag(senate.size(), false);
        int forbidden_count = 0;
        int i = 0;
        char last_c = 'N';
        do {
            forbidden_count = 0;
            last_c = senate[i];
            // std::cout << senate[i] << ":";
            if (forbidden_flag[i] == false) {
                // std::cout << i << "|";
                for (int j = 1; j < senate.size() && forbidden_count == 0; ++j) {
                    int new_i = (i+j)%senate.size();
                    // std::cout << new_i << " ";
                    if (forbidden_flag[new_i] == false && senate[i] != senate[new_i]) {
                        forbidden_flag[new_i] = true;
                        ++forbidden_count;
                    }
                }
                // std::cout << "|" << forbidden_count;
            } else {
                ++forbidden_count;
            }
            std::cout << std::endl;
            ++i;
            i %= senate.size();
        } while (forbidden_count != 0);
        if (last_c == 'R') {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};
// @lc code=end

