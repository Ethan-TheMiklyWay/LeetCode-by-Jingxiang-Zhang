Rotate Array - Medium

Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> num;
        int length = nums.size();
        k = k%length;
        for(int i=-k;i<length-k;i++){
            num.push_back(nums[(i+length)%length]);
        }
        for(int i=0;i<length;i++){
            nums[i] = num[i];
        }
        /*
        k=nums.size()-k%nums.size();
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
        */
    }
};
