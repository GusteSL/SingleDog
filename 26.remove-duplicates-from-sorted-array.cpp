/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int nums_count = 1;
        for(int i = 0; i < nums.size()-1; ++i) {
            if(nums[i] == nums[i+1]) {
                nums[i] = nums[nums.size()-1];
            } else {
                nums_count++;
            }
        }
        sort(nums.begin(), nums.end());
        // nums.erase(nums.begin()+nums_count, nums.end());
        return nums_count;
    }
};

