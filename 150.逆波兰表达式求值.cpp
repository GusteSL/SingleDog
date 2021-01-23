/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
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
            } else if(tokens[i] == "*") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2*num1);
            } else if(tokens[i] == "/") {
                int num1 = nums.top();
                nums.pop();
                int num2 = nums.top();
                nums.pop();
                nums.push(num2/num1);
            } else {
                nums.push(stoi(tokens[i]));
            }
            // cout << nums.top() << endl;
        }
        return nums.top();
    }
};
// @lc code=end

