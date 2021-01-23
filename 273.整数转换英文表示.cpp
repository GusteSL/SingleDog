/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string result;
        for(int i = 1000000000, j = 0; j < 4; ++j, i /= 1000) {
            int tmp_num = num / i;
            num %= i;
            // cout << tmp_num << endl;
            if(tmp_num == 0) continue;
            int hun_num = tmp_num/100;
            if( hun_num != 0) {
                if(!result.empty()) result += " ";
                result += (small[hun_num]+" Hundred");
            }
            int dac_num = tmp_num%100;
            if(dac_num != 0 && dac_num < 20) {
                if(!result.empty()) result += " ";
                result += small[dac_num];
            } else {
                if(dac_num/10 != 0) {
                    if(!result.empty()) result += " ";
                    result += decade[dac_num/10];
                }
                if(dac_num%10 != 0) {
                    if(!result.empty()) result += " ";
                    result += small[dac_num%10];
                }
            }
            if(j != 3) result += (" " + big[j]);
        }
        return result;
    }
    string small[20] = {
        "", "One", "Two", "Three", "Four",
        "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    string decade[10] = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };
    string big[4] = {
        "Billion", "Million", "Thousand", ""
    };
};
// @lc code=end

