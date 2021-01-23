/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() == 0) return -1;
        int index = -1;
        for(int i = 0; i < haystack.size(); ++i) {
            if(i+needle.size() > haystack.size()) {
                break;
            }
            bool same = true;
            for(int j = 0; j < needle.size() && same; ++j) {
                if(i+j >= haystack.size() || haystack[i+j] != needle[j]) {
                    same = false;
                }
            }
            if(same) {
                index = i;
                break;
            }
        }
        return index;
    }
};

