/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int left = 0;
        int right = nums.size()-1;
        if(nums[left] < nums[right]) return nums[left];
        int middle;
        while(left < right) {
            middle = (left + right)*0.5;
            if(nums[left] < nums[middle]) {
                left = middle;
            } else {
                right = middle;
            }
        }
        return nums[left+1];
    }
};
// @lc code=end

