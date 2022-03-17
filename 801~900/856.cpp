Score of Parentheses
Medium



Example 1:

Input: s = "()"
Output: 1
Example 2:

Input: s = "(())"
Output: 2
Example 3:

Input: s = "()()"
Output: 2
 



class Solution {
public:
    int loc = 0;
    int scoreOfParentheses(string s) {
        int score = get_score(s);
        cout<<loc<<endl;
        while(loc<s.length()){
            score += get_score(s);
        }
        
        return score;
    }
    int get_score(string s){
        if(loc>s.length())
            return 0;
        if(s[loc]=='(' && s[loc+1]==')'){
            loc += 2;
            return 1;
        }
        int score = 0;
        loc += 1;
        score += get_score(s);
        if(s[loc]==')'){
            loc += 1;
            score = score*2;
            // cout<<score;
            return score;
        }
        while(true){
            if(s[loc]=='('){
                score += get_score(s);
            }
            else
                break;
        }
        loc += 1;
        return score*2;
    }
};