/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

