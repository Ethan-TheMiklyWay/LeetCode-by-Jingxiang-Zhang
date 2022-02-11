Permutation in String - Medium

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) 
            return false;
        int letters[200] = {0};
        for(int i=0;i<s1.size();i++){
            letters[s1[i]]++;
        }
        int letter_num = 0;
        for(int i='a';i<='z';i++){
            if(letters[i]>0){
                letter_num++;
                letters[i]+=1000000;
            }
        }
        for(int i=0;i<s1.size();i++){
            letters[s2[i]]--;
        }
        /*
        for(int i='a';i<='z';i++){
            cout<<char(i)<<": "<<letters[i]<<endl;
        }
        */
        for(int i=s1.size();i<s2.size();i++){            
            int j;
            int temp=0;
            for(int j='a';j<='z';j++){
                if(letters[j]==1000000)
                    temp++;
            }
            if(temp==letter_num) return true;
            letters[s2[i]]--;
            letters[s2[i-s1.size()]]++;
        }
        
        int temp=0;
        for(int j='a';j<='z';j++){
            if(letters[j]==1000000)
                temp++;
            }
        if(temp==letter_num) return true;
        
        return false;
    }
};