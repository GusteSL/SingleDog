/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        vector<int> result = CameraCover(root);
        return min(result[1], result[2]);
    }
    // [0]: last don't have, and last isn't covered;
    // [1]: last don't have, but last is covered;
    // [2]: last have;
    vector<int> CameraCover(TreeNode* root) {
        if(root == NULL) {
            return vector<int>({0,0,1});
        }
        vector<int> left_num = CameraCover(root->left);
        vector<int> right_num = CameraCover(root->right);
        int case0 = left_num[1] + right_num[1];
        int case1 = min(min(left_num[1],left_num[2])+right_num[2], left_num[2]+min(right_num[1],right_num[2]));
        int case2 = ThisMin(left_num) + ThisMin(right_num) + 1;
        return vector<int>({case0, case1, case2});
    }
    int ThisMin(vector<int>& nums) {
        return min(nums[0],min(nums[1],nums[2]));
    }
};
// @lc code=end

