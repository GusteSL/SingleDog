/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();
        return generateTrees(1, n+1);
    }
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> result;
        for(int i = start; i < end; ++i) {
            vector<TreeNode*> left_result = generateTrees(start, i);
            vector<TreeNode*> right_result = generateTrees(i+1, end);
            for(int left_i = 0; left_i < left_result.size(); ++left_i) {
                for(int right_i = 0; right_i < right_result.size(); ++right_i) {
                    TreeNode* head = new TreeNode(i);
                    head->left = left_result[left_i];
                    head->right = right_result[right_i];
                    result.push_back(head);
                }
            }
        }
        if(result.empty()) {
            result.push_back(NULL);
        }
        return result;
    }
};
// @lc code=end

