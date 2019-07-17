/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        stack<char> c_stack;
        for(int i = 0; i < s.size() && result; ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                c_stack.push(s[i]);
            } else if(s[i] == ')') {
                if(!c_stack.empty() && c_stack.top() == '(') {
                    c_stack.pop();
                } else {
                    result = false;
                }
            } else if(s[i] == ']') {
                if(!c_stack.empty() && c_stack.top() == '[') {
                    c_stack.pop();
                } else {
                    result = false;
                }
            } else if(s[i] == '}') {
                if(!c_stack.empty() && c_stack.top() == '{') {
                    c_stack.pop();
                } else {
                    result = false;
                }
            }
        }
        result = result && c_stack.empty();
        return result;
    }
};

