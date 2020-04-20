/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        vector<vector<int>> tmp_dp(2, vector<int>(nums.size(), 0));
        tmp_dp[0][0] = nums[0];
        tmp_dp[1][0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i-1] == 0) {
                tmp_dp[0][i] = nums[i];
                tmp_dp[1][i] = nums[i];
            } else {
                tmp_dp[0][i] = max(nums[i], max(tmp_dp[0][i-1]*nums[i], tmp_dp[1][i-1]*nums[i]));
                tmp_dp[1][i] = min(nums[i], min(tmp_dp[0][i-1]*nums[i], tmp_dp[1][i-1]*nums[i]));
            }
            result = max(result, tmp_dp[0][i]);
        }
        return result;
    }
};
// @lc code=end

