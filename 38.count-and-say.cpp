/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        string s = countAndSay(n-1);
        string result;
        int count = 1;
        for(int i = 0; i < s.size(); ++i) {
            if(i < s.size()-1) {
                if(s[i] == s[i+1]) {
                    count++;
                } else {
                    result += to_string(count);
                    result += s[i];
                    count = 1;
                }
            } else {
                result += to_string(count);
                result += s[i];
            }
        }
        return result;
    }
};

