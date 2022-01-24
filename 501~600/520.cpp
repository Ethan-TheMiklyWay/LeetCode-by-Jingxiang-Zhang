Detect Capital - Easy

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0]<='z' and word[0]>='a'){
            for(int i = 1 ;i < word.length(); i++)
                if(!(word[i]<='z' and word[i]>='a'))
                    return false;
            return true;
        }
        if(word.length()>=2 and (word[1]<='z' and word[1]>='a')){
            for(int i = 2 ;i < word.length(); i++)
                if(!(word[i]<='z' and word[i]>='a'))
                    return false;
            return true;
        }
        for(int i = 1 ;i < word.length(); i++)
            if(!(word[i]<='Z' and word[i]>='A'))
                return false;
        return true;
    }
};