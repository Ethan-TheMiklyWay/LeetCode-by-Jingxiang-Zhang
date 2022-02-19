Minimize Deviation in Array - Hard

You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
If the element is odd, multiply it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
The deviation of the array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of operations.

 

Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then the deviation will be 3 - 2 = 1.
Example 2:

Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3], then the deviation will be 5 - 2 = 3.
Example 3:

Input: nums = [2,10,8]
Output: 3


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int size = nums.size();
        int max_num = -1000000000, min_num = 1000000000;
        
        for(int i = 0; i<size; ++i) {
            if((nums[i]%2) != 0) // multiplication by 2 if nums[i] is odd
                nums[i] *= 2;   
            // if it is an odd, then it can only multiply once, because
            // after multiply, it become a even.
            max_num = max(max_num,nums[i]);
            min_num = min(min_num,nums[i]);
        }
        
        int min_deviation = max_num - min_num;
        priority_queue<int> pq;
        for(int i = 0; i<size; ++i) {
            pq.push(nums[i]);
        }
        // sort all elements when add its to the queue
        
        while(true) {
            if((pq.top()) % 2 != 0)
                break;
            int top = pq.top();
            pq.pop(); // popped the maximum element
            
            min_deviation = min(min_deviation, top - min_num);
            top /= 2;
            min_num = min(min_num, top);  // updating min
            pq.push(top);    
            // pushing again the top as we have to minimize the max
        }
        min_deviation = min(min_deviation, pq.top() - min_num);
        return min_deviation;
    }
};