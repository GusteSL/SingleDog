/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        vector<string> tokens;
        stack<char> opertors;
        int num_i = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == ' ') {
                s.erase(s.begin()+i);
                --i;
            } else if(s[i] == '(') {
                opertors.push(s[i]);
                num_i = i+1;
            } else if(s[i] == '+' || s[i] == '-') {
                if(!opertors.empty() && opertors.top() != '(') {
                    tokens.push_back( string(1, opertors.top()) );
                    opertors.pop();
                }
                opertors.push(s[i]);
                num_i = i+1;
            } else if(s[i] == ')') {
                while(opertors.top() != '(') {
                    tokens.push_back( string(1, opertors.top()) );
                    opertors.pop();
                }
                opertors.pop();
                num_i = i+1;
            } else {
                if(i+1 >= s.size() || s[i+1] < '0' || s[i+1] > '9') {
                    tokens.push_back(s.substr(num_i, i-num_i+1));
                }
            }
        }
        while(!opertors.empty()) {
            tokens.push_back( string(1, opertors.top()) );
            opertors.pop();
        }
        // for(int i = 0; i < tokens.size(); ++i) {
        //     cout << tokens[i] << ",";
        // }
        stack<int> nums;
        for(int i = 0; i < tokens.size(); ++i) {
            if(tokens[i] == "+") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2+num1);
            } else if(tokens[i] == "-") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2-num1);
            } else {
                nums.push( stoi(tokens[i]) );
            }
        }
        return nums.top();
    }
};
// @lc code=end

