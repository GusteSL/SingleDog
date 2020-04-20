/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> tmp_val(n, vector<int>(m,0));
        for(int i = 0; i < m; ++i) {
            tmp_val[0][i] = matrix[0][i] == '1' ? 1 : 0;
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                tmp_val[i][j] = matrix[i][j] == '1' ? tmp_val[i-1][j] + 1 : 0;
            }
        }
        int largestArea = 0;
        for(int i = 0; i < n; ++i) {
            largestArea = max(largestArea, LargestArea(tmp_val[i], 0, tmp_val[i].size()));
        }
        return largestArea;
    }
    int LargestArea(vector<int>& list, int left, int right) {
        if(left == right) return 0;
        int min_i = left, min_h = list[left];
        for(int i = left; i < right; ++i) {
            if(list[i] < min_h) {
                min_i = i;
                min_h = list[i];
            }
        }
        int leftArea = LargestArea(list, left, min_i);
        int centerArea = min_h*(right-left);
        int rightArea = LargestArea(list, min_i+1, right);
        return max(leftArea, max(centerArea, rightArea));
    }
};
// @lc code=end

