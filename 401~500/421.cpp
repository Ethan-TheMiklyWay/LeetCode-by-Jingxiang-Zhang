Maximum XOR of Two Numbers in an Array - Medium

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127


struct treeNode{
    treeNode *left;  // stand for 0
    treeNode *right; // stand for 1
};

class Solution {
public:
    treeNode* root;
    
    void insert(int x){   //to insert each element into the Trie
        treeNode *t = root;
        bitset<32> bs(x);
        for(int j=31; j>=0; j--){
            if(bs[j] == 0){
                if(!t->left){
                    t->left = new treeNode(); 
                }
                t = t->left;
            }
            else{
                if(!t->right){
                    t->right = new treeNode(); 
                }
                t = t->right;
            }
        }    
    }
    
     int maxXOR(int n){
        treeNode *t = root;
        bitset<32> bs(n);
        int ans=0; 
        for(int j=31; j>=0; j--){
            if(bs[j] == 0 && t->right){
                t = t->right;
                ans += (1<<j);
            }
            else if(bs[j] == 1 && t->left){
                t = t->left;
                ans += (1<<j);
            }
            else if(bs[j] == 0 && t->left){
                t = t->left;
            }
            else{
                t = t->right;
            }

        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        root = new treeNode();
        for(int i=0; i<nums.size(); i++)
            insert(nums[i]);
        int max_value = 0;
        for(int i=0; i<nums.size(); i++){
            max_value = max(max_value, maxXOR(nums[i])); 
        }
        return max_value;
        
    }
};