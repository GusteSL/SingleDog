/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        size_t A_i = 0, B_i = 0;
        int start, end;
        while(A_i < A.size() && B_i < B.size()) {
            start = max(A[A_i][0],B[B_i][0]);
            end = min(A[A_i][1],B[B_i][1]);
            if(start <= end) result.push_back({start, end});
            if(A[A_i][1]<B[B_i][1]) ++A_i;
            else ++B_i;
        }
        return result;
    }
};
// @lc code=end

