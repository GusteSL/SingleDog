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
        vector<TreeNode*> result;
        for(int i = 1; i <= n; ++i) {
            vector<bool> tmp_val(n, false);
            TreeNode *head = new TreeNode(i);
            tmp_val[i-1] = true;
            generateTree(head, tmp_val);
            tmp_val[i-1] = false;
            result.push_back(head);
        }
        return result;
    }
    void generateTree(TreeNode *head, vector<bool>& tmp_val) {
        for(int i = 1; i <= tmp_val.size(); ++i) {
            if(!tmp_val[i-1]) {
                insertTree(head, i);
                tmp_val[i-1] = true;
                generateTree(head, tmp_val);
                tmp_val[i-1] = false;
            }
        }
    }
    void insertTree(TreeNode *head, int n) {
        if(n < head->val) {
            if(head->left == NULL) {
                head->left = new TreeNode(n);
            } else {
                insertTree(head->left, n);
            }
        } else {
            if(head->right == NULL) {
                head->right = new TreeNode(n);
            } else {
                insertTree(head->right, n);
            }
        }
    }
};
// @lc code=end

