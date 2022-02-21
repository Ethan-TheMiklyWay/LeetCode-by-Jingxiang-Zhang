Majority Element - Easy

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        srand( (unsigned)time( NULL ) );
        int result;
        while(true){
            int now = nums[rand()%size];
            int count = 0;
            for(int i=0;i<size;i++){
                if(nums[i] == now)
                    count++;
            }
            if( count>=((size+1)>>1) ){
                result = now;
                break;
            }
        }
        
            
        return result;
    }
};