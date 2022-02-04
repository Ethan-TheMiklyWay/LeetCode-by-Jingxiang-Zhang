Contiguous Array - Medium
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int now = 0;
        int *count = new int[nums.size()];
        for(int i=0;i<nums.size();i++){
            now = now + (nums[i]==0?-1:1);
            count[i] = now;
            // cout<<count[i]<<" "<<i<<endl;
        }
        int *array = new int[nums.size()*2+1];
        for(int i=0;i<nums.size()*2+1;i++)
            array[i] = -2;
        int leng = nums.size();
        int maxlen = 0;
        array[leng] = -1;
        // offset the array, make all of the item is positive value
        for(int i=0;i<nums.size();i++){
            if(array[count[i]+leng]>=-1){
                
                // if exist, do not refrest the position, use the first
                maxlen = maxlen > i - array[count[i]+leng]?
                        maxlen : i - array[count[i]+leng];
            }
            else{  // not exist, add one
                
                array[count[i]+leng] = i;
            }
        }
        
        delete [] count;
        delete [] array;
        return maxlen;
    }
};
