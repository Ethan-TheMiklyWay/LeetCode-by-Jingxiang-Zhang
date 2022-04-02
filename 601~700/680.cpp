Valid Palindrome II - Easy


Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


class Solution {
public:
    bool palindrom(string &s, int b, int e){
        while(b<e){
            if(s[b]!=s[e])
                return false;
            b++;
            e--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                bool a = palindrom(s,i+1,j);
                bool b = palindrom(s,i,j-1);
                return a||b;
            }
            i++;
            j--;
        }
        return true;
    }
};