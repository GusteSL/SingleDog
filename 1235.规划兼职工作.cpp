  /*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> node;
        for(int i = 0; i < startTime.size(); ++i) {
            node[startTime[i]] = 0;
        }
        for(int i = 0; i < endTime.size(); ++i) {
            node[endTime[i]] = profit[i];
        }
        int result = node.begin()->second;
        for(auto itr = node.begin(); itr != node.end(); ++itr) {
            itr->second = result;
            for(int j = 0; j < endTime.size(); ++j) {
                if(endTime[j] == itr->first) {
                    itr->second = max(itr->second, node[startTime[j]]+profit[j]);
                }
            }
            result = itr->second;
            // cout << itr->first << "\t" << itr->second << endl;
        }
        return result;
    }
};
// @lc code=end

