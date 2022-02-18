Remove K Digits - Medium

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()<k) 
            return "0";
        if(k==0)
            return num;
        
        stack<char> all_num;
        all_num.push(num[0]);
        for(int i=1;i<num.size();i++){
            
            while(k>0 && !all_num.empty() && num[i]<all_num.top()){
                all_num.pop();
                k--;
            }
            if(all_num.size()==1 && all_num.top()=='0')
                all_num.pop();
            all_num.push(num[i]);
        }
        
        while(k>0 && !all_num.empty()){
            all_num.pop();
            k--;
        }
        string ans;
        while(!all_num.empty()){
            // cout<<all_num.top();
            ans.push_back(all_num.top());
            all_num.pop();
        }
        
        int len = ans.length();
        if(len==0)
            return "0";
        for(int i=0;i<len/2;i++){
            char temp = ans[i];
            ans[i] = ans[len-i-1];
            ans[len-i-1] = temp;
        }
        
        return ans;
    }
};