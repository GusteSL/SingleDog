  /*
 * @lc app=leetcode.cn id=1235 lang=cpp
 *
 * [1235] 规划兼职工作
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // Sort(startTime, endTime, profit);
        size_t job_num = startTime.size();
        vector<int> job_index(job_num+1, 0);
        iota(job_index.begin(), job_index.end(), 0);
        sort(job_index.begin()+1, job_index.end(), [&](int& n1, int& n2){return endTime[n1-1] < endTime[n2-1];});
        // for(int i = 1; i < job_index.size(); ++i) {
        //     cout << endTime[job_index[i]-1] << endl;
        // }
        vector<int> pre_job(job_num+1);
        for(int i = 1; i <= job_num; ++i) {
            for(int j = i-1; j > 0; --j) {
                if(endTime[job_index[j]-1] <= startTime[job_index[i]-1]) {
                    pre_job[i] = j;
                    break;
                }
            }
        }
        vector<int> tmp_dp(job_num+1, 0);
        for(int i = 1; i <= job_num; ++i) {
            // cout << i << "\t" << tmp_dp[i-1] << "\t" << pre_job[i] << "\t" << tmp_dp[pre_job[i]] << "\t" << profit[job_index[i]-1] << endl;
            tmp_dp[i] = max(tmp_dp[i-1], tmp_dp[pre_job[i]]+profit[job_index[i]-1]);
        }
        // for(int i = 1; i <= job_num; ++i) {
        //     cout << endTime[job_index[i]-1] << "\t" << startTime[job_index[i]-1] << "\t" << pre_job[i] << "\t" << tmp_dp[i] << endl;
        // }
        return tmp_dp.back();
    }
};
// @lc code=end

