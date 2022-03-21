Partition Labels - Medium

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]



class Solution {
public:
    vector<int> partitionLabels(string s) {
        int part = 0;
        int start[200];
        int end[200];
        vector<int> ans;
        for(int i='a';i<='z';i++){
            start[i] = 10000;
            end[i] = -1;
        }
        for(int i=0;i<s.length();i++){
            start[s[i]] = start[s[i]] < i ? start[s[i]] : i;
            end[s[i]] = end[s[i]] > i ? end[s[i]] : i;
        }
        int loc=0;
        while(loc<s.length()){
            int start_temp = start[s[loc]];
            int end_temp = end[s[loc]];
            int end_a = end_temp;
            do{
                end_temp = end_a;
                for(int i='a';i<='z';i++){
                    if(start[i]>start_temp && start[i]<end_a)
                        end_a = end_a>end[i]?
                                end_a:end[i];
                }
               
            }while(end_a!=end_temp);
            int length = end_a - start_temp + 1;
            ans.push_back(length);
            loc+=length;
        }

        return ans;
    }
};