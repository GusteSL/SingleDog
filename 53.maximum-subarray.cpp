/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int segmentSum = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            segmentSum = nums[i] > segmentSum + nums[i] ? nums[i] : segmentSum + nums[i];
            result = result > segmentSum ? result : segmentSum;
        }
        return result;
    }
};

