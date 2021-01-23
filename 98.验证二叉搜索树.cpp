/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        int min_val, max_val;
        return isValidBST(root, min_val, max_val);
    }
    bool isValidBST(TreeNode* root, int& min_val, int& max_val) {
        if(root == NULL) {
            return true;
        }
        int left_min, left_max, right_min, right_max;
        if(root->left == NULL) {
            left_min = root->val;
            left_max = root->val;
        } else {
            if(isValidBST(root->left, left_min, left_max)) {
                if(left_max >= root->val) {
                    return false;
                }
            } else {
                return false;
            }
        }
        if(root->right == NULL) {
            right_min = root->val;
            right_max = root->val;
        } else {
            if(isValidBST(root->right, right_min, right_max)) {
                if(right_min <= root->val) {
                    return false;
                }
            } else {
                return false;
            }
        }
        min_val = left_min;
        max_val = right_max;
        return true;
    }
};
// @lc code=end

