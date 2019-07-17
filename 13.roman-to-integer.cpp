/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        map<char, int> romanNum;
        romanNum['I'] = 1;
        romanNum['V'] = 5;
        romanNum['X'] = 10;
        romanNum['L'] = 50;
        romanNum['C'] = 100;
        romanNum['D'] = 500;
        romanNum['M'] = 1000;
        for(int i = 0; i < s.size(); ++i) {
            if(i+1 < s.size() && romanNum[s[i]] < romanNum[s[i+1]]) {
                result += romanNum[s[i+1]] - romanNum[s[i]];
                ++i;
            } else {
                result += romanNum[s[i]];
            }
        }
        return result;
    }
};

