/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string result, tmp_s;
        vector<int> len;
        tmp_s.resize(s.size()*2 + 1);
        len.resize(s.size()*2 + 1);
        tmp_s[0] = '#';
        for(int i = 0; i < s.size(); ++i) {
            tmp_s[2*i+1] = s[i];
            tmp_s[2*i+2] = '#';
        }
        int max_right_p = 0;
        int max_right_p_center = 0;
        int start = 0, max_len = 0;
        for(int i = 0; i < tmp_s.size(); ++i) {
            if( i < max_right_p ) {
                if( len[2*max_right_p_center-i] < max_right_p - i ) {
                    len[i] = len[2*max_right_p_center-i];
                } else {
                    for(int tmp_len = max_right_p-i; i-tmp_len>=0 && i+tmp_len<tmp_s.size(); ++tmp_len) {
                        if(tmp_s[i-tmp_len] == tmp_s[i+tmp_len]) {
                            len[i] = tmp_len+1;
                            if( i+tmp_len > max_right_p ) {
                                max_right_p = i+tmp_len;
                                max_right_p_center = i;
                            }
                        } else {
                            break;
                        }
                    }
                }
            } else {
                for(int tmp_len = 0; i-tmp_len>=0 && i+tmp_len<tmp_s.size(); ++tmp_len) {
                    if(tmp_s[i-tmp_len] == tmp_s[i+tmp_len]) {
                        len[i] = tmp_len+1;
                        if( i+tmp_len > max_right_p ) {
                            max_right_p = i+tmp_len;
                            max_right_p_center = i;
                        }
                    } else {
                        break;
                    }
                }
            }
            if(len[i]-1 > max_len) {
                max_len = len[i]-1;
                start = (i-len[i]+1) / 2;
            }
        }
        for(int i = 0; i < tmp_s.size(); ++i) {
            cout << tmp_s[i] << "\t" << len[i] << endl;
        }
        return s.substr(start, max_len);
    }
};
// @lc code=end

