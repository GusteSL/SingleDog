/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        SortAndDrop(nums1);
        SortAndDrop(nums2);
        vector<int> tmp(nums1);
        for(int i = 0; i < nums2.size(); ++i) {
            tmp.push_back(nums2[i]);
        }
        return SortAndDrop(tmp);
    }
    vector<int> SortAndDrop(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int n1, int n2){return n1<n2;});
        vector<int> tmp;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i-1]) {
                if(tmp.empty() || nums[i] != tmp.back()) {
                    tmp.push_back(nums[i]);
                }
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        return tmp;
    }
};
// @lc code=end

