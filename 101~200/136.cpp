Single Number - Easy

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> n;
        set<int>::iterator iter;
        for(int i=0;i<nums.size();i++){
            iter = n.find(nums[i]);
            if(iter==n.end()){
                n.insert(nums[i]);
            }
            else{
                n.erase(iter);
            }
            
        }
        return *n.begin();
    }
};