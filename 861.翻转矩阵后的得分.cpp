/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for (int i = 0; i < A.size(); ++i) {
            if (!A[i].empty() && A[i].front() == 0) {
                TransRaw(&A, i);
            }
        }
        for (int i = 0; !A.empty() && i < A.front().size(); ++i) {
            if (2*CountCol(A, i) < A.size()) {
                TransCol(&A, i);
            }
        }
        int result = 0;
        for (const auto& raw : A) {
            result += Num(raw);
        }
        return result;
    }
private:
    int Num(const vector<int> &raw) {
        int num = 0;
        for (const auto &n : raw) {
            num <<= 1;
            num += n;
        }
        return num;
    }
    void TransRaw(vector<vector<int>> *const matrix_p, int i) {
        auto &matrix = *matrix_p;
        if (i < matrix.size()) {
            for (auto& num : matrix[i]) {
                num = 1 - num;
            }
        }
    }
    void TransCol(vector<vector<int>> *const matrix_p, int i) {
        auto &matrix = *matrix_p;
        if (!matrix.empty() && i < matrix.front().size()) {
            for (auto& raw : matrix) {
                raw[i] = 1 - raw[i];
            }
        }
    }
    int CountCol(const vector<vector<int>>& matrix, int i) {
        int result = 0;
        if (!matrix.empty() && i < matrix.front().size()) {
            for (const auto& raw : matrix) {
                result += raw[i];
            }
        }
        return result;
    }
};
// @lc code=end

