/*
https://leetcode.com/problems/valid-parentheses/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
*/

class Solution {
    //Stack solution, Time Complexity of O(n), Space Complexity of O(n)
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for (char c : s){
            switch(c){
                //If it is open bracket, it will save to the stack for checking the closing bracket
                case '(':
                case '[':
                case '{':
                    stk.push(c);
                    break;
                //If it is close bracket, it will check with the last bracket in stack
                case '}':
                    if (stk.empty() || stk.top() != '{'){
                        return false;
                    }else{
                        stk.pop();
                        break;
                    }
                case ']':
                    if (stk.empty() || stk.top() != '['){
                        return false;
                    }else{
                        stk.pop();
                        break;
                    }
                case ')':
                    if (stk.empty() || stk.top() != '('){
                        return false;
                    }else{
                        stk.pop();
                        break;
                }
            }
        }
        //If stack is not empty, it means that there is extra open bracket
        return stk.empty();
    }
};