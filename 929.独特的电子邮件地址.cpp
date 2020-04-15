/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, bool> result;
        for(int i = 0; i < emails.size(); ++i) {
            bool meet_plus = false;
            int first_plus = 0, after_plus_len = 0;
            // cout << emails[i] << endl;
            for(int j = 0; j < emails[i].size(); ++j) {
                if(meet_plus) {
                    if(emails[i][j] == '@') {
                        emails[i].erase(first_plus, after_plus_len);
                        break;
                    } else {
                        ++after_plus_len;
                    }
                } else {
                    if(emails[i][j] == '.') {
                        emails[i].erase(j, 1);
                        --j;
                    } else if(emails[i][j] == '+') {
                        first_plus = j;
                        after_plus_len = 1;
                        meet_plus = true;
                    } else if(emails[i][j] == '@') {
                        break;
                    }
                }
            }
            // cout << emails[i] << endl;
            result[emails[i]] = true;
        }
        return result.size();
    }
};
// @lc code=end

