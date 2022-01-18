Can Place Flowers - Easy

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
 

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zero_length = 1;
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        vector<int>::iterator flowerbed_iter;
        for(flowerbed_iter = flowerbed.begin(); 
            flowerbed_iter != flowerbed.end(); 
            flowerbed_iter++){
            if(*flowerbed_iter == 0) zero_length++;
            else{
                //int num = zero_length/2;
                //n -= num;
                cout<<zero_length;
                zero_length--;
                n -= zero_length>>1;
                if(n<=0) return true;
                zero_length = 0;
            }
        } 
        
        return n<=0;
    }
};