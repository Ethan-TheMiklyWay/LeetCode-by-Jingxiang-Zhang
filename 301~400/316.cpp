Remove Duplicate Letters
Medium



Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26,0)  , vis(26,0);
        string res = "";
        int n = s.size();
        for(int i = 0; i<n; ++i)
            cnt[s[i] - 'a']++;
        for(int i = 0; i<n; ++i) {
            // decrease cnt of current character
            cnt[s[i] - 'a']--;
            // If character is not already
            // in answer
            if(!vis[s[i]- 'a']) {
                // Last character > s[i]
                // and its count > 0
                while(res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0) {
                    // marking letter visited
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                
                // Add s[i] in res and
                // mark it visited
                res += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        // return resultant string
        return res;
    }
};