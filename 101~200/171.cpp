Excel Sheet Column Number - Easy

Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701



class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i=0;i<columnTitle.length();i++){
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        }
        return ans;
    }
};