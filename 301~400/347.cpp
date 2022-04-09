Top K Frequent Elements
Medium


Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> cmap;
        for(int i=0;i<nums.size();i++){
            if(cmap.find(nums[i])==cmap.end()){
                cmap[nums[i]] = 1;
            }
            else
                cmap[nums[i]]++;
        }
        
        auto comp = [&cmap](int n1, int n2) { return cmap[n1] > cmap[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for (pair<int, int> p : cmap) {
            heap.push(p.first);
            if (heap.size() > k) heap.pop();
        }

        vector<int> top(k);
        for (int i = k - 1; i >= 0; i--) {
            top[i] = heap.top();
            heap.pop();
        }
        return top;
    }
};