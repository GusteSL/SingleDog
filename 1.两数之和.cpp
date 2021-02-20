/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<pair<int, int>> nums_index(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            nums_index[i].first = nums[i];
            nums_index[i].second = i;
        }
        sort(nums_index.begin(), nums_index.end(), [](pair<int, int>& p1, pair<int, int>& p2){return p1.first < p2.first;});
        int first_i = 0, last_i = nums_index.size()-1;
        while(first_i < last_i) {
            if(nums_index[first_i].first + nums_index[last_i].first < target) {
                ++first_i;
            } else if(nums_index[first_i].first + nums_index[last_i].first > target) {
                --last_i;
            } else {
                result.push_back(nums_index[first_i].second);
                result.push_back(nums_index[last_i].second);
                break;
            }
        }
        return result;
    }
};
// @lc code=end

