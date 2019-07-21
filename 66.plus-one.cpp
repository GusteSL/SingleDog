/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        if(digits.empty()) return result;
        int up_digit = 1;
        for(int i = digits.size()-1; i >= 0; --i) {
            result.push_back((digits[i]+up_digit)%10);
            up_digit = (digits[i]+up_digit)/10;
        }
        if(up_digit != 0) {
            result.push_back(up_digit);
        }
        for(int i = 0, j = result.size()-1; i < j; ++i,--j) {
            swap(result[i],result[j]);
        }
        return result;
    }
};

