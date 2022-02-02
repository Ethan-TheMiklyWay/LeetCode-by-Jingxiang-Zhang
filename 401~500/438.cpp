Find All Anagrams in a String - Medium

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len[200] = {0};
        int now[200] = {0};

        vector<int> result;
        if(s.length()<p.length()) return result;
        int i;
        for(i=0;i<p.length();i++){
            len[p[i]] += 1;
            now[s[i]] += 1;
        }
        i--;
        now[s[i]] -= 1;
        int length_p = p.length();
        for(;i<s.length();i++){
            now[s[i]] += 1;
            int j;
            for(j='a';j<='z';j++){
                if(now[j]!=len[j]){
                    // cout<<i<<" "<<now[j]<<" "<<len[j]<<endl;
                    break;
                }
            }
            // cout<<int('a')<<endl;
            if(j=='z'+1)
                result.push_back(i-length_p+1);
            
            now[s[i-length_p+1]] -= 1;
        }
        
        /*
        for(int i='a';i<26+'a';i++)
            cout<<char(i)<<":"<<len[i]<<endl;
        */
        return result;
    }
};