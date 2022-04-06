3Sum With Multiplicity - Medium

Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.


class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1000000007;
        int ans = 0;
        sort(arr.begin(),arr.end());
        /*
        for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<endl;
            */
        int size = arr.size();
        for(int i=0;i<arr.size();i++){
            int T = target - arr[i];
            int j = i + 1;
            int k = size - 1;
            while(j<k){
                if(arr[j]+arr[k]<T)
                    j++;
                else if(arr[j]+arr[k]>T)
                    k--;
                else if(arr[j]!=arr[k]){
                    int left = 1, right = 1;
                    while(j+1<k && arr[j+1]==arr[j]){
                        left++;
                        j++;
                    }
                    while(k-1>j && arr[k]==arr[k-1]){
                        right++;
                        k--;
                    }
                    ans += left*right;
                    ans %= mod;
                    j++;
                    k--;
                }
                else{
                    ans += (k-j+1) * (k-j) / 2;
                    ans %= mod;
                    break;
                }
            }
            
        }
        return ans;       
    }
};