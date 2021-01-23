/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        float left = 0.0, right = 1.0;
        int p, q;
        float middle = 0.5f*(left + right);
        size_t num = count(A, middle, p, q);
        while(num != K) {
            // cout << num << endl;
            if(num < K) {
                left = middle;
            } else {
                right = middle;
            }
            middle = 0.5f*(left + right);
            num = count(A, middle, p, q);
        }
        return {p ,q};
    }
    size_t count(vector<int>& A, float num, int& p, int& q) {
        size_t result = 0;
        p = A[0];
        q = A.back();
        for(int i = 0; i < A.size(); ++i) {
            for(int j = i+1; j < A.size(); ++j) {
                if(A[i] < A[j]*num) {
                    result += A.size() - j;
                    if(A[i]*q > A[j]*p) {
                        p = A[i];
                        q = A[j];
                    }
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

