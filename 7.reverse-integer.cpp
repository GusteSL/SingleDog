/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0) {
            if(result > __INT_MAX__/10 || (result == __INT_MAX__/10 && x%10 > 7)) return 0;
            if(result < (-1-__INT_MAX__)/10 || (result == (-1-__INT_MAX__)/10 && x%10 < -8)) return 0;
            result *= 10;
            result += x%10;
            x /= 10;
        }
        return result;
    }
};

