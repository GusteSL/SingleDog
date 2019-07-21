/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        if(a.empty() && b.empty()) return result;
        else if(!a.empty() && b.empty()) return a;
        else if(a.empty() && !b.empty()) return b;
        else {
            int up_digit = 0;
            while(!a.empty() || !b.empty()) {
                int a_digit = 0;
                int b_digit = 0;
                int sum = 0;
                if(!a.empty()) {
                    a_digit = a.back() == '0' ? 0 : 1;
                    a.pop_back();
                }
                if(!b.empty()) {
                    b_digit = b.back() == '0' ? 0 : 1;
                    b.pop_back();
                }
                sum = a_digit + b_digit + up_digit;
                result += to_string(sum%2);
                up_digit = sum / 2;
            }
            if(up_digit == 1) {
                result += to_string(up_digit);
            }
            for(int i = 0, j = result.size()-1; i < j; ++i,--j) {
                swap(result[i], result[j]);
            }
            return result;
        }
    }
};

