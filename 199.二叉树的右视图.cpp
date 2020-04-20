/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightSideView(root, 1, result);
        // queue<TreeNode*> tmp_queue;
        // if(root == NULL) return result;
        // tmp_queue.push(root);
        // while(!tmp_queue.empty()) {
        //     size_t queue_size = tmp_queue.size();
        //     for(int i = 0; i < queue_size; ++i) {
        //         TreeNode* front_node = tmp_queue.front();
        //         tmp_queue.pop();
        //         if(front_node->left != NULL) tmp_queue.push(front_node->left);
        //         if(front_node->right != NULL) tmp_queue.push(front_node->right);
        //         if(i == queue_size-1) result.push_back(front_node->val);
        //     }
        // }
        return result;
    }
    void rightSideView(TreeNode* root, int deepth, vector<int>& result) {
        if(root == NULL) return;
        if(deepth > result.size()) result.push_back(root->val);
        rightSideView(root->right, deepth+1, result);
        rightSideView(root->left, deepth+1, result);
    }
};
// @lc code=end

