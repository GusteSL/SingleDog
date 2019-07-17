/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<pair<int, int> > _nums(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            _nums[i].first = nums[i];
            _nums[i].second = i;
        }
        sort(_nums.begin(), _nums.end(), compare);
        int first, last;
        first = 0;
        last = nums.size()-1;
        while(first < last) {
            if(_nums[first].first + _nums[last].first < target) {
                first ++;
            } else if(_nums[first].first + _nums[last].first > target) {
                last --;
            } else {
                result.push_back(_nums[first].second);
                result.push_back(_nums[last].second);
                if(result[0] > result[1]) {
                    swap(result[0], result[1]);
                }
                break;
            }
        }
        return result;
    }
    static bool compare(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first < p2.first;
    }
};

