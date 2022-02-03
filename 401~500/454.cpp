4Sum II - Medium

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> hashmap;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int summ = nums1[i] + nums2[j];
                if(hashmap.find(summ)==hashmap.end()){
                    hashmap.insert(pair<int,int>(summ,1));
                }
                else{
                    hashmap[summ] += 1;
                }
            }
        }
        map<int,int>::iterator iter;
        int ans = 0;
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                int summ = -(nums3[i] + nums4[j]);
                iter = hashmap.find(summ);
                if(iter!=hashmap.end()){
                    ans += iter->second;
                }
            }
        }
        return ans;
        /*
        for(map<int,int>::iterator iter=hashmap.begin();
           iter!=hashmap.end();iter++){
            cout<<(iter->first)<<" "<<(iter->second)<<endl;
        }
        */
    }
};