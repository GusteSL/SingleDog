/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        size_t start_i = 0, end_i = nums.size()-1;
        while(start_i <= end_i) {
            size_t middle_i = start_i + (end_i-start_i)*0.5;
            if(nums[start_i] == target || nums[middle_i] == target || nums[end_i] == target) {
                return true;
            }
            cout << nums[start_i] << "\t" << nums[middle_i] << "\t" << nums[end_i] << "\n";
            if(nums[start_i] == nums[middle_i]) {
                ++start_i;
            } else if(nums[start_i] < nums[middle_i]) {
                if(nums[start_i] < target && nums[middle_i] >= target) {
                    end_i = middle_i;
                } else {
                    start_i = middle_i;
                }
            } else {
                if(nums[middle_i] <= target && nums[end_i] > target) {
                    start_i = middle_i;
                } else {
                    end_i = middle_i;
                }
            }
        }
        return false;
    }
};
// @lc code=end

