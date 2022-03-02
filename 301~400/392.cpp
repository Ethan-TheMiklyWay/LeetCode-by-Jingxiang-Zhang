Is Subsequence - Easy

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size())
            return 0;
        if(s.size()==0)
            return 1;
        int j=0;
        char c=s[j];
        for(int i=0;i<t.size();i++){
            if(t[i]==c){
                ++j;
                if(j==s.size())
                    return 1;
                c=s[j];
            }
        } 
        return 0;
    }
};