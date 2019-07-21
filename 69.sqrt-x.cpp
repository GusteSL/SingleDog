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
        long long int result = x / 2;
        while(x < result * result) {
            result /= 2;
        }
        return result;
    }
};

