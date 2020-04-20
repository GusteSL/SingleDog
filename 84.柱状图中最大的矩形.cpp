/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return largestRectangleArea(heights, 0, heights.size());
    }
    int largestRectangleArea(vector<int>& heights, int left, int right) {
        if(left == right) {
            return 0;
        }
        int min_i = left, min_h = heights[left];
        for(int i = left; i < right; ++i) {
            if( heights[i] < min_h ) {
                min_h = heights[i];
                min_i = i;
            }
        }
        int leftlagestArea = largestRectangleArea(heights, left, min_i);
        int centerArea = min_h*(right-left);
        int rightlagestArea = largestRectangleArea(heights, min_i+1, right);
        return max(leftlagestArea, max(centerArea, rightlagestArea));
    }
};
// @lc code=end

