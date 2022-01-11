131. Palindrome Partitioning - Medium
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]




class Solution {
public:
    vector<vector<int>> all_seq;
    string line;
    vector<vector<string>> partition(string s) {
        line = s;
        vector<vector<string>> result;
        int length = s.length();
        find_sequence(0, length);
        
        for (vector<vector<int>>::const_iterator iter = all_seq.cbegin();
                 iter != all_seq.cend(); iter++) {
            int current_pos = 0;
            vector<int>::const_iterator itert;
            for(itert = (*iter).cbegin(); itert != (*iter).cend(); itert++) {
                if(!palindrome(current_pos,current_pos+(*itert))){
                    break;
                }
                current_pos += (*itert);
            }
            
            
            current_pos = 0;
            if(itert == (*iter).cend()){
                vector<string> temp;
                for(itert = (*iter).cbegin(); itert != (*iter).cend(); itert++) {
                    temp.push_back(line.substr(current_pos,(*itert)));
                    current_pos += (*itert);
                }
                result.push_back(temp);
            }
            
        }
        return result;
    }
    
    
    bool palindrome(int low, int high){
        high--;
        while (low < high) {
            if (line[low++] != line[high--]) return false;
        }
        return true;
    }
    /*
    map<int,bool> res;
    bool palindrome(int start, int end){
        int hash = end*100 + start;
        map<int,bool>::iterator iter = res.find(hash);
        if(iter != res.end()){
            return iter->second;
        }
        for(int i=start; i<start+((end-start)/2); i++){
            if(line[i] != line[end - i + start - 1]){
                res.insert(pair<int, bool>(hash, 0));
                return false;
            }
        }
        res.insert(pair<int, bool>(hash, 1));
        return true;
    } */
    
    vector<int> current_seq;
    void find_sequence(int current_pos, int length){
        if (current_pos == length){
            vector<int> seq;
            for (vector<int>::const_iterator iter = current_seq.cbegin();
                 iter != current_seq.cend(); iter++) {
                seq.push_back(*iter);
            }
            all_seq.push_back(seq);
            return;
        }
        for(int i = current_pos + 1; i <= length; i++){
            current_seq.push_back(i - current_pos);
            find_sequence(i, length);
            current_seq.pop_back();
        }
    }
};