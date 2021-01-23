/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end(), [](int n1, int n2){return n1 < n2;});
        return nums[0.5*nums.size()];
    }
};
// @lc code=end

