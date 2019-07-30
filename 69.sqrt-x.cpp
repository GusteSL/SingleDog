/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x < 4) return 1;
        int result = 0.5 * x;
        while(result > x / result) {
            result *= 0.5;
        }
        while(result <= x / result) {
            result ++;
        }
        result --;
        return result;
        // return sqrt(x);
    }
};

