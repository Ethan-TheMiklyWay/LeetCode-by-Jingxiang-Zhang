Arithmetic Slices - Medium


An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
Example 2:

Input: nums = [1]
Output: 0
 

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
		// if nums size is less than 3 return false
        if(nums.size() < 3)
            return 0;
        
        int cnt = 0, diff;
        
        for(int i = 0; i<nums.size()-2; ++i)
        {
			// storing diff of first 2 elements
            diff = nums[i+1] - nums[i];
			
			// checking for consecutive elements with same difference.
            for(int j = i+2; j<nums.size(); ++j)
            {
				// if we find the same diff of next 2 elements
				// this means we  find consecutive elements
				// increase the Count
                if(nums[j] - nums[j-1] == diff)
                    ++cnt;
                else
				// break as we need to cnt for consecutive diff elements
                    break;
            }
        }
		// return cnt
        return cnt;
    }
    /*
    
    
    
    int ans = 0;
    map<int, bool> exist;
    int numberOfArithmeticSlices(vector<int>& nums) {
        iterate(nums,0,nums.size()-1);
        return ans;
    }
    
    bool iterate(vector<int>& nums,int s,int e){
        int ex = s * 10000 + e;
        auto al = exist.find(ex);
        if(al != exist.end()){
            return al->second;
        }
        
        if(e-s==2){
            if(nums[s+1]*2==nums[s]+nums[e]){
                exist.insert(pair<int, bool>(ex, true));
                ans += 1;
                return true;
            }
            else{
                exist.insert(pair<int, bool>(ex, false));
                return false;
            }
        }
        if(e-s<2)
            return false;
        
        int a = iterate(nums, s+1, e);
        int b = iterate(nums, s, e-1);
        if(a && b){
            exist.insert(pair<int, bool>(ex, true));
            ans += 1;
            return true;
        }
        exist.insert(pair<int, bool>(ex, false));
        return false;
    }
    
    */
};