1. Two Sum - Easy

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        int index1;
        int index2;
        vector<int> Sum;
        for(index1 = 0; index1 < nums.size(); index1++){
            for(index2 = index1 + 1; index2 < nums.size(); index2++){
                if(nums[index1] + nums[index2] == target){
                    Sum.push_back(index1);
                    Sum.push_back(index2);
                    return Sum;
                }
            }
        }
        return Sum;
        */
        int index;
        vector<int> Sum;
        map<int, int> store;
        store.insert(pair<int,int>(nums[0],0));
        for(index = 1; index < nums.size(); index++){
            int left = target - nums[index];
            map<int, int>::iterator iter = store.find(left);
            if(iter != store.end()){
                Sum.push_back(iter->second);
                Sum.push_back(index);
            }
            else{
                store.insert(pair<int,int>(nums[index],index));
            }
        }
        return Sum;
    }
};


