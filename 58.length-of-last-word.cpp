/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for(int i = s.size()-1; i >= 0; --i) {
            if(length == 0 && s[i] == ' ') continue;
            else if(s[i] == ' ') break;
            else length++;
        }
        return length;
    }
};

