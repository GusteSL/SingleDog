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
<<<<<<< HEAD
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
=======
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
>>>>>>> 8feeb9dbf65957abfdb3de81b9dd1148ad398c5d
    }
};
// @lc code=end

