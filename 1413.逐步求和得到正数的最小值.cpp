/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        return Method1(nums);
    }
    int Method1(const vector<int>& nums) {
        if (nums.empty()) return 1;
        int min_val = 0;
        int sum = 0;
        for (const auto &num : nums) {
            sum += num;
            min_val = std::min(min_val, sum);
        }
        return 1-min_val;
    }
};
// @lc code=end

