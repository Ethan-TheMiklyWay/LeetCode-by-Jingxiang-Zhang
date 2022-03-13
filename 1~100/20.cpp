Valid Parentheses - Easy



Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

class Solution {
public:
    bool isValid(string s) {
        stack<int> cha;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                cha.push(s[i]);
            }
            else{
                if(cha.empty()){
                    return false;
                }
                
                char c = cha.top();
                cha.pop();
                if((c=='(' and s[i]!=')') or
                   (c=='{' and s[i]!='}') or
                   (c=='[' and s[i]!=']')){
                    return false;
                }
            }
        }
        if(!cha.empty())
            return false;
        return true;
    }
};