/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> tmp_flag(numCourses, 0);
        vector<vector<int>> next_map(numCourses);
        
        for(int i = 0; i < prerequisites.size(); ++i) {
            next_map[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(!canFinish(tmp_flag, next_map, i)) {
                return false;
            }
        }
        return true;
    }
    bool canFinish(vector<int>& flag, vector<vector<int>>& next_map, int index) {
        if(flag[index] == 1) {
            return false;
        }
        if(flag[index] == -1) {
            return true;
        }
        flag[index] = 1;
        for(int i = 0; i < next_map[index].size(); ++i) {
            if(!canFinish(flag, next_map, next_map[index][i])) {
                return false;
            }
        }
        flag[index] = -1;
        return true;
    }
};
// @lc code=end

