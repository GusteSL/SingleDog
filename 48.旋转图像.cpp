/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp_val;
        int n = matrix.size();
        for(int i = 0; i < (n+1)/2; ++i) {
            for(int j = 0; j < n/2; ++j) {
                tmp_val = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = tmp_val;
            }
        }
    }
};
// @lc code=end

