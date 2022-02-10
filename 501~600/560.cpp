Subarray Sum Equals K - Medium

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,vector<int> > record;
        map<int,vector<int> >::iterator iter;
        int current_val = 0;
        for(int i=0;i<nums.size();i++){
            current_val += nums[i];  // CDF in probability
            nums[i] = current_val;
            iter = record.find(current_val);
            if(iter!=record.end()){  // exist such value
                (iter->second).push_back(i);
            }
            else{
                vector<int> tt;
                tt.push_back(i);
                record.insert(pair<int,vector<int> >(current_val,tt));
            }
        }
        
        /*
        for(iter=record.begin();iter!=record.end();iter++){
            cout<<iter->first<<": ";
            vector<int> temp = iter->second;
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }
        */
        vector<int>::iterator iiter = nums.begin();
        nums.insert(iiter,0);
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int temp_val = nums[i] + k;
            iter = record.find(temp_val);
            if(iter!=record.end()){
                vector<int> temp = iter->second;
                for(int j=temp.size()-1;j>=0;j--){
                    if(temp[j]>=i){
                        // cout<<i<<" "<<nums[i]<<" "<<temp[j]<<endl;
                        ans++;
                    }
                    else
                        break;
                }
            }
        }
        return ans;
    }
};