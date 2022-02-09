K-diff Pairs in an Array - Medium

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

 

Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.



class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> n;
        n.insert(nums[0]);
        int summ = 0;
        if(k==0){
            set<int> nn;
            for(int i=1;i<nums.size();i++){
                
                int temp = nums[i];
                if(n.find(temp)!=n.end()){
                    if(nn.find(temp)==nn.end()){
                        nn.insert(temp);
                        summ++;
                    }
                }
                n.insert(temp);
            }
            return summ;
        }
        
        
        for(int i=1;i<nums.size();i++){
            int temp = nums[i];
            if(n.find(temp)!=n.end())
                continue;
            if(n.find(temp+k)!=n.end())
                summ++;
            if(n.find(temp-k)!=n.end())
                summ++;
            n.insert(temp);
        }
        return summ;
    }
};