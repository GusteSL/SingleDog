/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int _x = x;
        int b_x = 0;
        while(_x > 0) {
            if(b_x > __INT_MAX__/10 || (b_x == __INT_MAX__/10 && _x%10 > 7)) return false;
            b_x *= 10;
            b_x += _x%10;
            _x /= 10;
        }
        return b_x == x;
    }
};

