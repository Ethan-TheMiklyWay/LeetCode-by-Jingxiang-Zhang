Word Pattern - Easy

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> patt;
        map<char,string>::iterator patt_iter;
        set<string> exist_str;
        int location = 0;
        for(int i = 0;i<pattern.length();i++){
            char c = pattern[i];
            int next_space = s.find(' ',location);
            string next_str;
            if(next_space != string::npos){
                next_str = s.substr(location,next_space-location);
            }
            else{
                next_str = s.substr(location,s.length()-location);
            }
            //cout<<c<<" "<<next_str<<endl;
            location = next_space+1;
            patt_iter = patt.find(c);
            if(patt_iter==patt.end()){
                if(exist_str.find(next_str)!=exist_str.end())
                    return false;
                exist_str.insert(next_str);
                patt.insert(pair<char,string>(c,next_str));
                
            }
            else{
                if(patt_iter->second!=next_str)
                    return false;
            }
        }
        //if location is not 0, then it must not finish reading 
        //string, the number of pattern is not match with S. 
        if(location)
            return false;
        return true;
    }
};
