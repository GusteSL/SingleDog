/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        dfs(result, 0, n);
        return result;
    }
    void dfs(vector<int>& nums, int k, int n) {
        if(k > n) return;
        if(k != 0) nums.push_back(k);
        for(int i = 0; i < 10; ++i) {
            if(10*k+i>0) {
                dfs(nums, 10*k+i, n);
            }
        }
    }
};
// @lc code=end

