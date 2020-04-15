/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n < 1) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> stairs(n);
        stairs[0] = 1;
        stairs[1] = 2;
        for(int i = 2; i < n; ++i) {
            stairs[i] = stairs[i-1] + stairs[i-2];
        }
        return stairs.back();
    }
};

