/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        if(grid[0].empty()) return 0;
        int result = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == '1') {
                    ++result;
                    tmpFunc(grid, i, j);
                }
            }
        }
        return result;
    }
    void tmpFunc(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size()) return;
        if(j < 0 || j >= grid[i].size()) return;
        if(grid[i][j] != '1') return;
        grid[i][j] = '2';
        tmpFunc(grid, i, j+1);
        tmpFunc(grid, i+1, j);
        tmpFunc(grid, i, j-1);
        tmpFunc(grid, i-1, j);
    }
};
// @lc code=end

