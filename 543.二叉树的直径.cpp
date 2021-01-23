/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int deep;
        return diameterOfBinaryTree(root, deep);
    }
    int diameterOfBinaryTree(TreeNode* root, int& deep) {
        if(root == NULL) {
            deep = 0;
            return 0;
        }
        int left_deep, right_deep;
        int left_d = diameterOfBinaryTree(root->left, left_deep);
        int right_d = diameterOfBinaryTree(root->right, right_deep);
        deep = max(left_deep, right_deep) + 1;
        // cout << root->val << "\t" << left_deep << "\t" << right_deep << endl;
        return max(left_deep+right_deep, max(left_d, right_d));
    }
};
// @lc code=end

